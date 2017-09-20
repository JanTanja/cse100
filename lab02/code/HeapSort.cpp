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
  return 0;
}
