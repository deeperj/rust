
using System;
using System.Threading;

namespace ObserverPattern
{
    public class NumberGenerator
    {
        public delegate void NewNumberHandler(int number);
        public event NewNumberHandler NewNumber;

        public void Run()
        {
            var random = new Random();

            for (int i = 0; i < 10; ++i )
            {
                Thread.Sleep(1);
                var number = random.Next();

                if (NewNumber != null)
                {
                    NewNumber.Invoke(number);
                }
            }
        }
    }
}
