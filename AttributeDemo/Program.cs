using AttributeDemo;

var attributes = Attribute.GetCustomAttributes(typeof(Person));
var authorAttribute = attributes.OfType<AuthorAttribute>().Single();
Console.WriteLine(authorAttribute.GetName());
Console.ReadLine();