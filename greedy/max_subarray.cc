#include <iostream>
#include <vector>

using namespace std;

int max_subarray_kadane(vector<int> A) {
  int maxNum = 0;
  int sum = 0;
  for (int i = 0; i < A.size(); i++) {
    sum += A[i];
    if (sum > maxNum) maxNum = sum;
    if (sum < 0)
      //当sum<0时，最大和连续子数组要么在A[0,...,i-1]中，要么在A[i+1,...,n-1]中。
      sum = 0;  //令sum=0,接下x3来求A[i+1,...,n-1]的最大和连续子数组
  }
  return maxNum;
}

int max_subarray_dp(vector<int> A) {
  int max = 0, sum = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sum > 0)    // b[i-1]>0
      sum += A[i];  // b[i]=b[i-1]+a[i];
    else            // b[i-1]=0
      sum = A[i];   // b[i]=a[i]
    if (sum > max) max = sum;
  }
  return max;
}

int main() {
  vector<int> A = {-2, 1, 8, -4, -1, 16, -5, 0};
  cout << max_subarray_kadane(A) << endl;
  cout << max_subarray_dp(A) << endl;
}
