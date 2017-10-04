// written by Jan Tanja

#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 *   Creates an binary tree
 ****************************************************************/
BST::BST() {
  root = NULL;
}

/****************************************************************
 * DECONSTRUCTOR
 *   Empty constructor
 ****************************************************************/
BST::~BST() {
}

void BST::Insert(int toInsert) {
	// node that will be iterated and checking over other nodes
	Node* y = NULL;
	// this is the parent node
      	Node* x = root;
	// node to insert 
	Node* z = new Node(); 
	z-> val = toInsert;
	// setting values of z to be NULL until we insert
	z->left = NULL;
	z->right = NULL;	
	z->parent = NULL;
	// recursively checking values of x to find out where the z value fits
	while(x != NULL) {
		y = x;
		if(toInsert < (x->val)) {
			x = (x->left);
		} else {
			x = (x->right);
		}
	}
	z->parent = y;
	if(y == NULL) {
		root = z;
	}
	else if(toInsert < (y->val)) {
		y->left = z;
	} else {
 		y->right = z;
	}
}	

void BST::Delete(int toDelete) {
	Node* z = Search(toDelete);
	Node* y;
	if(z->left == NULL) {
		Transplant(z, z->right);
	}
	else if (z->right == NULL) {
		Transplant(z, z->left);
	} else {
		y = Minimum(z->right);
		if(y->parent != z) {
			Transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
}

void BST::Transplant(Node *u, Node *v) {
	Node* z = root;
	if(u->parent == NULL) {
		root = v;
	}
	else if(u == u->parent->left) {
		u->parent->left = v;
	} else {
		u->parent->right = v;
	}
	if(v != NULL) {
		v->parent=u->parent;
	}
}

Node *BST::Successor(Node *x) {
	Node* y;
	if(x->right == NULL) {
		return Minimum(x->right);
	}
	y = x->parent;
	while(y != NULL && x == (y->right)) {
		x = y;
		y = y->parent;
	}
	return y;
}

Node *BST::Minimum(Node *x) {
	while(x->left != NULL) {		
		x = x->left;
	}
	return x;
}

Node *BST::Maximum(Node *x) {
	while(x->right == NULL) {
		x = x->right;
	}
	return x; 
}

Node *BST::Search(int toFind) {
	Node* temp = root; 
	while(temp != NULL && toFind != temp->val) {
		if(temp->val > toFind) {
			temp = temp->left;
		} else {
			temp = temp->right;
		}
	}
	return temp;
}

void BST::Print(enum TraversalOrder) {
	TraversalOrder order;
	if(order == InOrderTrav) {
		InOrder(root);
	}
	else if(order == PreOrderTrav) {
		PreOrder(root);
	}
	else if(order == PostOrderTrav) {
		PostOrder(root);
	}
}

void BST::PreOrder(Node *x) {
	if(x != NULL) {
		cout << x->val <<endl;
		PreOrder(x->left);
		cout << "preorder" << endl;
		PreOrder(x->right);
	}
}

void BST::InOrder(Node *x) {
	if(x != NULL) {
		InOrder(x->left);
		cout << x->val <<endl;
		InOrder(x->right);
	}
}

void BST::PostOrder(Node *x) {
	if(x!= NULL) {
		PostOrder(x->left);
		PostOrder(x->right);
		cout << x->val <<endl;
	}
}

