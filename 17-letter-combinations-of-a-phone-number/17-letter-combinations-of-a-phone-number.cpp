class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
            if(digits.length()==0)
                    return ans;
            string output="";
            string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            solve(digits,ans,output,0,mapping);
                    return ans;
    }
        void solve(string digits,vector<string> &ans,string output,int index,string mapping[]){
                if(index>=digits.length()){
                        ans.push_back(output);
                        return;
                }
                int number=digits[index]-'0';
                string value=mapping[number];
                for(int i=0;i<value.length();i++){
                        output.push_back(value[i]);
                        solve(digits,ans,output,index+1,mapping);
                        output.pop_back();
                }          
        }
};