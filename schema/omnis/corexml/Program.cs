using System;

namespace corexml
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlDocument document = new XmlDocument();
            document.Load("test.xml");

            XmlNamespaceManager m = new XmlNamespaceManager(document.NameTable);
            m.AddNamespace("ns", "http://www.dotnetcoretutorials.com/namespace");
            Console.WriteLine(document.SelectSingleNode("ns:MyDocument/ns:MyProperty", m).InnerText);
        }
    }
}
