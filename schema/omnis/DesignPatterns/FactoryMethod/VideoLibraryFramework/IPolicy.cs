namespace VideoLibraryFramework
{
    public interface IPolicy
    {
        bool CanBuy(Movie movie);
        decimal GetPrice(Movie movie);
    }
}