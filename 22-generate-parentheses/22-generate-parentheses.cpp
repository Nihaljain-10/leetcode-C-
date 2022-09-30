class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
         sub(ans,n,0,0,"");
            return ans;
    }
        void sub(vector<string> &ans,int n,int open,int close,string temp){
                if(temp.size()==n*2){
                        ans.push_back(temp);
                        return;
                }
                if(open<n)
                        sub(ans,n,open+1,close,temp+"(");
                if(close<open)
                        sub(ans,n,open,close+1,temp+")");
        }
};