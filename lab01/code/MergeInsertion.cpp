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
void MergeSort(int *array, int leftBound, int rightBound) {

  if (leftBound < rightBound)
  {

      int m = leftBound+(rightBound-leftBound)/2;

      MergeSort(array, leftBound, m);
      MergeSort(array, m+1, rightBound);

      MergeFunc(array, leftBound, m, rightBound);
  }
  
}

void InsertionSort(int *array, int low, int high) {

  int i, j, k;
  for (i = 1; i < high; i++)
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

void MyFunc ( int *array, int low, int high ) {  
  // for MergeSort
  int r = high - low;
  if (r >= 100) MergeSort(array, low, high);
  else if (r < 100) InsertionSort(array, low, high);

}

int main(int argc,char **argv) {

  int *Sequence;
  int arraySize;
  int low, high = 0;
  // Get the size of the sequence
  cin >> arraySize;

  // Allocate enough memory to store "arraySize" integers
  Sequence = new int[arraySize];
    
  // Read in the sequence
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];
  

// Run your algorithms to manipulate the elements in Sequence
  MyFunc(Sequence, 0, arraySize ); 
    
  // Output the result
  for(int i=1; i<arraySize; i++)
     if (i < arraySize)
      cout << Sequence[i] << endl;
     else 
      cout << Sequence[i];
  // Free allocated space
  delete[] Sequence;
}
