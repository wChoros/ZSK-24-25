using System.Runtime.InteropServices;

namespace BusinessLogic.Test;

using Calculator = BusinessLogic.Calculator;

public class TestCalculator
{
    [Theory]
    [InlineData(5, 10, 15)]
    [InlineData(5, -10, -5)]
    [InlineData(-5, 10, 5)]
    [InlineData(-5, -10, -15)]
    public void TestAdd(int x, int y, int expected)
    {
        Assert.Equal(expected, Calculator.Add(x, y));
    }
    
    [Theory]
    [InlineData(Int32.MaxValue, 1)]
    [InlineData(Int32.MinValue, -1)]
    public void TestAddOverflow(int x, int y)
    {
        Assert.Throws<OverflowException>(() => Calculator.Add(x, y));
    }

    [Theory]
    [InlineData(5, 10, -5)]
    [InlineData(5, -10, 15)]
    [InlineData(-5, 10, -15)]
    public void TestSubtract(int x, int y, int expected)
    {
        Assert.Equal(expected, Calculator.Subtract(x, y));
    }
    
    [Theory]
    [InlineData(Int32.MaxValue, -1)]
    [InlineData(Int32.MinValue, 1)]
    public void TestSubtractOverflow(int x, int y)
    {
        Assert.Throws<OverflowException>(() => Calculator.Subtract(x, y));
    }

    [Fact]
    public void TestMultiply()
    {
        int x = 5;
        int y = 10;
        int expected = 50;
        Assert.Equal(expected, Calculator.Multiply(x, y));
    }
    
    [Theory]
    [InlineData(Int32.MaxValue, 2)]
    [InlineData(2, Int32.MaxValue)]
    [InlineData(Int32.MinValue, 2)]
    [InlineData(2, Int32.MinValue)]
    public void TestMultiplyOverflow(int x, int y)
    {
        Assert.Throws<OverflowException>(() => Calculator.Multiply(x, y));
    }

    [Fact]
    public void TestDivide()
    {
        int x = 10;
        int y = 5;
        int expected = 2;
        Assert.Equal(expected, Calculator.Divide(x, y));
    }

    [Fact]
    public void TestDivideByZero()
    {
        int x = 10;
        int y = 0;
        Assert.Throws<DivideByZeroException>(() => Calculator.Divide(x, y));
    }
}