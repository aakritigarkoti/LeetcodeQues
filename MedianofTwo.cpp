Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

  class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size() + nums2.size();
        int merged[n];
        int mid = n/2;
        double median;
        int i = 0, j = 0, k = 0;
        int count = 0, curr;
        while(count<n){
            if(i<nums1.size() and j<nums2.size()){
                if(nums1[i]<=nums2[j]){
                    curr = nums1[i++];
                }
                else{
                    curr = nums2[j++];
                }
            }
            else if(i<nums1.size()){
                curr = nums1[i++];
            }
            else{
                curr = nums2[j++];
            }
            merged[k++] = curr;
            count++;
        }
        if(n%2==0){
            median = merged[mid] + merged[mid-1];
            median /= 2;
        }
        else{
            median = merged[mid];
        }
        return median; 
    }
};
