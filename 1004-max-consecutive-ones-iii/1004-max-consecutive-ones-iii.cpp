class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size(),zerocount=0,ans=0;
            while(r<n){
                    if(nums[r]==0)
                            zerocount++;
                    while(zerocount>k){
                            if(nums[l]==0){
                                    zerocount--;
                            }
                            l++;
                    }
                    ans=max(ans,r-l+1);
                    r++;
            }
            return ans;
    }
};