namespace ArrayFunctions;

public static class ArrayFunctions
{
    public static int[] ReverseArray(int[] arr)
    {
        int[] reversedArray = new int[arr.Length];
        for (int i = 0; i < arr.Length; i++)
        {
            reversedArray[i] = arr[arr.Length - 1 - i];
        }
        return reversedArray;
    }

    public static int[] SortArray(int[] arr)
    {
        int[] sortedArray = new int[arr.Length];
        Array.Copy(arr, sortedArray, arr.Length);
        Array.Sort(sortedArray);
        return sortedArray;
    }

    public static int[] RotateArray(int[] arr, int n)
    {
        int[] rotatedArray = new int[arr.Length];
        for (int i = 0; i < arr.Length; i++)
        {
            rotatedArray[(i + n) % arr.Length] = arr[i];
        }
        return rotatedArray;
    }
    public static int FindMax(int[] arr)
    {
        if (arr.Length == 0)
        {
            throw new ArgumentException("Array is empty");
        }
        int max = arr[0];
        for (int i = 1; i < arr.Length; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
}