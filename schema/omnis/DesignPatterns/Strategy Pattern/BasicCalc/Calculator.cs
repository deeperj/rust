
using System;

namespace BasicCalc
{
    public class Calculator
    {
        public double Calculate(string line)
        {
            var elemens = line.Split();

            if (elemens.Length == 2)
            {
                var operation = elemens[0];
                var first = double.Parse(elemens[1]);

                switch (operation)
                {
                    case "sin": return Math.Sin(first);
                    case "cos": return Math.Cos(first);
                }
            }           
            else if (elemens.Length == 3)
            {
                var first = double.Parse(elemens[0]);
                var operation = elemens[1];
                var second = double.Parse(elemens[2]);

                switch (operation)
                {
                    case "+": return first + second;
                    case "-": return first - second;
                }
            }

            throw new InvalidOperationException();
        }
    }
}
