using System;
//Shell_sort
using System.Linq;
using System.Collections.Generic;

namespace CSharp_Shell
{

    public static class Program 
    {
        public static void Main() 
        {
           int gap,i,j,temp;
           int []a={49,18,26,33,12,10,40,58,4,6};
           Console.WriteLine("Before sorting");
           foreach(int e in a)
           {
               Console.WriteLine(e);
           }
           for(gap=a.Length/2;gap>0;gap=gap/2)
           {
               for(i=gap;i<a.Length;i++)
               {
                   temp=a[i];
                   j=i-gap;
                   while(j>=0&&a[j]>temp)
                   {
                       a[j+gap]=a[j];
                       j=j-gap;
                   }
                   a[j+gap]=temp;
               }
           }
           Console.WriteLine("After sorting");
           foreach(int e in a)
           {
               Console.WriteLine(e);
           }
        }
    }
}
