# include <iostream>
# include <string>
# include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 * primary constructor
 ****************************************************************/

BST::BST() {
  root = NULL;
}

/****************************************************************
 * DECONSTRUCTOR
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
			Transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
}


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