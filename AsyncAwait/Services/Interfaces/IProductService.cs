namespace AsyncAwait.Services.Interfaces
{
    public interface IProductService
    {
        Task<IEnumerable<int>> GetProductsAsync();
    }
}
