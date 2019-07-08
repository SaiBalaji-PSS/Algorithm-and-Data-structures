using System;

namespace Insertion_sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int i;
            int j;
            int temp;
            
            int[] a = { 34, 8, 64, 51, 4, 5 };
            Console.WriteLine("Before sorting");
           
            foreach(int e in a)
            {
                Console.WriteLine(e);
            }
            for(i=1;i<a.Length;i++)
            {
                temp = a[i];
                j = i - 1;
                while(j>=0&&a[j]>temp)
                {
                    a[j + 1] = a[j];
                    j = j - 1;
                }
                a[j + 1] = temp;
            }
            Console.WriteLine();
            Console.WriteLine("After sorting");
            foreach (int e in a)
            {
                Console.WriteLine(e);
            }

        }
    }
}
