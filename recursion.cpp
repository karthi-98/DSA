#include <iostream>
using namespace std;


int factorial(int n){
  if(n > 1) {
    return n * factorial(n - 1);
  }else {
    return 1;
  }
}

int main () {
  int result, n;
  cout << "Enter Input : ";
  cin >> n;
  result = factorial(n);
  cout << "Factorial of given number is : " << result;
  return 0;
}