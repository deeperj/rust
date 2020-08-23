using System;
using System.Collections.Generic;
using VideoLibraryFramework;

namespace FactoryMethod
{
    class Program
    {
        static void Main()
        {
            VideoLibrary videoLibrary = new MyVideoLibrary();

            var customers = new List<Customer>
                {
                    new Customer { Name = "Andrea", Age = 28 }, // Adult
                    new Customer { Name = "Luca", Age = 17 }    // Child
                };

            var movies = new List<Movie>
                {
                    new Movie { Name = "The Ring", Category = "Horror", Price = 12 },
                    new Movie { Name = "Finding Nemo", Category = "Animation", Price = 10 }
                };

            foreach (var customer in customers)
            {
                foreach (var movie in movies)
                {
                    videoLibrary.Buy(customer, movie);
                }
            }

            Console.ReadKey();
        }
    }
}
