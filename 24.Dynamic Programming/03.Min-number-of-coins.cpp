#include <bits/stdc++.h>

//APPROACH 1 = RECURSION + MEMOIZATION

int solveMem(vector<int> &num, vector<int> &dp, int x) {
  // base case
  if (x == 0) {
    return 0;
  }

  if (x < 0) {
    return INT_MAX;
  }

  // dp check
  if (dp[x] != -1) {
    return dp[x];
  }

  int mini = INT_MAX;
  for (int i = 0; i < num.size(); i++) {
    int ans = solveMem(num, dp, x - num[i]);
    if (ans != INT_MAX) {
      mini = min(mini, ans + 1);
    }
  }

  dp[x] = mini;
  return mini;
}

int minimumElements(vector<int> &num, int x) {
  // Write your code here.
  vector<int> dp(x + 1, -1);
  int ans = solveMem(num, dp, x);
  if (ans != INT_MAX) {
    return ans;

  } else {
    return -1;
  }
}#include <bits/stdc++.h>

//APPROACH 1 = RECURSION + MEMOIZATION

int solveMem(vector<int> &num, vector<int> &dp, int x) {
  // base case
  if (x == 0) {
    return 0;
  }

  if (x < 0) {
    return INT_MAX;
  }

  // dp check
  if (dp[x] != -1) {
    return dp[x];
  }

  int mini = INT_MAX;
  for (int i = 0; i < num.size(); i++) {
    int ans = solveMem(num, dp, x - num[i]);
    if (ans != INT_MAX) {
      mini = min(mini, ans + 1);
    }
  }

  dp[x] = mini;
  return mini;
}

int minimumElements(vector<int> &num, int x) {
  // Write your code here.
  vector<int> dp(x + 1, -1);
  int ans = solveMem(num, dp, x);
  if (ans != INT_MAX) {
    return ans;

  } else {
    return -1;
  }
}