class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
         vector<string> temp;
            sub(s,ans,temp,0);
            return ans;
    }
        void sub(string s, vector<vector<string>> &ans, vector<string> &temp,int index){
                if(index==s.size())
                        ans.push_back(temp);
                for(int i=index;i<s.size();i++){
                    if(ispalindrome(s,index,i)){
                        temp.push_back(s.substr(index,i-index+1));
                         sub(s,ans,temp,i+1);
                         temp.pop_back();
                    }
                }
        }
        bool ispalindrome(string s,int start,int end){
                while(start<=end){
                        if(s[start++]!=s[end--])
                                return false;
                }
                return true;      
        }
};