#include <sstream>
#include <iostream>


struct Node {
  int val;   //node value
  Node *left;   //left node pointer
  Node *right;  // right node pointer
  Node *parent; // parent node pointer
};

class BST { //this is a class to create a binary search tree

  public: 
	  enum travOrder { inOrder,
	  preOrder, 
	 postOrder};


  public:
    BST();  // constructor
   ~BST(); // destructor
    void Insert(int insert);
    void Delete(int del);
    void Print(enum travOrder);


  private:
    Node *root;
 	Node *max(Node *n);
    Node *min(Node *n);
    Node *succ(Node *n);
    Node *search(int n); 
    
  
   
 
    void in_order(Node *n); // inorder traversal
    void pre_order(Node *n); // preorder traversal
    void post_order(Node *n); // pstorder traversal
    
    
    
       void transplant(Node *a, Node *b); 
};

using namespace std;


BST::BST() {
  root = NULL;
}


BST::~BST() {
//
}


void BST::Insert(int insert) {

  Node* a = NULL;         //temp
  Node* b = root;         //root node
  Node* c = new Node();   //inderted not

  c->val = insert;

  while(b != NULL) {
    a = b;

    if (b->val > insert) {
      b = b->left;
    } else {
      b = b->right;
    }
  }

  c->parent = a;
  if (a == NULL) {
    root = c;
  } else if (insert < a->val) {
    a->left = c;
  } else {
    a->right = c;
  }
}

void BST::Delete(int del) {

  Node* x = search(del);
  Node* y;

  if (x->left == NULL) {
    transplant(x, x->right);
  } else if (x->right == NULL) {
    transplant(x, x->left);
  } else {
    y = min(x->right);

    if (y->parent != x) {
      transplant(y, y->right);
      y->right = x->right;
      y->right->parent = y;
    }
    transplant(x,y);
    y->left = x->left;
    y->left->parent = y;
  }
}



void BST::transplant(Node *a, Node *b) {

  if (a->parent == NULL) {
    root = b;
  } else if (a == a->parent->left) {
    a->parent->left = b;
  } else {
    a->parent->right = b;
  }

  if (b != NULL) {
    b->parent = a->parent;
  }
}


Node *BST::succ(Node *x) {

  Node *b;

  if (x->right == NULL) {
    return min(x->right);
  }

  b = x->parent;
  while (b!= NULL && x == b->right) {
    x = b;
    b = b->parent;
  }

  return b;
}


Node *BST::min(Node *b) {
  while (b->left != NULL) {
    b = b->left;
  }
  return b;
}


Node *BST::max(Node *a) {
  while (a-> right != NULL) {
    a = a-> right;
  }

  return a;
}


Node *BST::search(int n) {

  Node* x = root;

  while (x != NULL & n != x->val) {
    if (n < x->val) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  return x;
}

void BST::Print(travOrder ord) {
  if(ord==inOrder)
    in_order(root);
  else if(ord==preOrder)
    pre_order(root);
  else if(ord==postOrder)
    post_order(root);
}


void BST::pre_order(Node *a) {

  if (a != NULL) {
    cout << a-> val << endl;
    pre_order(a->left);
    pre_order(a->right);
  }
}

void BST::post_order(Node *b) {

  if (b != NULL) {
    post_order(b->left);
    post_order(b->right);
    cout << b->val << endl;
  }
}

void BST::in_order(Node *c) {

  if (c != NULL) {
    in_order(c->left);
    cout << c->val << endl;
    in_order (c-> right);
  }
}












int main(int argc,char **argv) {

 
  BST x;


  char line[100];


  while (std::cin.getline(line,100))
  {
    string str(line);
    if ( str.size()==0 ) {
	continue;
	}
    
    
    if ( str[0]=='e' ){
	return 1;
	}


    if ( str[0]=='o' ){
	      if ( str.substr(0,3)=="oin" ){
	        x.Print(BST::inOrder);
	      }
	      
		  else if ( str.substr(0,4)=="opre" ){
	        x.Print ( BST::preOrder );
	      }
	      
		  else if (str.substr(0,5) == "opost"){
	        x.Print(BST::postOrder);
	      }
	      
      
     }
	else{ 
	
	
	int key;
       stringstream convert_stm(str.substr(1,str.size()-1));
       if ( !(convert_stm>>key) ) key = -1;

       if (str.substr(0,1) == "i") x.Insert(key);
       else
       if (str.substr(0,1) == "d") x.Delete(key);
	 }
  }

  return 1;
}

