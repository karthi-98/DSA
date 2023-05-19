#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10

class Queue {
  private:
    int items[MAX];
    int front;
    int end;

  public:
    Queue() {
      front = -1;
      end = -1;
    }

    bool isFull () {
      if ((front == 0) && (end == MAX - 1)) {
        return true;
      }else {
        return false;
      }
    }

    bool isEmpty() {
      if (front == -1) {
        return true;
      }else {
        return false;
      }
    }

    void enQueue() {
      if (isFull()){
        cout << "Queue is Full";
      }else {
        int item;
        cout << "\nEnter number to enqeue : ";
        cin >> item;
        if (front == -1) {
          front++;
        }
        end++;
        items[end] = item;
      }
    }

    void deQueue() {
      if (isEmpty()){
        cout << "Queue is empty";
      }else {
        cout << "Value " << items[front] << " got deleted";
        if(front >= end ) {
          front = -1;
          end = -1;
        }else {
          front++;
        }
      }
    }

    void display() {
      if (isEmpty()) {
        cout << "Queue is Empty";
      }else {
        cout << "Front : " << front << " End : " << end;
        cout << "\nQueue : ";
        for(int i = front;i <= end; i++){
          cout << items[i] << " ";
        }
      }
    }
};

int main () {
  Queue q;
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