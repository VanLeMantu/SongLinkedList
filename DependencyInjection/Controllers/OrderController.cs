using DependencyInjection.Services.Interfaces;
using Microsoft.AspNetCore.Mvc;

namespace DependencyInjection.Controllers
{
    [Route("api/[controller]")]
    public class OrderController(IProductService productService, ITransientService transientService) : ControllerBase
    {
        private readonly IProductService _productService = productService;
        private readonly ITransientService _transientService = transientService;

        [HttpGet]
        public async Task<IActionResult> GetOrders()
        {
            //var order1 = await _orderService.GetOrders();
            var order2 = await _productService.GetProducts();
            //if (order2 == order1)
            //{
            //    return Ok("cung instance");
            //}
            return Ok(order2);
        }

        [HttpGet("abc")]
        public async Task<IActionResult> GetAbc()
        {
            List<string> results = new();
            for (int i = 0; i < 3; i++)
            {
                var transientService = _transientService.GetMessage();
                results.Add(transientService);
            }
            return Ok(results);
        }
    }
}
