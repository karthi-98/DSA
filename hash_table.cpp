#include<iostream>
#include <list>

using namespace std;

class HashTable {
  int capacity;
  list<int> *table;

  public:
    HashTable(int size);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int hashFunction(int key);
    void displayHash();
};

HashTable::HashTable(int size){
  capacity = size;
  table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data){
  int index = hashFunction(key);
  table[index].push_back(data);
}

void HashTable::displayHash() {
  for(int i{};i<capacity;i++){
    cout << "Table[" << i << "] : ";
    for(auto x:table[i]){
      cout << " --> " << x << " ";
    }
    cout << endl;
  }
}

void HashTable::deleteItem(int key){
  int index = hashFunction(key);

  list<int>::iterator itr = table[index].begin();
  for(; itr != table[index].end();itr++){
    if(*itr == key){
      break;
    }

    if(itr != table[index].end()){
      table[index].erase(itr);
    }

  }
}

int HashTable::hashFunction(int key) {
  return (key % capacity);
}

int main() {
  int key[] = {230, 321, 212, 222, 323, 434, 265};
  int data[] = {123, 432, 523, 43, 32, 423, 111};

  int size = sizeof(key)/sizeof(key[0]);
  HashTable h(10);

  for(int i{};i<size;i++){
    h.insertItem(key[i],data[i]);
  }
  h.displayHash();
  h.deleteItem(212);
  h.displayHash();

  return 0;
}