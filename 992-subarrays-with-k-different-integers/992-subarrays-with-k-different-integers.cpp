class Solution {
public:
   int subarraywithatmostbdistinct(vector<int> &nums,int b)
{
    int i=0,j=0,cnt=0,n=nums.size();
    unordered_map<int,int> mp;
    while(j<n)
    {
        mp[nums[j]]++;
        while(mp.size()>b)
        {
            mp[nums[i]]--;
           if(mp[nums[i]]==0)
                   mp.erase(nums[i]);
            i++;
        }
        cnt+=j-i+1;
        
        j++;
    }
    
    return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    
    return subarraywithatmostbdistinct(nums,k)-subarraywithatmostbdistinct(nums,k-1);
    
}
};