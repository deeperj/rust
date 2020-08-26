using System;
using System.Collections.Generic;
using System.Linq;

namespace BasicCalc
{
    public class Calculator
    {
        public List<IUnaryOperation> UnaryOperators { get; set; }
        public List<IBinaryOperation> BinaryOperators { get; set; }

        public Calculator()
        {
            UnaryOperators = new List<IUnaryOperation> { new SinOperation(), new CosOperation() };
            BinaryOperators = new List<IBinaryOperation> { new SumOperation(), new DiffOperation() };
        }

        public double Calculate(string line)
        {
            var elemens = line.Split();

            if (elemens.Length == 2)
            {
                var operation = elemens[0];
                var first = double.Parse(elemens[1]);

                foreach (var unaryOperator in UnaryOperators.Where(x => x.Name == operation))
                {
                    return unaryOperator.Calculate(first);
                }
            }
            else if (elemens.Length == 3)
            {
                var first = double.Parse(elemens[0]);
                var operation = elemens[1];
                var second = double.Parse(elemens[2]);

                foreach (var binaryOperator in BinaryOperators.Where(x => x.Name == operation))
                {
                    return binaryOperator.Calculate(first, second);
                }
            }

            throw new InvalidOperationException();
        }
    }
}
