
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector> 

using namespace std;

void MergeFunc(int *array, int l, int m, int r) {

  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
      L[i] = array[l + i];
  for (j = 0; j < n2; j++)
      R[j] = array[m + 1+ j];


  i = 0; 
  j = 0; 
  k = l; 
  while (i < n1 && j < n2)
  {
      if (L[i] <= R[j])
      {
          array[k] = L[i];
          i++;
      }
      else
      {
          array[k] = R[j];
          j++;
      }
      k++;
  }

  while (i < n1)
  {
      array[k] = L[i];
      i++;
      k++;
  }

  while (j < n2)
  {
      array[k] = R[j];
      j++;
      k++;
  }

}
void MergeSort(int *array, int l, int r) {

  if (l < r)
  {

      int m = l+(r-l)/2;

      MergeSort(array, l, m);
      MergeSort(array, m+1, r);
      MergeFunc(array, l, m, r);
  }
  
}

void InsertionSort(int *array, int n) {

  int i, j, k;
  for (i = 1; i < n; i++)
  {
      k = array[i];
      j = i-1;

      while (j >= 0 && array[j] > k)
      {
          array[j+1] = array[j];
          j = j-1;
      }
      array[j+1] = k;
  }

}

void MyFunc ( int *array, int n ) {  
  // for MergeSort
  int l = 0;
  int r = n;
  if (n >= 100) MergeSort(array, l, r - 1);
  else if (n < 100) InsertionSort(array, n - 1);

}


int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;

  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  MyFunc(Sequence, arraySize); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
