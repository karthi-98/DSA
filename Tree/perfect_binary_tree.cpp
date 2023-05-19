#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *left,*right;
};

int findDepth(struct Node *node){
  int d = 0;
  while(node!=NULL){
    d++;
    node = node->left;
  }

  return d;
}

bool isPerfectR(struct Node *node, int depth, int level = 0) {
  if(node == NULL ){
    return true;
  }

  if(node->left == NULL && node->right == NULL ){
    return (depth==level+1);
  }
  if(node->left == NULL || node->right == NULL){
    return false;
  }

  return (isPerfectR(node->left,depth,level+1) && (isPerfectR(node->right,depth,level+1)));
}

bool isPerfect(struct Node *node){
  int depth = findDepth(node);
  return isPerfectR(node, depth);

}

struct Node* createNode(int data){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->left = newNode->right = NULL;

  return newNode;
}


int main() {
  struct Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  

  if(isPerfect(root)){
    cout << "Perfect Binary Tree";
  }else {
    cout << "Not a perfect Binary tree";
  }



  return 0;
}