#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
// Description: A brilliant approach I learned in Algo II
// Approach: Inversion count at each recursive step is the question: How many elements are on your left that is greater than you?
// Important Detail: We do not count the inversion of left half of that recursions' merge. 
// The reason for that is, it is already calculated by a previous call.
// An alternative approach is BIT with coordinate compression which is still o(nlogn) time but o(n) space.

class Solution {
    public:
    int merge(vector<int>& nums, int l, int m, int r) {
        vector<int> left = vector<int>(nums.begin()+l, nums.begin()+m+1);
        vector<int> right = vector<int>(nums.begin()+m+1, nums.begin()+r+1);
        int inversionCount = 0;
        left.push_back(INT_MAX);
        right.push_back(INT_MAX);
        int p1 = 0;
        int p2 = 0;
        while(p1 < left.size()-1 || p2 < right.size()-1) {
            if(left[p1] <= right[p2]) {
                nums[l+p1+p2] = left[p1]; 
                p1++;
            } else {
                inversionCount += m-l+1-p1;
                nums[l+p1+p2] = right[p2];
                p2++;
            }
        }
        return inversionCount;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return 0; // already sorted
        int m = l + (r-l)/2;
        int ans = 0;
        ans += mergeSort(nums, l, m);
        ans += mergeSort(nums, m+1, r);

        ans += merge(nums, l, m, r);
        return ans;
    }

    int countInversions(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,3,8,1,4};
    cout << s.countInversions(nums);
    return 0;
}