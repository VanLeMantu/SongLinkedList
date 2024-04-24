using System;

record Person(string Name, int Age);

class Program
{
    static void Main()
    {
        // Tạo một record Person và gán vào hai biến tham chiếu
        var person1 = new Person("Alice", 30);
        var person2 = person1;

        // In thông tin của person1 và person2
        Console.WriteLine("Thông tin ban đầu:");
        Console.WriteLine($"person1: {person1.Name}, {person1.Age}");
        Console.WriteLine($"person2: {person2.Name}, {person2.Age}");

        if (ReferenceEquals(person1, person2))
            Console.WriteLine("person1 và person2 cùng trỏ đến một đối tượng.");
        else { Console.WriteLine("person1 và person2 không trỏ đến một đối tượng.");}

        // Thay đổi thông tin của person1
        person1 = person1 with { Age = 31 };

        // In thông tin của person1 và person2 sau khi thay đổi
        Console.WriteLine("\nThông tin sau khi thay đổi:");
        Console.WriteLine($"person1: {person1.Name}, {person1.Age}");
        Console.WriteLine($"person2: {person2.Name}, {person2.Age}");

        if (ReferenceEquals(person1, person2))
            Console.WriteLine("person1 và person2 cùng trỏ đến một đối tượng.");
        else { Console.WriteLine("person1 và person2 không trỏ đến một đối tượng."); }
    }
}
