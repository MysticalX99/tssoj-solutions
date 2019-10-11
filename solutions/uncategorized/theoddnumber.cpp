#include <iostream>
#define endl '\n'
using namespace std; 
typedef unsigned int ui;

int main() { 
  cin.tie(0);
  cin.sync_with_stdio(0);

  ui n, r = 0;
  cin >> n;

  for(ui i = 0; i < n; i++) {
    int c;
    cin >> c;
    r ^= c;
  }

  cout << r << endl;
  return 0; 
}
