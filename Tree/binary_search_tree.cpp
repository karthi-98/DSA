#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *left, *right;
};

struct Node* newNodeFunc(int newData) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = newData;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void inorder(struct Node* node){
  if(node != NULL){
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }
}

struct Node* insert(struct Node *node , int newData) {
  if(node == NULL){
    return newNodeFunc(newData);
  }

  if(node->data > newData){
    node->left = insert(node->left, newData);
  }else {
    node->right = insert(node->right, newData);
  }

  return node;
}

struct Node* minValueNode(struct Node* root) {
    struct Node* current = root;

    if(current->left != NULL){
      current = current->left;
    }

    return current;
}

struct Node* deleteNode(struct Node* root, int delData){
  if( root == NULL) {
    return root;
  }

  if( root->data > delData) {
    root->left = deleteNode(root->left, delData);
  }else if (root->data < delData) {
    root->right = deleteNode(root->right , delData);
  }else {
    if( root->left == NULL ) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    }else if(root->right == NULL){
      struct Node* temp = root->left;
      free(root);
      return temp;
    }

    struct Node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

int main() {
  struct Node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
  inorder(root);
  cout << endl;
  root = deleteNode(root,6);
  inorder(root);
  return 0;
}