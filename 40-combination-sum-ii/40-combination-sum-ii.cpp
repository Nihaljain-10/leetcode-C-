class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
            sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
            vector<int> temp;
            sub(candidates,ans,temp,0,target);
            return ans;
    }
        void sub(vector<int> &arr,vector<vector<int>> &ans,vector<int> &temp,int ind,int target){
        if(target==0){
                ans.push_back(temp);
                return;
        }
                
        for(int i=ind;i<arr.size();i++){
                if(i>ind && arr[i]==arr[i-1])
                        continue;
                if(arr[i]>target)
                        break;
                temp.push_back(arr[i]);
                sub(arr,ans,temp,i+1,target-arr[i]);
                temp.pop_back();        
        }
        }
};