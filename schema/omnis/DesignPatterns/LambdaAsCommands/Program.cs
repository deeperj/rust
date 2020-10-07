using System;
using System.Collections.Generic;
using System.Linq;

namespace LambdaAsCommands
{
    public interface PredicateCommand<in T, out TResult>
    {
        TResult Predicate(T element);
    }

    public class CitiesThatStartWith : PredicateCommand<string, bool>
    {
        private readonly string initials;

        public CitiesThatStartWith(string initials)
        {
            this.initials = initials;
        }

        public bool Predicate(string city)
        {
            return city.StartsWith(initials);
        }
    }

    static class Extensions
    {
        public static IEnumerable<TSource> Where<TSource>(
            this IEnumerable<TSource> source, 
            PredicateCommand<string, bool> predicate)
        {
            var result = new List<TSource>();

            foreach (var element in source)
                if (predicate(element))
                    result.Add(element);

            return result;
        }
    }

    class Program
    {
        static void Main()
        {
            var cities = new List<string> { "London", "Florence", "Milan", "Cambridge", "Cambourne" };

            var result = cities.Where(n => n.StartsWith("C"));

            var result = cities.Where(new CitiesThatStartWith("C"));
            
            foreach (var city in result)
            {
                Console.WriteLine(city);
            }

            Console.ReadKey();
        }
    }
}
