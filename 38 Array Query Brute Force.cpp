#include <vector>
#include <iostream>
using namespace std;

void solve(int n, int arr[], int q, int query[]) {
   vector<int> values;
   for(int i = 0; i < n; i++){
      values.push_back(arr[i]);
   }
   for(int i = 0; i < q; i++) {
      int idx = lower_bound (values.begin(), values.end(),
      query[i]) - values.begin();
      if (values[idx] == query[i])
         cout << "Present ";
      else
         cout << "Not present ";
      cout << idx + 1 << endl;
   }
}
int main() {
   int input_arr[] = {1, 2, 3, 4, 7, 9, 12, 15};
   int query_arr[] = {1, 5, 8};
   solve(8, input_arr, 3, query_arr);
   return 0;
}
