
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

   int partition (int * arr, int low, int high)
   {
       int pivot = arr[high];    // pivot
       int i = (low - 1);  // Index of smaller element
    
       for (int j = low; j <= high- 1; j++)
       {
           // If current element is smaller than or
           // equal to pivot
           if (arr[j] <= pivot)
           {
               i++;    // increment index of smaller element
               swap(&arr[i], &arr[j]);
           }
       }
       swap(&arr[i + 1], &arr[high]);
       return (i + 1);
   }
    
   /* The main function that implements QuickSort
    arr[] --> Array to be sorted,
     low  --> Starting index,
     high  --> Ending index */
   void MyFunc(int *array, int low, int high)
   {
       if (low < high)
       {
           /* pi is partitioning index, arr[p] is now
              at right place */
           int pi = partition(array, low, high);
    
           // Separately sort elements before
           // partition and after partition
           MyFunc(array, low, pi - 1);
           MyFunc(array, pi + 1, high);
       }
   }

int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;
  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  for ( int i=0; i<arraySize; i++ ) {
    cin >> Sequence[i];
  }
  // Run your algorithms to manipulate the elements in Sequence
  MyFunc( Sequence, 0, arraySize - 1); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
