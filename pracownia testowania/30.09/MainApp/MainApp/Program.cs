namespace MainApp;
using Calculator = BusinessLogic.Calculator;


class Program
{
    static void Main(string[] args)
    {
        int x = 5;
        int y = 10;
        Console.WriteLine(Calculator.Add(x, y));
    }
}