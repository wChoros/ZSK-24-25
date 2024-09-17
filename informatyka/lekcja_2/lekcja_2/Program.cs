using System;
using System.IO;
using System.Linq.Expressions;


internal class Program
{
    public static string[] BubbleSort_String(string[] array)
    {
        int length = array.Length;

        string temp = array[0];

        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (Int32.Parse(array[i]) > Int32.Parse(array[j]))
                {
                    temp = array[i];

                    array[i] = array[j];

                    array[j] = temp;
                }
            }
        }

        return array;
    }

    private static int[] BubbleSort(int[] array)
    {
        int length = array.Length;

        int temp = array[0];

        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (array[i] > array[j])
                {
                    temp = array[i];

                    array[i] = array[j];

                    array[j] = temp;
                }
            }
        }

        return array;
    }

    static void WriteToFile(string text, string filePath)
    {
        // try
        // {
        //     using (FileStream fs = File.Create(filePath))
        //     {
        //         byte[] info = new UTF8Encoding(true).GetBytes("This is some text in the file.");
        //         // Add some information to the file.
        //         fs.Write(info, 0, info.Length);
        //     }        }
        // catch (Exception e)
        // {
        //     Console.WriteLine(e.Message);
        // }
        using (StreamWriter writer = new StreamWriter(filePath))
        {
            writer.WriteLine(text);
        }

        Console.WriteLine("File created successfully...");
    }

    public static void Main(String[] args)
    {
        Random rnd = new Random();
        int[] T = new int[200];
        string text = "";
        for (int i = 0; i < T.Length; i++)
        {
            T[i] = rnd.Next(0, 100);
        }

        int[] Y = BubbleSort(T);
        for (int i = 0; i < Y.Length; i++)
        {
            text += Y[i].ToString() + "\n";
        }


        // get path to this file
        
        string filePath = Path.Combine(Directory.GetCurrentDirectory(), "file.txt");
        Console.WriteLine(filePath);
        WriteToFile(text, filePath);
    }
}