namespace AttributeDemo
{
    [AttributeUsage(AttributeTargets.Class)]
    public class AuthorAttribute(string name) : Attribute
    {
        private readonly string _name = name;
        public string GetName() => _name;
    }
}
