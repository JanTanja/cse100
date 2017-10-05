# include <iostream>
# include <string>
# include <vector>
# include <list>
# include "Hash.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 ****************************************************************/
Hash::Hash(int _bNo) {
  this->bNo = _bNo;
  for (int c = 0; c < bNo; c++) 
  {
    list<int> temp;
    table.push_back(temp);
  }
}

/****************************************************************
 * DESTRUCTOR
 ****************************************************************/
Hash::~Hash() {
  delete this;
}

void Hash::Insert(int toInsert) {
  // insert toInsert into a list in an entry by the hash function inside table
  // cout << "inserting " << toInsert << "inside table at " << (toInsert % bNo) << endl;
  
  
  table[toInsert % bNo].push_front(toInsert);
  
}

bool Hash::Delete(int toDelete) {
  bool boolean;
  list<int>::iterator iterate;
  for (iterate = table[(toDelete % bNo)].begin(); iterate != table[(toDelete % bNo)].end(); ++iterate) 
  {
    if (*iterate == toDelete) 
    {
      table[(toDelete % bNo)].erase(iterate);
      boolean = true;
      break;
    }
  }
  if (!boolean) 
  {
    boolean = false;
  }
  return boolean;
}

bool Hash::Search(int key, int& _bucket, int& _pos) {
    // return value for the function Hash::Search
    bool boolean;
    int i = 0;
    list<int>::iterator iterate;

//    for (iterate = table[(key % bNo)].begin(); iterate != table[(key % bNo)].end(); ++iterate) 
//    {
 //     if (*iterate == key) 
//      { 
//        _bucket = i;
//        _pos = *iterate;
//        boolean = true;
//        break;
//      }
//    i++;
//  }


// first for loop to account for all of the values inside each element
for (int c = 0; c < bNo; c++ ) {
	// second for loop to account for all of the lists in each respective element
	for (iterate = table[i].begin(); iterate != table[i].end(); ++iterate) {
		// if found, then return true
		if (*iterate == key) 
		{
			_bucket = i;
			_pos = *iterate;
			boolean = true;
			break;
		}	
		i++;
	}
}

  if (!boolean)
  {
    boolean = false;
  }
	return boolean;
}

void Hash::Print() {
    list<int>::iterator iterate;
    int i = 0;
    
    // iterate through each element of the hash table

    for (int c = 0; c < bNo; c++) 
    {
      cout << c << " : ";
      for (iterate = table[c].begin(); iterate != table[c].end(); ++iterate){
		
		cout << *iterate << "->";
	   
	}
	// endl after every single c value
	cout << endl;
  }
}
