
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


void heapify(int *array, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && array[l] > array[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && array[r] > array[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(array[i], array[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

void MyFunc ( int *array, int n ) {  
  
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(array[0], array[i]);
 
        // call max heapify on the reduced heap
        heapify(array, i, 0);
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
  for ( int i=0; i<arraySize; i++ )
    cin >> Sequence[i];

  // Run your algorithms to manipulate the elements in Sequence
  MyFunc( Sequence, arraySize ); 
    
  // Output the result
  for(int i=0; i<arraySize; i++)
      cout << Sequence[i] << endl;
    
  // Free allocated space
  delete[] Sequence;
}
