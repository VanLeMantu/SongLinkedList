using OverrideNewVirtual;

namespace Delegate
{
    // Khai báo một delegate có chữ ký tương tự như phương thức
    delegate void MyDelegate(string message);

    class Program
    {
        // Phương thức sẽ được tham chiếu bởi delegate
        static void WelcomeMessage(string name)
        {
            Console.WriteLine($"Hello, {name}!");
        }

        static void Main()
        {
        }
    }
}
