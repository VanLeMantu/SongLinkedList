using DependencyInjection.Services.Interfaces;

namespace DependencyInjection.Services.Implementations
{
    public class OrderService : IOrderService
    {
        private int randomNumber;
        public OrderService()
        {
            randomNumber = 0;
        }
        public Task<int> GetOrders()
        {
            if (randomNumber == 0)
            {
                randomNumber = GetRandomNumber();
            }
            return Task.FromResult(randomNumber);
        }

        private static int GetRandomNumber()
        {
            Random random = new();

            int randomNumber = random.Next(1, 101);

            return randomNumber;
        }
    }
}
