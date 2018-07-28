#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int a[5];
int b[5];
int t[5];
int n;
int sum;
int trans(int i){
	if(i <= 0){i += n; return i;}
	if(i > n){i -= n; return i;}
	return i;
}
void rrepeat(int m) {
  for (int i = a[m] - 2; i <= a[m] + 2; i++) {
    int k = trans(i);
    for (int j = b[m] - 2; j <= b[m] + 2; j++) {
      int q = trans(j);
      if (k == q) {
        t[m]++;
      }
    }
  }
}
int main() {
  memset(a, 0, 5);
  memset(b, 0, 5);
  memset(t, 0, 5);
  cin >> n;
  cin >> a[1] >> a[2] >> a[3];
  cin >> b[1] >> b[2] >> b[3];
  sum = 250;
  if(n>=5){
    rrepeat(1);
    rrepeat(2);
    rrepeat(3);
    sum -= t[1]*t[2]*t[3];
    cout<<sum<<endl;
    return 0;    
  }
  else{
    cout<<n*n*n<<endl; 
    return 0;
  }
}