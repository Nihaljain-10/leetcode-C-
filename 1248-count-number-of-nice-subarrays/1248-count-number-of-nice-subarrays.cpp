class Solution {
public:
    int atmost(vector<int> &nums,int k){
        
        if(k<0)
            return 0;
        int odd=0;
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            
            if(nums[j]%2) odd++;
            while(odd>k){
                if(nums[i]%2){
                    odd--;
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};