using DependencyInjection.Services.Interfaces;

namespace DependencyInjection.Services.Implementations
{
    public class ProductService(IOrderService orderService) : IProductService
    {
        private readonly IOrderService _orderService = orderService;

        public Task<int> GetProducts()
        {
            var result = _orderService.GetOrders();
            return result;
        }
    }
}
