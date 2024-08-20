#include <bits/stdc++.h>
using namespace std;

// BOTTOM UP APPROACH - TABULATION

int main() {
  /*
   *  Write your code here.
   *  Read input as specified in the question.
   *  Print output as specified in the question.
   */

  int n;
  cin >> n;

  vector<int> dp(n + 1);
  // base case initialization
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n];
  return 0;
}

// TOP DOWN APPROACH - RECURSION + MEMOIZATION

// int fib(int n, vector<int> &dp) {

//   // base case
//   if (n <= 1) {
//     return n;
//   }

// //dp check
//   if (dp[n] != -1) {
//     return dp[n];
//   }

//   // recursive call
//   dp[n] = fib(n - 1 , dp) + fib(n - 2 ,dp);
//   return dp[n];
// }

// int main() {
//   /*
//    *  Write your code here.
//    *  Read input as specified in the question.
//    *  Print output as specified in the question.
//    */

//   int n;
//   cin >> n;

//   vector<int> dp(n + 1);

//   for (int i = 0; i <= n; i++) {
//     dp[i] = -1;
//   }

//   cout << fib(n, dp);
//   return 0;
// }