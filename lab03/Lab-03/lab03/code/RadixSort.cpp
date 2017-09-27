#include <iostream>
#include <stdlib.h>
using namespace std;

class vec{
	public:
		int key[11];
		vec() {
			for(int i = 1; i <= 10; i++) {
				key[i] = 0;
			}
		}
};
vec** arr;
vec** arr1;

void count_sort(int i, int size) {
	int x, j, y, c[4];
	for(x = 0; x < 4; x++) {
		c[x] = 0;
	}
	for(j = 1; j <= size; j++) {
		c[arr[j]->key[i]] = c[arr[j]->key[i]]+1;
	}
	for(x = 1; x < 4; x++) {
		c[x] = c[x]+c[x-1];
	}
	for(j = size; j >= 1; j--) {
		arr1[c[arr[j]->key[i]]] = arr[j];
		c[arr[j]->key[i]] = c[arr[j]->key[i]]-1;
	}
	for (y = 1; y <= size; y++) {
		arr[y] = arr1[y];
	}
}

void radix_sort(int size) {
	for(int i = 10; i >= 1; i--) {
		count_sort(i, size);
	}
}

int main() {
	int num, x, size;
	cin >> size;
	arr = new vec * [size + 1];
	arr1 = new vec * [size + 1];

	for(num = 1; num <= size; num++) {
		arr[num] = new vec();
		for(int x = 1; x <= 10; x++) {
			cin >> arr[num]->key[x];
		}
	}
	radix_sort(size);
	for(num = 1; num <= size; num++) {
		for(x= 1; x <= 10; x++) {
			cout << arr[num]->key[x] << ";";
		}
		cout << "\n";
	}
	for(num = 1; num <= size; num++) {
		delete arr[num];
	}
	delete[] arr;
	delete[] arr1;
	return 0;
}

