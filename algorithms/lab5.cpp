#include <iostream>
#include <vector>
#define limit 10

using namespace std;


vector< vector<int> > countSort(vector< vector<int> > vec, vector<int> vec2){

	vector<int> c(limit,0);
	
	
	for ( int i = 0; i < vec2.size(); i++ ){
	
		c[vec2[i]] += 1; 
	}
	for ( int i = 1; i < c.size(); i++ ){
		c[i] += c[i-1];
	}

	vector< vector<int> > out;
	
	out.resize(vec2.size());							
	for ( int i = 0; i < vec2.size(); i++ )
	{
		out[i].resize(limit);
	}

	for ( int i = vec2.size()-1; i >=0; i-- )
	{
	
		swap(out[c[vec2[i]]-1],vec[i]);
	
		
		c[vec2[i]] -= 1;
	
	}

	return out;

}
	
void radixSort(vector< vector<int> > vec)
{

	for (int i = 9; i >= 0; i--)
	{
		vector<int> output_v;
		
		for (int j = 0; j < vec.size(); j++ ){
		
			output_v.push_back(vec[j][i]);
		}
		vec = countSort(vec,output_v);
	
	}

		for(int i = 0; i < vec.size(); i++){
			for (int j = 0; j < vec[i].size(); j++){
				cout << vec[i][j] << ";";
			}
			cout << endl;
		}


}

int main()
{
	vector< vector<int> > given; //intialize vector


	int rows; //how many rows are there
	cin >> rows; //input rows for the vector
	given.resize(rows);  //there are "rows" amount off vector into the space

	int input; //for the input for the array

	for(int i = 0; i < rows; i++) //for the rows
		{
			for(int j = 0; j < limit; j++) //10 elements pushed into the vector, pushed into the vector
			{
				cin >> input;
				given[i].push_back(input);
			}
		}
	radixSort(given);

	
	return 0;
}

