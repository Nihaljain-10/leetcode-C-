class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int xorx=0;
            for(int i=0;i<nums.size();i++){
                xorx=xorx^nums[i];
            }
            return xorx;
    }
};