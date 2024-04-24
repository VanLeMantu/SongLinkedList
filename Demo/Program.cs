using System;

class Program
{
    static void Main(string[] args)
    {
        int initialValue = 10;
        int initialValue2 = 20;

        RefMethod(ref initialValue, ref initialValue2);
        Console.WriteLine("Value after RefMethod: " + initialValue);
        Console.WriteLine("Value after RefMethod2: " + initialValue2);
        int outResult;
        OutMethod(out outResult, out int res2, out int res3);
        Console.WriteLine("Value after OutMethod: " + outResult);
        Console.WriteLine("Value after OutMethod2: " + res2);
        Console.WriteLine("Value after OutMethod3: " + res3);
    }

    static void RefMethod(ref int num, ref int num2)
    {
        num += 10;
        num2 += 20;
    }

    static void OutMethod(out int num, out int num2, out int num3)
    {
        num = 0;
        num += 10;
        num2= 20;
        num3 = 30;
    }
}
