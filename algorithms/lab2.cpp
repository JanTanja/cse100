#include <iostream>  
#include <math.h>
#include <limits> 
using namespace std;  
  
  
void merge(int A[], int p, int q, int r) {       
    int n1 = q-p+1;  //intitialize indeces size from low to mid                           
    int n2 = r-q;    //initialze                           

    int i,j,k;
    int *L=new int[n1+1], *R = new int[n2+1];   //initilize left and Right arrays

    for(i=0; i<n1; i++) //for left array has the size from low to mid                        
        L[i]=A[p+i];    //set the left element to the array                      
              
    for(j=0; j<n2;j++)  //for right array has the size from mid+1 end                       
        R[j]=A[q+1+j];  //set the right array to the array                     

	int inf = std::numeric_limits<int>::max();//infinity

    L[n1]=inf; //sentinel                      
    R[n2]=inf; //sentinel                       
    i=0; //init i to 0                                    
    j=0; //init j to 0                                       
    for(k=p; k<=r; k++) {                        
        if(L[i]<=R[j])    //if the left array element is less than or equal to the right element array, set the left element to the array, and increment                      
            A[k]=L[i++];                        
                                                
        else                                    
            A[k]=R[j++];   //else set right element to the array                               
    }

}
  
void mergeSort(int a[],  int p,  int r)   
{  
    int q; //initialize the middle index 
    if(p<r)  //if the low is less than the high
    {  
        q=(p+r)/2;  //mid initialization
        mergeSort(a, p,q);  //recursive call from low to mid
        mergeSort(a, q+1,r);  //recursive from mid+1 to high
        merge(a, p,q,r);  //merge call from low to mid to high
    }  
}  
  
int main()  
{  
int size=0;
 cin>>size; //user input for the size
int a[size]; //initialize array and put the size value for the array.


	for(int i=0; i<size; i++){
		cin>>a[i]; //input for the array 
		} 
	  
    			mergeSort(a, 0, (size-1)); //the array size will be from 0 to size-1
	
  
				for(int j=0; j<size; j++){ //print array
			
					cout<<a[j]<<";"; 	
				}
				cout<<endl;
   
    return 0;  
}  
