using VideoLibraryFramework;

namespace FactoryMethod
{
    public class AdultPolicy : IPolicy
    {
        public bool CanBuy(Movie movie)
        {
            return true;
        }

        public decimal GetPrice(Movie movie)
        {
            return movie.Price;
        }
    }
}