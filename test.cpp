#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  v.push_back(1);
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(4);

  for(auto x = v.begin(); x!=v.end();x++){
    cout << *x << " ";
  }

  int ans=0;
  for(auto n:v)
    ans^=n;

  cout << "\nAnswer : " << ans;
  return 0;
}
