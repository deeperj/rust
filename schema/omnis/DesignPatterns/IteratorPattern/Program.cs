using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

public static class Enumerable
{
    public static IEnumerable<TSource> Where<TSource>(
        this IEnumerable<TSource> source, Func<TSource, bool> predicate)
    {
        return new WhereEnumerableIterator<TSource>(source, predicate);
    }

    class WhereEnumerableIterator<TSource> : IEnumerable<TSource>, IEnumerator<TSource>
    {
        IEnumerable<TSource> source;
        Func<TSource, bool> predicate;
        IEnumerator<TSource> enumerator;

        public WhereEnumerableIterator(IEnumerable<TSource> source, Func<TSource, bool> predicate)
        {
            this.source = source;
            this.predicate = predicate;
        }

        public override bool MoveNext()
        {
            switch (state)
            {
                case 1:
                    enumerator = source.GetEnumerator();
                    state = 2;
                    goto case 2;
                case 2:
                    while (enumerator.MoveNext())
                    {
                        TSource item = enumerator.Current;
                        if (predicate(item))
                        {
                            current = item;
                            return true;
                        }
                    }
                    Dispose();
                    break;
            }
            return false;
        }
    }

    public static IEnumerable<TResult> Select<TSource, TResult>(
        this IEnumerable<TSource> source, Func<TSource, TResult> selector)
    {
        return new WhereSelectEnumerableIterator<TSource, TResult>(source, null, selector);
    }

    private class WhereSelectEnumerableIterator<TSource, TResult> : IEnumerable<TSource>, IEnumerator<TSource>
    {
        private IEnumerable<TSource> source;
        private Func<TSource, bool> predicate;
        private Func<TSource, TResult> selector;
        private IEnumerator<TSource> enumerator;

        public WhereSelectEnumerableIterator(IEnumerable<TSource> source, Func<TSource, bool> predicate,
                                             Func<TSource, TResult> selector)
        {
            this.source = source;
            this.predicate = predicate;
            this.selector = selector;
        }

        public override bool MoveNext()
        {
            switch (state)
            {
                case 1:
                    enumerator = source.GetEnumerator();
                    state = 2;
                    goto case 2;
                case 2:
                    while (enumerator.MoveNext())
                    {
                        TSource item = enumerator.Current;
                        if (predicate == null || predicate(item))
                        {
                            current = selector(item);
                            return true;
                        }
                    }
                    Dispose();
                    break;
            }
            return false;
        }
    }

}


namespace IteratorPattern
{
    class Program
    {
        static readonly Random Random = new Random();

        const int N = 100;
        const int NumberOfAdds = 100;

        private static void Main()
        {
            //var collection = new List<int> { 1, 2, 4, 8, 16 };

            //using (var enumerator = collection.GetEnumerator())
            //{                
            //    while (enumerator.MoveNext())
            //    {
            //        Console.WriteLine(enumerator.Current);
            //    }
            //}

            //foreach (var n in collection)
            //{
            //    Console.WriteLine(n);
            //}

            var collection = new List<int> { 1, 2, 3, 4, 5 };

            foreach (var n in collection.Where(x => x % 2 == 0).Select(x => x * 2))
            {
                Console.WriteLine(n);                
            }

            //var list = new List<int>();
            //var myList = new MyList(N);

            //for (int i = 0; i < NumberOfAdds; ++i)
            //{
            //    var n = Random.Next(N);

            //    list.Add(n);
            //    myList.Add(n);
            //}

            //Console.WriteLine("List<int>\n");
            //{
            //    int sum = 0;
            //    foreach (var n in list)
            //    {
            //        Console.Write("{0} ", n);
            //        sum += n;
            //    }
            //    Console.WriteLine("\nSum: {0}", sum);
            //}

            //Console.WriteLine("\n\nMyList:\n");
            //{
            //    int sum = 0;
            //    foreach (var n in myList)
            //    {
            //        Console.Write("{0} ", n);
            //        sum += n;
            //    }
            //    Console.WriteLine("\nSum: {0}", sum);
            //}

            Console.ReadKey();
        }
    }
}
