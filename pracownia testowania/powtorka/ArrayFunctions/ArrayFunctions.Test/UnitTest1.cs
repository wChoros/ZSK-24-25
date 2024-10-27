namespace ArrayFunctions.Test;

using ArrayFunctions = ArrayFunctions;

public class TestArrayFunctions
{
    [Theory]
    [InlineData(new int[] { 10, 20, 30, 40, 50 }, new int[] { 50, 40, 30, 20, 10 })]
    [InlineData(new int[] { 1, 2, 3, 4, 5 }, new int[] { 5, 4, 3, 2, 1 })]
    [InlineData(new int[] { 1, 2, 3, 4, 5, 6 }, new int[] { 6, 5, 4, 3, 2, 1 })]
    public void TestReverseArray(int[] arr, int[] expectedResult)
    {
        int[] reversedArray = ArrayFunctions.ReverseArray(arr);
        Assert.Equal(expectedResult, reversedArray);
    }

    [Theory]
    [InlineData(new int[] { 5, 3, 4, 1, 2 }, new int[] { 1, 2, 3, 4, 5 })]
    [InlineData(new int[] { 1, 2, 3, 4, 5 }, new int[] { 1, 2, 3, 4, 5 })]
    [InlineData(new int[] { 5, 4, 3, 2, 1 }, new int[] { 1, 2, 3, 4, 5 })]
    public void TestSortArray(int[] arr, int[] expectedResult)
    {
        int[] sortedArray = ArrayFunctions.SortArray(arr);
        Assert.Equal(expectedResult, sortedArray);
    }

    [Theory]
    [InlineData(new int[] { 1, 2, 3, 4, 5 }, 2, new int[] { 4, 5, 1, 2, 3 })]
    [InlineData(new int[] { 1, 2, 3, 4, 5 }, 3, new int[] { 3, 4, 5, 1, 2 })]
    [InlineData(new int[] { 1, 2, 3, 4, 5 }, 4, new int[] { 2, 3, 4, 5, 1 })]
    public void TestRotateArray(int[] arr, int n, int[] expectedResult)
    {
        int[] rotatedArray = ArrayFunctions.RotateArray(arr, n);
        Assert.Equal(expectedResult, rotatedArray);
    }

    [Theory]
    [InlineData(new int[] { 5, 3, 4, 1, 2 }, 5)]
    [InlineData(new int[] { 1, 2, 3, 4, 5 }, 5)]
    [InlineData(new int[] { 5, 4, 3, 2, 1 }, 5)]
    public void TestFindMax(int[] arr, int expectedResult)
    {
        int max = ArrayFunctions.FindMax(arr);
        Assert.Equal(expectedResult, max);
    }

    [Fact]
    public void TestFindMaxEmptyArray()
    {
        int[] arr = { };
        Assert.Throws<ArgumentException>(() => ArrayFunctions.FindMax(arr));
    }
}