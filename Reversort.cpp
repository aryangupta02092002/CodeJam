#include <bits/stdc++.h>
using namespace std;

int reversort(int a[100], int n) {
  int res = 0;
  for(int i = 1; i<n; i++) {
    int j = int(min_element(a + i - 1, a + n) - a) + 1;
    reverse(a + i - 1, a + j);
    res += (j - i + 1);
  }
  return res;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  int num = 1;
  while(t--) {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++) {
      cin>>a[i];
    }
    cout<<"Case #"<<num<<": "<<reversort(a, n)<<endl;
    num++;
  }

  return 0;
}
