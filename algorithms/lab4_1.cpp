#include <iostream>  
#include <math.h>
#include <limits> 
using namespace std;  
  
  void maxheapify(int arr[], int n, int i)
{
	
	//n is the herap size
    int largest = i;  // set largest = i
    int left = 2*i + 1;  // set left 
    int right = 2*i + 2;  // set right
 
    // if the heap size is greater than the left and element greater that the largest, return left
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // else then retrun right
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // if the largest does not equal i, then exchange a[i] with the largest
    if (largest != i){
        swap(arr[i], arr[largest]); //swap function ,makes the exchange
 
        // recurse
        maxheapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[],int n){
	//n is the size of the array
	//from the book
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
 
}



void heapSort(int arr[], int n)
{
	buildMaxHeap(arr,n); //build max heap
   

    for (int i=n-1; i>=0; i--)
    {
     
        swap(arr[0], arr[i]); //swap elements
 
       
        maxheapify(arr, i, 0); //call max heapify
    }
}

 
  
int main()  
{  
int size=0;
 cin>>size; 
int a[size]; 


	for(int i=0; i<size; i++){
		cin>>a[i]; 
		} 
		

	 heapSort(a, size); 
    
	
  
	for(int j=0; j<size; j++){
		cout<<a[j]<<";"; 	
				}
		cout<<endl;		
			
				
   
    return 0;  
}  
