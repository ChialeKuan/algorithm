#include<iostream>
#include<vector>

using namespace std;

// o(m+n/2)
/*
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>::size_type len1 = nums1.size(), len2 = nums2.size();
    vector<int>::size_type i1 = 0, i2 = 0;
    int tmp1 = 0, tmp2 = 0;
    for (vector<int>::size_type n = 0; n < (len1 + len2) / 2 + 1; n++) {
        tmp1 = tmp2;
        if ((i1 >= len1) || ((i2 < len2) && (nums1[i1] > nums2[i2]))) {
            tmp2 = nums2[i2];
            i2++;
            continue;
        }
        if ((i2 >= len2) || ((i1 < len1) && (nums1[i1] <= nums2[i2]))) {
            tmp2 = nums1[i1];
            i1++;
            continue;
        }
    }
    if ((len1 + len2) % 2 == 0)
        return float(tmp1 + tmp2) / 2;
    else
        return tmp2;
}
*/

// ¶þ·Ö²éÕÒ
// o(log(min(m, n)))
//      A[i-1]      A[i]
//                B[j-1]
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    vector<int>::size_type m = A.size();
    vector<int>::size_type n = B.size();
    if (m > n) { // to ensure m<=n
        vector<int> temp = A; A = B; B = temp;
        vector<int>::size_type tmp = m; m = n; n = tmp;
    }
    vector<int>::size_type iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        vector<int>::size_type i = (iMin + iMax) / 2;
        vector<int>::size_type j = halfLen - i;
        if (i < iMax && A[i] < B[j - 1]) {
            iMin = i + 1; // i is too small
        }
        else if (i > iMin && A[i - 1] > B[j]) {
            iMax = i - 1; // i is too big
        }
        else { // i is perfect
            int maxLeft = 0;
            if (i == 0)
                maxLeft = B[j - 1];
            else if (j == 0)
                maxLeft = A[i - 1];
            else
                maxLeft = (A[i - 1] > B[j - 1]) ? A[i - 1] : B[j - 1];
            if ((m + n) % 2 == 1)  
                return maxLeft; 

            int minRight = 0;
            if (i == m)
                minRight = B[j];
            else if (j == n)
                minRight = A[i];
            else
                minRight = (B[j] < A[i]) ? B[j] : A[i];
            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0.0;
}
void s4() {
    vector<int> a, b;
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    b.push_back(5);
    cout << findMedianSortedArrays(a, b) << endl;
}