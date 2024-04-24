namespace OverrideNewVirtual 
{
    public abstract class BaseClass
    {
        internal abstract void Method();
        public virtual void Method2()
        {
            Console.WriteLine("BaseClass Method2");
        }
    }

    public class DerivedClass : BaseClass
    {
        internal override void Method()
        {
            Console.WriteLine("DerivedClass Method");
        }
        public override void Method2()
        {
            base.Method2();
        }
    }

    //class AnotherDerivedClass : BaseClass
    //{
    //    private readonly string name = "abc";
    //    public AnotherDerivedClass()
    //    {
    //        name = "def";
    //    }
    //    public override void Method()
    //    {
    //        Console.WriteLine("foiasdjfnoisadnjf foasndjfasdnkjviv sadf");
    //    }
    //}

    interface IInterface
    {
        void Method()
        {
            Console.WriteLine("method fdsaf asd");
        }
    }
    public class MyClass : IInterface
    {
    }

    class Program
    {
        static void Main(string[] args)
        {
            BaseClass a = new DerivedClass();
            a.Method();
        }
    }
}