class Solution {
public:
    string removeKdigits(string num, int k) {
         int n = num.size();
        stack<char> st;
        //Store the final string in stack
        for(char c: num)
        {
            while(!st.empty() && k>0 && st.top()>c)
            {   st.pop();      k-=1;   }
            
            if(!st.empty() || c!='0')
                st.push(c);
        }
        
        //Now remove the largest values from the top of the stack
        while(!st.empty() && k--)
            st.pop();
        if(st.empty())
            return "0";
       string res="";
        while(!st.empty())
        {
           res.push_back(st.top());
            st.pop();
            
        }
            reverse(res.begin(),res.end());
        return res;
    }
};