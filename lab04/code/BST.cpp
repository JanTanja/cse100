<<<<<<< HEAD
// written by Jan Tanja

#include <iostream>
#include <string>
#include "BST.h"
=======
# include <iostream>
# include <string>
# include "BST.h"
>>>>>>> 5808438b41e0dc063601dcb80a2ea5ebf429f115

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
<<<<<<< HEAD
 *   Creates an binary tree
=======
 * primary constructor
>>>>>>> 5808438b41e0dc063601dcb80a2ea5ebf429f115
 ****************************************************************/

BST::BST() {
  root = NULL;
}

/****************************************************************
 * DECONSTRUCTOR
<<<<<<< HEAD
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
=======
 * Empty constructor
 ****************************************************************/
BST::~BST() {
}

void BST::Insert(int inserted_node) 
{
  // initialize nodes
	Node* place_hold;
	Node* root_node;
  Node* new_node;
  
  // initialize their values
  place_hold = NULL;
  root_node = root;
  new_node = new Node();

  //inserted node will be the new node's value
  new_node-> val = inserted_node;
  
  
	new_node->left = NULL;
	new_node->right = NULL;	
  new_node->parent = NULL;
  
	while(root_node != NULL) 
	{
		place_hold = root_node;
    if(inserted_node < (root_node->val)) {
      root_node = (root_node->left); 
    }
    else {
    root_node = (root_node->right);
    }
  }
  
  new_node->parent = place_hold;
  
	if(place_hold == NULL) {
    root = new_node;
  }

	else if(inserted_node < (place_hold->val)) {
    place_hold->left = new_node; 
  }

	else {
    place_hold->right = new_node;
  }

}	

void BST::Delete(int deleted_node) 
{
  // node to be deleted 
  Node* z;
  z = Search(deleted_node);
  Node* y;

  // following conditional statements check for NULL nodes to transplant in the Transplant() function
  if(z->left == NULL) {
    Transplant(z, z->right);
  }

	else if (z->right == NULL) {
    Transplant(z, z->left);
  }

	else 
	{
		y = Minimum(z->right);
		if (y->parent != z) 
		{
>>>>>>> 5808438b41e0dc063601dcb80a2ea5ebf429f115
			Transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
}

<<<<<<< HEAD
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
=======

void BST::Transplant(Node *n1, Node *n2) 
{
	Node* z = root;
  if(n1->parent == NULL) {
    root = n2;
  }
  else if (n1 == n1->parent->left) {
    n1->parent->left = n2;
  }
	else {
    n1->parent->right = n2;
  }
	if (n2 != NULL) {
    n2->parent=n1->parent;
  }
}


Node *BST::Minimum(Node *n)
{
	while(n->left != NULL) {
    n = n->left;
  }
	return n;
}

Node *BST::Maximum(Node *n) 
{
	while(n->right == NULL){ 
   n = n->right;
  }
	return n; 
}

Node *BST::Search(int to_find) 
{
  Node* t; 
  t = root;

	while ((t != NULL) && (to_find != t->val)) 
	{
		if (t->val > to_find) {
      t = t->left;
    }
		else {
      t = t->right;
    }
	}
	return t;
}

void BST::Print(TraversalOrder order) 
{
	// cout << "Print Function" << endl;
	if (order == InOrderTrav) InOrder(root);
	else if (order == PreOrderTrav) PreOrder(root);
	else if (order == PostOrderTrav) PostOrder(root);
}

void BST::PreOrder(Node *curr) 
{
	if (curr != NULL) 
	{
		cout << curr->val <<endl;
		PreOrder(curr->left);
		PreOrder(curr->right);
	}
}

void BST::InOrder(Node *curr) 
{
	if (curr != NULL) 
	{
		InOrder(curr->left);
		cout << curr->val <<endl;
		InOrder(curr->right);
>>>>>>> 5808438b41e0dc063601dcb80a2ea5ebf429f115
	}
}

void BST::PostOrder(Node *curr) 
{
	if (curr!= NULL) 
	{
		PostOrder(curr->left);
		PostOrder(curr->right);
		cout << curr->val <<endl;
	}
}
