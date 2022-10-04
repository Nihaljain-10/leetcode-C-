class Solution {
public:
    string minWindow(string s, string t) {
          if(t=="")
                return "";
            unordered_map<char,int>um;
            for(int i=0;i<t.length();i++){
                    um[t[i]]++;
            }
            int need=um.size();
             unordered_map<char,int>window;
            int i=0,j=0,have=0;
            int minlen=INT_MAX;
            int minpos=-1;
            char c;
            string ans="";
            for(j=0;j<s.length();j++){
                    c=s[j];
                    window[c]++;
                    if(um.find(c)!=um.end()&&window[c]==um[c]){
                            have++;
                    }
                    while(have==need){
                            if(j-i+1<minlen){
                                    minlen=j-i+1;
                                    minpos=i;
                            }
                    
                    window[s[i]]--;
                 if(um.find(s[i])!=um.end()&&window[s[i]]<um[s[i]]){
                         have--;
                    }
                     i++;
                    }
            }
            if(minlen<INT_MAX){
                    ans=s.substr(minpos,minlen);
            }
            else{
                    return "";
            }
            return ans;
    
    }
};