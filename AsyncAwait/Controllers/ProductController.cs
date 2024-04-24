using AsyncAwait.Services.Interfaces;
using Microsoft.AspNetCore.Mvc;

namespace AsyncAwait.Controllers
{
    [Route("api/[controller]")]
    public class ProductController : ControllerBase
    {
        private readonly IProductService _productService;
        private readonly ILogger<ProductController> _logger;
        public ProductController(IProductService productService, ILogger<ProductController> logger)
        {
            _productService = productService;
            _logger = logger;
        }

        [HttpGet]
        public async Task<IActionResult> GetProducts()
        {
            _logger.LogInformation("thread id 1 = {threadId}", Environment.CurrentManagedThreadId);
            var products = await _productService.GetProductsAsync();
            _logger.LogInformation("thread id 5 = {threadId}", Environment.CurrentManagedThreadId);
            return Ok(products);
        }
    }
}
