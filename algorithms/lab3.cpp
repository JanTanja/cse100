#include <iostream>  
#include <math.h>
#include <limits> 
using namespace std;  



  
int maxcross(int arr[], int l, int m, int h) {       
 int inf = std::numeric_limits<int>::max();//infinity sentinel
    int sum = 0; //sum to 0
    int left = -inf; //set left to -infinity
    for (int i = m; i >= l; i--){ //for loop to iterate on the left subaray
        sum = sum + arr[i];
        if (sum > left) //if sum is greater
          left = sum;	//then set left to sum
    }

 
    sum = 0;
    int right= -inf;
    for (int i = m+1; i <= h; i++){ //for loop to iterate for the right side
    
        sum = sum + arr[i];
        if (sum > right) //if sum is greater than right
          right = sum;   //set right to sum
    }

    
    return left + right; //retrun the sum of left and right

}
  
int maxsub(int a[],  int low,  int high){
 if (high==low){ //base case
 
     return a[low]; //return the low
     
 }
	else{ 
 

   int mid = (low + high)/2;//initialize the mid
 

              
	    	int left_sum=maxsub(a, low, mid); //the left sum from low to mid
	    	int right_sum=maxsub(a, mid+1, high); //the right sum from mid to high
		int cross_sum=maxcross(a, low, mid, high); //the cross sum in the middle
		
		if(left_sum>=right_sum && left_sum>=cross_sum){ //if left is greater, return left
			return left_sum;
		}
		else if(right_sum>=left_sum && right_sum>=cross_sum){ //if right is greater, return right
			return right_sum;
		}
		else
		return cross_sum;
              
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
		
		int b = maxsub(a, 0, (size-1));
	  
    		cout<< b <<endl;
	
  
			
				
   
    return 0;  
}  
