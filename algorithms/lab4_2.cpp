#include <iostream>  
#include <math.h>
#include <limits> 
using namespace std;  
  int  partition(int arr [], int p, int r ){
  	
  	int x = arr[r];
  	
  	int i = p-1;
  	
  	for (int j = p; j <=r-1; j ++){
  		
  			if (arr[j]<= x){
  				i++;
  				swap(arr[i],arr[j]);
  				
			  }
	  }
	swap(arr[i+1],arr[r]);
	return i+1;
  }

 void quickSort(int arr[], int p ,int r ){ //p==low, r==high
 
 	if(p<r){
 		
 		int  q=partition(arr,p,r);
 		quickSort(arr,p,q-1);
 		quickSort(arr,q+1,r);
	 }
 	
 	
 }
  

int main()  {  
int size=0;
 cin>>size; 
int a[size]; 


	for(int i=0; i<size; i++){
		cin>>a[i]; 
		} 
		

	 quickSort(a,0, size-1); 
    
	
  
	for(int j=0; j<size; j++){
					cout<<a[j]<<";"; 	
				}
				
			
	cout<<endl;		
   
    return 0;  
}  
