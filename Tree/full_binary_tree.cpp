#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *left,*right;

  Node(int d){
    data = d;
    left = right = NULL;
  }
};

bool checkFullBinaryTree(struct Node *node) {
  if(node == NULL) {
    return true;
  }
  
  if(node->left == NULL && node->right == NULL){
    return true;
  }

  if((node->left) && (node->right)){
    return (checkFullBinaryTree(node->left) && checkFullBinaryTree(node->right));
  }

  return false;
}

int main() {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);

  if(checkFullBinaryTree(root)){
    cout << "Full Binary Tree";
  }else {
    cout << "Not a Full Binary Tree";

  }
  return 0;
}