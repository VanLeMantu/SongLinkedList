using DependencyInjection.Models;

namespace DependencyInjection.Services.Interfaces
{
    public interface IOrderService
    {
        Task<int> GetOrders();
    }
}
