using System;
using System.Text.RegularExpressions;

namespace RegExApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "Hello   World   ";
            string pattern = @"\s+";
            string replacement = " ";
            Regex rgx = new(pattern);
            string result = rgx.Replace(input, replacement);
            Console.WriteLine($"Original String: {input}");
            Console.WriteLine($"Replacement String: {result}");
            Console.ReadKey();
        }
    }
}
