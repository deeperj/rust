using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Facade
{
    public class Program
    {
        static void Main()
        {
            //StaticFacade();

            var client = new WebClient();
            var content = client.DownloadString("http://www.google.com");

            Console.WriteLine(content);

            Console.ReadKey();
        }

        private static void StaticFacade()
        {
            byte[] bytes = File.ReadAllBytes("file.txt");

            foreach (var b in bytes)
            {
                Console.Write(b.ToString("X"));
            }
        }

        public static byte[] ReadAllBytes(String path)
        {
            byte[] bytes;

            using (var fs = new FileStream(path, FileMode.Open, 
                                           FileAccess.Read, FileShare.Read))
            {
                int index = 0;
                int count = (int)fs.Length;
                bytes = new byte[count];

                while (count > 0)
                {
                    int bytesRead = fs.Read(bytes, index, count);
                    if (bytesRead == 0)
                    {
                        throw new EndOfStreamException();
                    }

                    index += bytesRead;
                    count -= bytesRead;
                }
            }

            return bytes;
        } 
    }
}
