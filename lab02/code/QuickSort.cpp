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