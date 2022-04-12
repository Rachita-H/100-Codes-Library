#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   string shortestCommonSupersequence(string str1, string str2){
      string s3 = getLCS(str1, str2);
      string ret = "";
      int i = 0;
      int j = 0;
      int k = 0;
      while (k < s3.size()) {
         if (i < str1.size() && str1[i] != s3[k]) {
            ret += str1[i];
            i++;
            continue;
         }
         if (j < str2.size() && str2[j] != s3[k]) {
            ret += str2[j];
            j++;
            continue;
         }
         ret += s3[k];
         k++;
         i++;
         j++;
      }
      while (i < str1.size()) {
         ret += str1[i];
         i++;
      }
      while (j < str2.size()) {
         ret += str2[j];
         j++;
      }
      return ret;
   }
   string getLCS(string s1, string s2){
      string ret = "";
      int n = s1.size();
      int m = s2.size();
      vector<vector<int> > dp(n + 1, vector<int>(m + 1));
      int i = n;
      int j = m;
      s1 = " " + s1;
      s2 = " " + s2;
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) {
               dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
         }
      }
      while (i && j) {
         if (dp[i][j] == dp[i - 1][j]) {
            i--;
            continue;
         }
         if (dp[i][j] == dp[i][j - 1]) {
            j--;
            continue;
         }
         ret += s1[i];
         i--;
         j--;
      }
      reverse(ret.begin(), ret.end());
      return ret;
   }
};
main(){
   Solution ob;
   cout << (ob.shortestCommonSupersequence("acab", "bac"));
}
