using System;

public class Fahrenheit
{
    public double Degrees { get; set; }

    public Fahrenheit(double degrees)
    {
        Degrees = degrees;
    }

    public static implicit operator double(Fahrenheit f)
    {
        return f.Degrees;
    }

    public static explicit operator Fahrenheit(double d)
    {
        return new Fahrenheit(d);
    }
}

public class Program
{
    public static void Main()
    {
        Fahrenheit f = new Fahrenheit(100);
        Console.WriteLine("Fahrenheit: " + f.Degrees + " degrees");
        double temp = f;
        Console.WriteLine("After implicit conversion: " + temp + " degrees");
        Fahrenheit f2 = (Fahrenheit)temp;
        Console.WriteLine("After explicit conversion: " + f2.Degrees + " degrees");
    }
}