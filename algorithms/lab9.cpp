
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    char alpha;
    int freq;
    Node *left;
    Node *right;
	//const
    Node(char alpha, int freq) {  
        left = NULL;
        right = NULL;
        this->alpha = alpha;
        this->freq = freq;
    }
    ~Node(){} //dest
};

class comp {
public:
    bool operator() (Node *l, Node *r) {
        return (l->freq > r->freq);
    }
};

void print (Node *c, string out, char array[], int num) {
    int i = num;
    if(!c) {
        return;
    }
    if(c->alpha == array[i]) {
        cout << c->alpha << ":" << out << endl;
    }
    print(c->left, out + "0", array, i);
    print(c->right, out + "1", array, i);
}
void huffcode(char array[], int freq[], int size) {
    Node *a;
    Node *b;
    Node *c;
    priority_queue<Node*, vector<Node*>, comp> A;
    for(int i = 0; i < size; ++i) {
        A.push(new Node(array[i], freq[i]));
    }
    while(A.size() != 1) {
        a = A.top();
        A.pop();
        b = A.top();
        A.pop();
        c = new Node('Z', (a->freq + b->freq));
        c->left = a;
        c->right = b;
        A.push(c);
    }
    for(int i = 0; i < 6; i++) {
        print(A.top(), "", array, i);
    }
}

int main() {
    char array[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int frequency[6];
    for(int i = 0; i < 6; i++) {
        cin >> frequency[i];
    }
    int size = sizeof(array)/sizeof(array[0]);
    huffcode(array, frequency, size);
    return 0;
}  
