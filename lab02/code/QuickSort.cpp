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
