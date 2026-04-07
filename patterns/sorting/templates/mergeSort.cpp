#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>

class MergeSort {
    public:
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> left = vector<int>(nums.begin()+l, nums.begin()+m+1);
        vector<int> right = vector<int>(nums.begin()+m+1, nums.begin()+r+1);
        left.push_back(INT_MAX);
        right.push_back(INT_MAX);
        int p1 = 0;
        int p2 = 0;
        while(p1 < left.size()-1 || p2 < right.size()-1) {
            if(left[p1] <= right[p2]) {
                nums[l+p1+p2] = left[p1]; 
                p1++;
            } else {
                nums[l+p1+p2] = right[p2];
                p2++;
            }
        }

    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return; // already sorted
        int m = l + (r-l)/2;

        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);

        merge(nums, l, m, r);
    }
};

int main() {
    MergeSort s;
    vector<int> nums = {1,2,3,6,5,4};
    s.mergeSort(nums, 0, nums.size()-1);
    for(int n: nums) cout << n << " ";
    return 0;
}