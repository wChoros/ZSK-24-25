namespace Library;

public class Math
{
    public static double Sqrt(int x)
    {
        if (x < 0)
        {
            throw new System.ArgumentException("Cannot take square root of negative number");
        }
        // Newton's method
        double guess = x / 2.0;
        double lastGuess = 0;
        while (guess != lastGuess)
        {
            lastGuess = guess;
            guess = (guess + x / guess) / 2;
        }
        return guess;
    }
}