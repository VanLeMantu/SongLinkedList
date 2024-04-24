using AsyncAwait.Services.Interfaces;

namespace AsyncAwait.Services.Implementations
{
    public class ProductService : IProductService
    {
        private readonly ILogger<ProductService> _logger;
        public ProductService(ILogger<ProductService> logger) { _logger = logger; }
        public async Task<IEnumerable<int>> GetProductsAsync()
        {
            _logger.LogInformation("thread id 2 = {threadId}", Environment.CurrentManagedThreadId);
            Task.Delay(20000);
            _logger.LogInformation("thread id 3 = {threadId}", Environment.CurrentManagedThreadId);
            await Task.Delay(10000);
            _logger.LogInformation("thread id 4 = {threadId}", Environment.CurrentManagedThreadId);
            return new List<int> { 1, 2, 3, 4, 5 };
        }
    }
}
