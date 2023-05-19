#include <iostream>

using namespace std;

struct Node {
  int key;
  struct Node *left;
  struct Node *right;
};

struct Node* createNewNode(int value){
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->key = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

int countIndexTree(struct Node* node) {
  if(node == NULL) {
    return 0;
  }
  
  return(1 + countIndexTree(node->left) + countIndexTree(node->right));
}

bool checkCompleteBinaryTree(struct Node* node, int index, int NodeCount) {
  if(node == NULL) {
    return true;
  }

  if(index >= NodeCount){
    return false;
  }

  return ((checkCompleteBinaryTree(node->left, 2 * index + 1,NodeCount)) && checkCompleteBinaryTree(node->right, 2 * index + 2, NodeCount));
}
  

int main(){

  struct Node *root;
  root = createNewNode(1);
  root->left = createNewNode(2);
  root->right = createNewNode(2);
  root->left->left = createNewNode(3);
  root->right->left = createNewNode(3);
  root->right->right = createNewNode(4);

  int count = countIndexTree(root);
  cout << "Count Value : " << count << endl;

  if(checkCompleteBinaryTree(root,0,count)) {
    cout << "It is a Complete binary tree";
  }else {
    cout << "Not a complete binary tree";
  }
  return 0;
}