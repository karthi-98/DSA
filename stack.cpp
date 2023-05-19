#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10

int size = 0;

struct stack {
  int items[MAX];
  int top;
};

typedef struct stack st;

int isFull(st *s){
  if(s->top == MAX - 1) {
    return 1;
  }
  else {
    return 0;
  }
}

int isEmpty(st *s){
  if(s->top == -1){
    return 1;
  }else {
    return 0;
  }
}

int createEmptyStack(st *s) {
  s->top = -1;
}

int push(st *s){
  if(isFull(s)){
    cout << "Stack is full";
  }else{
    int item;
    cout << "Enter New Item to push : ";
    cin >> item;
    s->top++;
    s->items[s->top] = item;
    size++;
  }
}

int pop(st *s){
  if(isEmpty(s)){
    cout << "Stack is Empty";
  }else {
    cout << "Item Popped : " << s->items[s->top];
    s->top--; 
    size--;
  }
}

int printStack(st *s){
  cout << "Stack : ";
  for (int i = 0; i < size; i++) {
    cout << s->items[i] << " ";
  } 
}

int main () {
  st *s = (st *)malloc(sizeof(st));
  cout << sizeof(st);
  createEmptyStack(s); 
  int check = true;


  do {
    int choice;
    cout << "\n\n1.Push\n2.Pop\n3.PrintStack\n4.Exit\n\nEnter Choice to continue : ";
    cin >> choice;
    switch(choice) {
      case 1: push(s);break;
      case 2: pop(s);break;
      case 3: printStack(s);break;
      case 4: check = false;break;
      default: break;
    }
  }while(check);

  return 0;
}