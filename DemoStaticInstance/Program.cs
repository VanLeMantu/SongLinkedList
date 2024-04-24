namespace DemoStaticInstance
{
    public class Counter
    {
        // Static member to keep track of the total count across all instances
        private static int totalCount;

        // Instance member to store the count for each instance
        private int count;

        // Static constructor to initialize static members
        static Counter()
        {
            totalCount = 0;
        }

        // Instance constructor to initialize instance members
        public Counter()
        {
            count = 0;
        }

        // Method to increment count for an instance
        public void Increment()
        {
            count++;
            totalCount++;
        }

        // Method to get the count for an instance
        public int GetCount()
        {
            return count;
        }

        // Static method to get the total count across all instances
        public static int GetTotalCount()
        {
            return totalCount;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Creating instances of Counter class
            Counter counter1 = new Counter();
            Counter counter2 = new Counter();

            // Incrementing count for counter1
            counter1.Increment();
            counter1.Increment();
            counter1.Increment();

            // Incrementing count for counter2
            counter2.Increment();
            counter2.Increment();

            // Displaying count for each instance
            Console.WriteLine("Count for counter1: " + counter1.GetCount()); // Output: 3
            Console.WriteLine("Count for counter2: " + counter2.GetCount()); // Output: 2

            // Displaying total count across all instances
            Console.WriteLine("Total count: " + Counter.GetTotalCount()); // Output: 5
        }
    }
}