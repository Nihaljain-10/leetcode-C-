class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,n=s.size()-1,cnt=0;
            unordered_map<char,int>m;
            while(r<=n){
                  m[s[r]]++;
                    while(m['a']&&m['b']&&m['c']){
                         cnt+=n-r+1;
                            m[s[l]]--;
                            l++;
                    }
                    r++;
            }
            return cnt;
    }
};