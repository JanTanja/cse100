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
  return 0;
}
