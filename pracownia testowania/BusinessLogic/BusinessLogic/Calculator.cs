namespace BusinessLogic;

public class Calculator
{
    public static int Add(int a, int b)
    {
        checked
        {
            return a + b;
        }
    }

    public static int Subtract(int a, int b)
    {
        checked
        {
            return a - b;
        }
    }

    public static int Multiply(int a, int b)
    {
        int value = 0;
        short sign = 1;

        if (a < 0 ^ b < 0)
        {
            sign = -1;
        }

        a = int.Abs(a);
        b = int.Abs(b);

        for (int i = 0; i < b; i++)
        {
            checked
            {
                value += a;
            }
        }

        return value * sign;
    }

    public static float Divide(int a, int b)
    {
        if (b == 0)
        {
            throw new DivideByZeroException();
        }

        int value = 0;
        short sign = 1;

        if (a < 0 ^ b < 0)
        {
            sign = -1;
        }

        a = Math.Abs(a);
        b = Math.Abs(b);

        while (a >= b)
        {
            a -= b;
            value++;
        }

        return value * sign;
    }
}