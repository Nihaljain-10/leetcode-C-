class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
            vector<int> temp;
            sub(temp,ans,candidates,0,target);
            return ans;
    }
        void sub( vector<int> &temp,vector<vector<int>> &ans,vector<int> &arr,int ind,int target){
             if(ind==arr.size()){
                     if(target==0){
                             ans.push_back(temp);
                     }
                     return;
             }
                if(arr[ind]<=target){
                        temp.push_back(arr[ind]);
                        sub(temp,ans,arr,ind,target-arr[ind]);
                        temp.pop_back();
                }
               
                sub(temp,ans,arr,ind+1,target);       
        }
};