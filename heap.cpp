#include <iostream>
#include <vector>

using namespace std;

void swap(int *i, int *j){
  int temp = *j;
  *j = *i;
  *i = temp;
}

void heapify(vector<int> &hp, int i) {
  int size = hp.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if((l < size) && (hp[l] > hp[largest])){
    largest = l;
    cout << "L -> " << largest << endl;
  }
  if((r < size)&&(hp[r] > hp[largest])){
    largest = r;
    cout << "R -> " << largest << endl;
  }

  if(largest != i){
    cout << "HP -> " << hp[i] << " largest -> " << hp[largest] << endl ;
    swap(&hp[i], &hp[largest]);
    heapify(hp, largest);
  }
}

void insert(vector<int> &v, int value) {
  int size = v.size();
  v.push_back(value);

  if(size != 0){
    for(int i = size/2-1; i>=0; i--){
      heapify(v,i);
    }
  }
}

void deleteNode(vector<int> &v,int value){
  int size = v.size();
  int i{};
  for(; i<size;i++){
    if(v[i] == value){
      swap(&v[i], &v[size-1]);
      break;
    }
  }

  v.pop_back();
  for(i=0;i< size/2-1;i++){
    heapify(v,i);
  }
}

void printArray(vector<int> &v){
  cout << "Vector : ";
  for(int i{}; i < v.size(); i++){
    cout << v[i] << " " ;
  }
}

int main() {
  vector<int> v;

  insert(v,1);
  insert(v,3);
  insert(v,2);
  insert(v,4);
  insert(v,5);
  printArray(v);
  deleteNode(v,5);

  printArray(v);
  return 0;
}