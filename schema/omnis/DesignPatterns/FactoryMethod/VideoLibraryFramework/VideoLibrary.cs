using System;

namespace VideoLibraryFramework
{
    public abstract class VideoLibrary
    {
        public void Buy(Customer customer, Movie movie)
        {
            IPolicy policy = GetPolicy(customer);

            if (!policy.CanBuy(movie))
            {
                Console.WriteLine("{0} is not allowed to buy '{1}'", customer.Name, movie.Name);
                return;
            }

            var price = policy.GetPrice(movie);

            Console.WriteLine("{0} bought {1} at the price of {2}", customer.Name, movie.Name, price);
        }

        public abstract IPolicy GetPolicy(Customer customer);
    }
}
