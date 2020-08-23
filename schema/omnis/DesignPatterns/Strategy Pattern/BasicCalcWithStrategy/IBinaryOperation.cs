namespace BasicCalc
{
    public interface IBinaryOperation : IOperation
    {
        double Calculate(double first, double second);
    }

    internal class SumOperation : IBinaryOperation
    {
        public string Name
        {
            get { return "+"; }
        }

        public double Calculate(double first, double second)
        {
            return first + second;
        }
    }

    internal class DiffOperation : IBinaryOperation
    {
        public string Name
        {
            get { return "-"; }
        }

        public double Calculate(double first, double second)
        {
            return first - second;
        }
    }

}