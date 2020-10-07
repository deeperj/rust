
using System;
using System.Collections.Generic;
using System.Threading;

namespace ObserverPattern
{
    public class NumberGenerator2
    {
        public List<Action<int>> Observers = new List<Action<int>>();

        public void Run()
        {
            var random = new Random();

            for (int i = 0; i < 10; ++i )
            {
                Thread.Sleep(1);

                var number = random.Next();

                Observers.ForEach(x => x(number));
            }
        }
    }
}
