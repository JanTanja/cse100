#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main()
{

int temp; //to hold the values in the index

int size;


int j;

//cout<<"Enter the size for the array: "<<endl;
cin>>size; //user input for the size
int array[size]; //initialize array and put the size value for the array.



		for(int i = 0; i<size;i++){//initialize array  for user input
		cin>>array[i]; //take in user input
		}


		for(int i = 1; i<size; i++){ //start the array at the second element, which is at index 1
			
				temp=array[i];//temporary variable is the key variable set to the second element of the array being analyzed
				j=i-1; //j will be the element for comparison
				
				while(j>=0 && array[j]>temp){ //while j is the 0th index and the key is less than the previous element
					
					array[j+1]=array[j]; //move the element back
					j=j-1; //decrement j
					array[j+1]=temp; //set the key element to the next j index

				
				}
				
				
				for(int j=0; j<=i; j++){ //print the array
			
					cout<<array[j]<<";"; 	
				
				}
				cout<<""<<endl;
			
		
			} 
		
return 0;
	
}
			
			

