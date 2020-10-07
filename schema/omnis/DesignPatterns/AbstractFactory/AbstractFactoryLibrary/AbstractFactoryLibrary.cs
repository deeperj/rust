using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace SecurityLibrary
{
    public abstract class AbstractSecurityFactory
    {
        public abstract ISigner GetSigner();
        public abstract ICypher GetCypher();
    }

    public interface ISigner
    {
        string Sign(string value);
        bool VerifySignature(string value, string signature);
    }

    public interface ICypher
    {
        string Cypher(string value);
        string DeCypher(string value);
    }
    
    internal abstract class AbstractSigner : ISigner
    {
        public abstract string Sign(string value);

        public bool VerifySignature(string value, string signature)
        {
            return signature == Sign(value);
        }
    }

    // NO SECURITY FAMILY

    internal class NullSigner : AbstractSigner
    {
        public override string Sign(string value)
        {
            return value;
        }
    }

    internal class NullCypher : ICypher
    {
        public string Cypher(string value)
        {
            return value;
        }

        public string DeCypher(string value)
        {
            return value;
        }
    }

    public class NoSecurityFactory : AbstractSecurityFactory
    {
        public override ISigner GetSigner()
        {
            return new NullSigner();
        }

        public override ICypher GetCypher()
        {
            return new NullCypher();
        }
    }

    // NORMAL SECURITY FAMILY

    internal class Hash256Signer : AbstractSigner
    {
        public override string Sign(string value)
        {
            var hash = SHA256.Create().ComputeHash(Encoding.ASCII.GetBytes(value));

            var sb = new StringBuilder();

            foreach (var b in hash)
            {
                sb.Append(b.ToString("x2"));
            }

            return sb.ToString();
        }
    }

    internal class DESCypher : ICypher
    {
        public byte[] Key { get; private set; }
        public byte[] IV { get; private set; }

        public DESCypher()
        {
            using (var provider = new DESCryptoServiceProvider())
            {
                Key = provider.Key;
                IV = provider.IV;
            }
        }

        public string Cypher(string value)
        {
            using (var provider = new DESCryptoServiceProvider())
            {
                ICryptoTransform encryptor = provider.CreateEncryptor(Key, IV);

                using (var ms = new MemoryStream())
                {
                    using (var cs = new CryptoStream(ms, encryptor, CryptoStreamMode.Write))
                    using (var sw = new StreamWriter(cs))
                    {
                        sw.Write(value);
                    }

                    return Convert.ToBase64String(ms.ToArray());
                }
            }
        }

        public string DeCypher(string value)
        {
            using (var provider = new DESCryptoServiceProvider())
            {
                ICryptoTransform decryptor = provider.CreateDecryptor(Key, IV);

                using (var ms = new MemoryStream(Convert.FromBase64String(value)))
                using (var cs = new CryptoStream(ms, decryptor, CryptoStreamMode.Read))
                using (var sr = new StreamReader(cs))
                {
                    return sr.ReadToEnd();
                }
            }
        }
    }

    public class NormalSecurityFactory : AbstractSecurityFactory
    {
        public override ISigner GetSigner()
        {
            return new Hash256Signer();
        }

        public override ICypher GetCypher()
        {
            return new DESCypher();
        }
    }

}
