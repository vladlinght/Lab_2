using System;

class Rectangle
{
    private double side1;
    private double side2;

    public Rectangle(double side1, double side2)
    {
        this.side1 = side1;
        this.side2 = side2;
    }

    public double CalculateArea()
    {
        return side1 * side2;
    }

    public double CalculatePerimeter()
    {
        return 2 * (side1 + side2);
    }

    public double Area
    {
        get { return CalculateArea(); }
    }

    public double Perimeter
    {
        get { return CalculatePerimeter(); }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Введіть довжину першої сторони прямокутника:");
        double side1 = double.Parse(Console.ReadLine());

        Console.WriteLine("Введіть довжину другої сторони прямокутника:");
        double side2 = double.Parse(Console.ReadLine());

        Rectangle rectangle = new Rectangle(side1, side2);

        double area = rectangle.Area;
        double perimeter = rectangle.Perimeter;

        Console.WriteLine($"Площа прямокутника: {area}");
        Console.WriteLine($"Периметр прямокутника: {perimeter}");

        Console.ReadLine();
    }
}
