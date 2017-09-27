<<<<<<< HEAD
# include <iostream>
# include <cstdlib>
# include <string>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int *array, int size, int c)
{
  int i = c;
  int left = (2 * c) + 1;  
  int right = (2 * c) + 2;  
  if (left < size && array[left] > array[i])
      i = left;
  if (right < size && array[right] > array[i])
      i = right;
  if (i != c)
  {
      swap(array[c], array[i]);
      heapify(array, size, i);
  }
  return;
}
void sort(int *array, int size) 
{  
  for (int c = (size); c >= 0; c--)
    heapify(array, size, c);
  for (int c = (size - 1); c >= 0; c--)
  {
    swap(array[0], array[c]);
    heapify(array, c, 0);
  }
  return;
}
int main(int argc, char **argv)
{
  int arraySize, *Sequence; 
  cin >> arraySize; 
  Sequence = new int[arraySize]; 
  for (int c = 0; c < arraySize; c++ ) 
    cin >> Sequence[c]; 
  sort(Sequence, arraySize);  
  for(int c = 0; c < arraySize; c++) 
      cout << Sequence[c] << endl; 
  delete[] Sequence; 
=======
// Written by Jan Tanja


#include <iostream>

using namespace std;

void heapify( int *a, int k, int N); 

void swap(int *m, int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
}

void heapsort( int a[], int N){       
	/* heapify */    
	for (int k = N/2; k >= 0; k--) { 
		heapify( a, k, N);    
	}     

	while (N-1 > 0) {  
		/* swap the root with last */
		swap(a[N-1], a[0]); 
		heapify(a, 0, N-1);  
		/* N-- : stable sort */
		N--;
	}
}  

void heapify( int *a, int k, int N){     
	while ( k*2 + 1 < N ) { 
 		int kid = 2*k + 1;    

		if ((kid + 1 < N) && (a[kid] < a[kid+1])) kid++;        
       
		if (a[k] < a[kid]) {        
			swap( a[kid], a[k] );  
			k = kid;  
		}        
		else            
			return;    
	}
} 

int main(int argc, char **argv)
{
  int arrSize, *Sequence;
  cin >> arrSize;
  Sequence = new int[arrSize];
  for (int i = 0; i < arrSize; i++ )
    cin >> Sequence[i];
  heapsort(Sequence, arrSize); 
  for(int i = 0; i < arrSize; i++)
      cout << Sequence[i] << endl;
  delete[] Sequence;
>>>>>>> 486d012ac4060a35d021527bebcfb970a3fe8394
  return 0;
}
