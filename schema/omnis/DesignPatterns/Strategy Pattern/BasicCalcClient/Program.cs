using System;
using BasicCalc;

namespace BasicCalcClient
{
    class Program
    {
        internal class PowerOperation : IBinaryOperation
        {
            public string Name { get { return "**"; } }

            public double Calculate(double first, double second)
            {
                return Math.Pow(first, second);
            }
        }

        static void Main()
        {
            var calculator = new Calculator();
            calculator.BinaryOperators.Add(new PowerOperation());

            Console.WriteLine("Basic Calculator");

            while(true)
            {
                Console.Write(">>> ");
                string line = Console.ReadLine();

                if (line == "exit") return;                    

                try
                {

                    double result = calculator.Calculate(line);
                    Console.WriteLine(result);
                }
                catch (InvalidOperationException)
                {
                    Console.WriteLine("Invalid syntax.");
                }
            }
        }
    }
}
