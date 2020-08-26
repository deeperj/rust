
using System;

namespace ObserverPattern
{
    public class Program
    {
        public static void Main()
        {
            var numberGenerator2 = new NumberGenerator2();
            numberGenerator2.Observers.Add(Observer1);
            numberGenerator2.Observers.Add(Observer2);

            numberGenerator2.Run();

            Console.ReadKey();
        }

        //public static void Main()
        //{
        //    var numberGenerator = new NumberGenerator();
        //    numberGenerator.NewNumber += Observer1;
        //    numberGenerator.NewNumber += Observer2;

        //    numberGenerator.Run();

        //    Console.ReadKey();
        //}

        private static void Observer1(int number)
        {
            Console.WriteLine("Observer1: The number is {0}", number);
        }

        private static void Observer2(int number)
        {
            Console.WriteLine("Observer2: The number is {0}", number);
        }
    }
}
