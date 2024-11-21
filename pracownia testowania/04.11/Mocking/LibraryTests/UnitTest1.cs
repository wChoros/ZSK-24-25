namespace LibraryTests;

public class MathTests
{
    [Fact]
    public void TestSqrt()
    {
        Assert.Equal(2, Math.Sqrt(4));
    }
}