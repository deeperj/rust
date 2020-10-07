using VideoLibraryFramework;

namespace FactoryMethod
{
    public class ChildPolicy : IPolicy
    {
        public bool CanBuy(Movie movie)
        {
            return movie.Category != "Porn" && movie.Category != "Horror";
        }

        public decimal GetPrice(Movie movie)
        {
            return movie.Price / 2;
        }
    }
}