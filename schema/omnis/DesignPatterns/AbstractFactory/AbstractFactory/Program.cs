using System;
using SecurityLibrary;

namespace AbstractFactory
{
    public class Client
    {
        private readonly ISigner signer;
        private readonly ICypher cypher;

        public Client(AbstractSecurityFactory securityFactory)
        {
            signer = securityFactory.GetSigner();
            cypher = securityFactory.GetCypher();            
        }

        public void Execute(string message)
        {
            // Send the message
            var cypherMessage = cypher.Cypher(message);
            var signature = signer.Sign(cypherMessage);

            Console.WriteLine("Sending...");
            Console.WriteLine("CypherMessage: {0}", cypherMessage);
            Console.WriteLine("Signature: {0}", signature);

            // Receive the message
            Console.WriteLine("\nReceiving...");

            if (signer.VerifySignature(cypherMessage, signature))
            {
                var receivedMessage = cypher.DeCypher(cypherMessage);

                Console.WriteLine("Received message: {0}", receivedMessage);
            }
            else
            {
                Console.WriteLine("Transmission error");
            }
        }
    }

    class Program
    {
        static void Main()
        {
            AbstractSecurityFactory securityFactory = GetSecurityFactoryFromConfiguration();

            var client = new Client(securityFactory);
            client.Execute("This is a message.");

            Console.ReadKey();
        }

        static AbstractSecurityFactory GetSecurityFactoryFromConfiguration()
        {
            // Create the concrete factory based on configuration
            return new NoSecurityFactory();
        }
    }
}
