using VideoLibraryFramework;

namespace FactoryMethod
{
    public class MyVideoLibrary : VideoLibrary
    {
        public override IPolicy GetPolicy(Customer customer)
        {
            if (customer.Age < 18)
            {
                return new ChildPolicy();
            }

            return new AdultPolicy();
        }
    }
}