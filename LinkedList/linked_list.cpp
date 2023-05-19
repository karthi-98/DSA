#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

void insertAtStart(struct Node** head ){

  int num;
  cout << "\nEnter number to add : ";
  cin >> num;

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->data = num;
  new_node->next = *head;

  *head = new_node;
}

struct Node* searchNode(struct Node* head, int num){
  struct Node* search_node = (struct Node*)malloc(sizeof(struct Node));
  search_node = head;
  while(search_node != NULL) {
    if(search_node->data == num) {
      break;
    }
    search_node  = search_node->next;
  }
  return search_node;
}

void insertAfter(struct Node** head){
  int num;
  cout << "\nEnter number to add after: ";
  cin >> num;

  struct Node* search_node = (struct Node*)malloc(sizeof(struct Node));
  search_node = searchNode(*head,num);
  if(search_node == NULL){
    cout << "\nNumber not found";
    return;
  }

  int new_num;
  cout << "\nEnter New Number to add : ";
  cin >> new_num; 

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_num;
  new_node->next = search_node->next;
  search_node->next = new_node;
  return;
}

void insertAtEnd(struct Node** head) {

  int num;
  cout << "\nEnter number to add : ";
  cin >> num;

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last_node = *head;

  new_node->data = num;
  new_node->next = NULL;

  if(*head == NULL ) {
    *head = new_node;
    return;
  }

  while(last_node->next != NULL) last_node = last_node->next;

  last_node->next = new_node;
  return;
}

void printList(struct Node* head){
  if(head == NULL){
    cout << "\nList is Empty\n";
  }else {
    cout << "\nLinked_List : ";
    while(head != NULL){
     cout << head->data << " ";
      head = head->next;
    }
  }
}

void deleteNode(struct Node* head) {
  printList(head);
  int num;
  cout << "\nEnter number to delete : ";
  cin >> num;

  struct Node* prev_node = (struct Node*)malloc(sizeof(struct Node));
  
  prev_node = head;

  while(prev_node->next->data != num) prev_node = prev_node->next;

  prev_node->next = prev_node->next->next;
}

void sortedLinkedList(struct Node* head) {
  struct Node *head_ref = head, *index = NULL;
  if(head_ref == NULL){
    cout << "\nList is Empty";
    return;
  }
  while(head_ref != NULL) {
    index = head_ref->next;
    while(index != NULL){
      if(head_ref->data > index->data) {
        int temp = head_ref->data;
        head_ref->data = index->data;
        index->data = temp;
      }
      index =  index->next;
    }
    head_ref = head_ref->next;
  }
}

int main () {
  struct Node* head = NULL;
  bool check = true;

  do{
    int choice;
    cout << "\n1.Insert At Beginning\n2.Insert at End\n3.Insert After\n4.Search Node\n5.Delete Node\n6.Print List\n7.Sort List\n8.Exit";
    cout << "\nEnter your choice : ";
    cin >> choice;
    switch(choice) {
      case 1: insertAtStart(&head); break;
      case 2: insertAtEnd(&head); break;
      case 3: insertAfter(&head); break;
      case 4: 
          int num;
          cout << "Enter number to search : ";
          cin >> num;  
          if(searchNode(head,num) == NULL){
            cout << "Node not Present";
          }else {
            cout << "Node is in the List";
          }
          break;
      case 5: deleteNode(head); break;
      case 6: printList(head); break;
      case 7: sortedLinkedList(head); break;
      case 8: check = false; break;
      default: break;
    }
  }while(check);

  return 0;
}
