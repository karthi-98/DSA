#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 5

class Dequeue {
    int items[MAX],front,rear;
  public:

    Dequeue() {
      front = -1;
      rear = -1;
    }

    bool isFull();
    bool isEmpty();
    void addFront();
    void addRear();
    void delFront();
    void delRear();
    void getFront();
    void getRear();
    void display();
};

bool Dequeue::isFull() {
  return ((front == 0 && rear == MAX - 1) || (front == rear + 1));

}

bool Dequeue::isEmpty() {
  return (front == -1);
}

int getInput(){
  int item;
  cout << "\nEnter Num to add : ";
  cin >> item;
  return item;
}


void Dequeue::addFront() {
    if(isFull()){
      cout << "Queue is full";
    }else {
      int num = getInput();
      if( front == -1 ){
        front = 0;
        rear = 0;
      }
      else if (front == 0 ) {
        front = MAX - 1;
      }else {
        front = front - 1;
      }

      items[front] = num;
    }
}

void Dequeue::addRear() {
  if(isFull()){
    cout << "Queue is full";
  }
  else {
    int num = getInput();
    if(front == -1 ){
      front = 0;
      rear = 0;
    }else if (rear == MAX - 1 ) {
      rear = 0;
    }else {
      rear = rear + 1;
    }
    items[rear] = num;
  }
}

void Dequeue::delFront() {
  if(isEmpty()){
    cout << "Queue is Empty";
  }else {
    cout << "Item " << items[front] << " got deleted.";
    if(front == rear) {
      front = -1;
      rear = -1;
    }else if (front == MAX - 1){
      front = 0;
    }else {
      front = front + 1;
    }
  }
}

void Dequeue::delRear() {
  if(isEmpty()) {
    cout << "Queue is Empty";
  }else {
    cout << "Item " << items[rear] << " got deleted.";
    if(rear == front){
      front = -1;
      rear = -1;
    }else if(rear == 0) {
      rear = MAX - 1;
    }else {
      rear = rear - 1;
    }
  }
}

void Dequeue::getFront() {
  if(front == -1){
    cout << "Queue is empty";
  }else {
    cout << "Front element is " << items[front];
  }
}

void Dequeue::getRear() {
  if(rear == -1){
    cout << "Queue is empty";
  }else {
    cout << "Rear element is " << items[rear];
  }
}

void Dequeue::display(){
  if(isEmpty()){
    cout << "Queue is Empty";
  }else {
    cout << "Queue : ";
    int i;
    for(i = front; i != rear; i=(i+1) % MAX){
      cout << items[i] << " ";
    }
    cout << items[i];
  }
}



int main() {
  Dequeue q;
  bool check = true;
  do{
    int choice;
    cout << "\n1.Add Front\n2.Add Rear\n3.Del Front\n4.Del Rear\n5.Display\n6.Get Front\n7.Get Rear\n8.Exit";
    cout << "\nEnter your choice : ";
    cin >> choice;

    switch(choice) {
      case 1: q.addFront(); break;
      case 2: q.addRear(); break;
      case 3: q.delFront(); break;
      case 4: q.delRear(); break;
      case 5: q.display(); break;
      case 6: q.getFront(); break;
      case 7: q.getRear(); break;
      case 8 : check = false; break;
      default: break;
    }
  }while(check);

  return 0;
}

 