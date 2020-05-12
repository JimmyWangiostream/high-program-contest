#include <bits/stdc++.h>
using namespace std;

int n;
//char str[2][3005];
string A,B;
int dp[2][3005];

int main() {
  cin >> n >>A>>B;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) dp[0][j] = dp[1][j];
    for(int j = 0; j < n; j++) {
      if(A[i]==B[j])
        dp[1][j]=dp[0][j-1]+1;
      else
        dp[1][j]=max(dp[0][j],dp[1][j-1]);
    }
  }
  cout << dp[1][n-1] << endl;
  return 0;
}
