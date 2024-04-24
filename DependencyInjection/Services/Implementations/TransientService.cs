using DependencyInjection.Services.Interfaces;

namespace DependencyInjection.Services.Implementations
{
    public class TransientService : ITransientService
    {
        private static int _counter = 0;
        private readonly int _instanceNumber;

        public TransientService()
        {
            _counter++;
            _instanceNumber = _counter;
        }

        public string GetMessage()
        {
            return $"This is transient service instance {_instanceNumber}";
        }
    }
}
