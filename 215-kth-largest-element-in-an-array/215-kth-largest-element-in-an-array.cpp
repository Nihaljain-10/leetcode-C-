class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int left = 0, right = nums.size() - 1, kth;
    while (1) {
        int idx = partition(nums, left, right);
        if (idx == k - 1) {
            kth = nums[idx];
            break;
        }
        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
    }
        int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left] ;
    int l = left + 1 ;
    int r = right;
    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot) {
            swap(nums[l], nums[r]);
            l++ ;
            r-- ;
        }
        if (nums[l] >= pivot) {
            l++;
        }
        if (nums[r] <= pivot) {
            r--;
        }
    }
    swap(nums[left], nums[r]);
    return r;
}
};