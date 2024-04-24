using DependencyInjection.Models;

namespace DependencyInjection.Services.Interfaces
{
    public interface IProductService
    {
        Task<int> GetProducts();
    }
}
