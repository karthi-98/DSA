#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 5

class CircularQueue {

  private:
    int items[MAX],front,rear;
  public:
    CircularQueue() {
      front = -1;
      rear = -1;
    }

    bool isFull() {
      if((front == rear + 1) || (rear == MAX - 1 && front == 0)) {
        return true;
      }
      return false;
    }

    bool isEmpty() {
      if(front == -1) {
        return true;
      }
      return false;
    } 

    void enQueue() {
      if(isFull()){
        cout << "\nQueue is Full";
      }else {
        int item;
        cout << "\nEnter number to enQueue : ";
        cin >> item;
        if(front == -1) {
          front++;
        }
        rear = (rear + 1) % MAX;
        items[rear] = item;
      }
    }

    void deQueue () {
      if(isEmpty()) {
        cout << "\nQueue is EMPTY";
      }else {
        cout << "\nDeleted Item : " << items[front];
        if(front == rear) {
          front = -1;rear = -1;
        }
        else {
          front = (front + 1) % MAX;
        }
      }
    }

    void display() {
      cout << "\nFront : " << front << " Rear : " << rear;
      cout << "\nQueue : ";
      if(isEmpty()) {
        cout << "Queue is Empty";
      }else {
        int i;
        for (i = front; i != rear ; i = (i+1)%MAX)
          cout << items[i] << " ";
        cout << items[i];
      }
    }
};

int main(){
  CircularQueue q;
  bool check = true;
  do{
    int choice;
    cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
    cout << "Enter your choice : ";
    cin >> choice;

    switch(choice) {
      case 1: q.enQueue(); break;
      case 2: q.deQueue(); break;
      case 3: q.display(); break;
      case 4: check = false; break;
      default: break;
    }
  }while(check);

  return 0;
}