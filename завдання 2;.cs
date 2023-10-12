using System;

class Point
{
    private double x;
    private double y;
    private string name;

    public Point(double x, double y, string name)
    {
        this.x = x;
        this.y = y;
        this.name = name;
    }

    public double X
    {
        get { return x; }
    }

    public double Y
    {
        get { return y; }
    }

    public string Name
    {
        get { return name; }
    }
}

class Figure
{
    private Point[] points;

    public Figure(Point point1, Point point2, Point point3)
    {
        points = new Point[] { point1, point2, point3 };
    }

    public Figure(Point point1, Point point2, Point point3, Point point4)
    {
        points = new Point[] { point1, point2, point3, point4 };
    }

    public Figure(Point point1, Point point2, Point point3, Point point4, Point point5)
    {
        points = new Point[] { point1, point2, point3, point4, point5 };
    }

    public double GetSideLength(Point A, Point B)
    {
        double sideLength = Math.Sqrt(Math.Pow(B.X - A.X, 2) + Math.Pow(B.Y - A.Y, 2));
        return sideLength;
    }

    public void CalculatePerimeter()
    {
        double perimeter = 0;
        for (int i = 0; i < points.Length; i++)
        {
            int nextIndex = (i + 1) % points.Length; // Остання точка з'єднуємо з першою
            perimeter += GetSideLength(points[i], points[nextIndex]);
        }
        Console.WriteLine($"Назва багатокутника: {points.Length}-кут");
        Console.WriteLine($"Периметр багатокутника: {perimeter}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Point A = new Point(0, 0, "A");
        Point B = new Point(0, 4, "B");
        Point C = new Point(3, 0, "C");

        Figure triangle = new Figure(A, B, C);
        triangle.CalculatePerimeter();

        Console.ReadLine();
    }
}
