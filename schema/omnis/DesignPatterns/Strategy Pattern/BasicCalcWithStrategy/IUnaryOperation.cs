using System;

namespace BasicCalc
{
    public interface IUnaryOperation : IOperation
    {
        double Calculate(double first);
    }

    internal class SinOperation : IUnaryOperation
    {
        public string Name
        {
            get { return "sin"; }
        }

        public double Calculate(double first)
        {
            return Math.Sin(first);
        }
    }

    internal class CosOperation : IUnaryOperation
    {
        public string Name
        {
            get { return "cos"; }
        }

        public double Calculate(double first)
        {
            return Math.Cos(first);
        }
    }

}