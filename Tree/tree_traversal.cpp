//Inorder, Preorder and Postorder functions

#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *left, *right;
  Node(int d){
    data = d;
    left = right = NULL;
  }
};

void Inorder(struct Node *node){
  if(node == NULL){
    return;
  }

  Inorder(node->left);
  cout << node->data << " ";
  Inorder(node->right);
}

void Preorder(struct Node *node){
  if(node == NULL){
    return;
  }

  cout << node->data << " ";
  Preorder(node->left);
  Preorder(node->right);
}

void PostOrder(struct Node *node){
  if(node == NULL){
    return;
  }

  PostOrder(node->left);
  PostOrder(node->right);
  cout << node->data << " ";
}


int main() {
  struct Node *node = new Node(1);
  node->left = new Node(2);
  node->right = new Node(3);
  node->left->left = new Node(4);
  node->left->right = new Node(5);

  Inorder(node);
  cout << endl;
  Preorder(node);
  cout << endl;
  PostOrder(node);


  return 0;
}