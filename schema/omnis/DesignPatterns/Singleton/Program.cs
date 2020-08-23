using System;

namespace Singleton
{
    public static class StaticLogger
    {
        public static void Log(string message)
        {
            Console.WriteLine(message);
        }
    }

    public sealed class Logger
    {
        public static readonly Logger Instance = new Logger();

        private Logger() { }

        public void Log(string message)
        {
            Console.WriteLine(message);
        }
    }

    public class Client
    {
        public void Run()
        {
            Logger.Instance.Log("Start");
            
            // Execute an operation

            Logger.Instance.Log("Stop");
        }
    }

    class Program
    {
        static void Main()
        {
            new Client().Run();

            Console.ReadKey();
        }
    }
}
