#include <iostream>

using namespace std;

void print_array(int num[], int size) {
  for(int i = 0;i<size;++i){
    cout << num[i] << " ";   
  }
}

void Bubble_Sort(int num[], int size) {
  for(int i = 0; i < size ;i++){
    for(int j = 0; j < size -1; j++ ){
      if(num[j] > num[j+1]){
        int temp = num[j];
        num[j] = num[j+1];
        num[j+1] = temp;
      }
    }
  }
}


int main() {
  int num[] = {5,4,3,2,1};
  int size = sizeof(num) / sizeof(num[0]);
  Bubble_Sort(num,size);
  print_array(num,size);
  return 0;
}