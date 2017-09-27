<<<<<<< HEAD
// Written by Jan Tanja

#include <iostream>
#include <algorithm>

int partition(int *array, const int l, const int r) {
    const int mid = l + (r - l) / 2;
    const int pivot = array[mid];
    // move the mid point value to the front.
    std::swap(array[mid],array[l]);
    int i = l + 1;
    int j = r;
    while (i <= j) {
        while(i <= j && array[i] <= pivot) {
            i++;
        }

        while(i <= j && array[j] > pivot) {
            j--;
        }

        if (i < j) {
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i - 1],array[l]);
    return i - 1;
}

void quicksort(int *array, const int l, const int r, const int sz){
    if (l >= r) {
        return;
    }
    int part = partition(array, l, r); 
    quicksort(array, l, part - 1, sz);
    quicksort(array, l + 1, r, sz);
}

int main(int argc, char **argv)
{
  int arraySize, *Sequence;
  std::cin >> arraySize;
  Sequence = new int[arraySize];
  for (int c = 0; c < arraySize; c++)
    std::cin >> Sequence[c];
  quicksort(Sequence, 0, (arraySize - 1), arraySize); 
  for(int c = 0; c < arraySize; c++)
      std::cout << Sequence[c] << std::endl;
  delete[] Sequence;
  return 0;
}
=======
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int quickSort(int *array, int p, int r)
{ 
  int pivot = array[r];
  int i = (p - 1); 
  for (int c = p; c <= (r - 1); c++)
  {
    if (array[c] <= pivot)
    {
      i++;
      swap(&array[i], &array[c]);
    }
  }
  swap(&array[i + 1], &array[r]);
  return (i + 1);
}

void sort(int *array, int p, int r)
{
  if (p < r)
  {
    int pivot = array[(rand() % (r + 1))]; 
    sort(array, p, (pivot - 1));
    sort(array, (pivot + 1), r);
  }
  return;
}

int main(int argc, char **argv)
{
  int arraySize, *Sequence;
  cin >> arraySize;
  Sequence = new int[arraySize];
  for (int c = 0; c < arraySize; c++)
    cin >> Sequence[c];
  sort(Sequence, 0, (arraySize - 1)); 
  for(int c = 0; c < arraySize; c++)
      cout << Sequence[c] << endl;
  delete[] Sequence;
  return 0;
}
>>>>>>> 60aab081c6ff3518b70096780210cd7f604feef7
