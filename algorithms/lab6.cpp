 #include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;
 
 
void  theDelete(vector<list<int> > &hashtable, int key){
 	
 	int size = hashtable.size();
 	
 	int val = (key % size); //to find the link to find to delete the value
 	
 		list<int>:: iterator iterate = find(hashtable[val].begin(), hashtable[val].end(), key);
 		
 		if(iterate == hashtable[val].end()){
		
			cout << key << ":DELETE_FAILED;" << endl;
		}
	else{
			hashtable[val].erase(iterate);
			cout << key << ":DELETED;" << endl;	
		}
 	
 }
 
 
 
 
 void search(vector<list<int> > &hashtable, int key){
 	int size = hashtable.size();
 	
 	int val = (key % size); //to find the link to find to delete the value
 	
 		list<int>:: iterator iterate = find(hashtable[val].begin(), hashtable[val].end(), key);
 		
 		if(iterate == hashtable[val].end()){
		
			cout << key << ":NOT_FOUND;" << endl;
		}
	else{
		cout << key << ":FOUND_AT" << val << "," << distance(hashtable[val].begin(), iterate) << ";" << endl;
		}
 	
 }
 void insert(vector<list<int> > &hashtable, int numval){
 	
 	int totalsize= hashtable.size();
 	
 	int modput = numval % totalsize;
 	
 	hashtable[modput].push_front(numval);
 	
 }
 void print(vector<list<int> > &hashtable){
	 int hashSize = hashtable.size();
	
	for(int i = 0; i < hashSize; i++) //for each vector space
		{
			cout << i << ":";
			for(list<int>::iterator iterate = hashtable[i].begin(); iterate != hashtable[i].end(); ++iterate) { //for each element
					cout << *iterate << "->";
				}
			cout << ";" << endl;
		}
}
 
 
 
 int main(){
 	int size;  //this is the size for the hashtable
 	cin>>size;
 	
 	vector<list<int> > hashtable; //initialize the hashtable 
 	
 	hashtable.resize(size); // initialize the size of the vector, which is the hahstable
 	
 	string input;
 	cin >> input;
 	
 	int numval = 0;
 	
 	string func = "";
 	
 	
 	while (input!="e"){ //if it does not end
 	
 	
 		if (input!="o"){ //if the user did not press on the output of the fucntion
 		
 		
 		
 		
 			//read thought the strings and separate them from the action keys and the value keys
 			
 			func = input.substr(0,1); //go the the function. found at the first location of the substring
 			
 			stringstream convert(input.substr(1,input.size()-1)); 
 			
	 				if(!(convert >> numval)) {
					 
							numval = -1;
					}
					
					if(func == "i"){ //insert
						insert(hashtable, numval);
					}
					
					else
					
					if(func=="s"){
						search(hashtable,numval);
					}
					
					else
					
					if(func=="d"){
						theDelete(hashtable,numval);
					}
					
				}
				
			if(input=="o"){
				print(hashtable);
			}
					
					
			cin>>input;
 			
		 }
}
 	

