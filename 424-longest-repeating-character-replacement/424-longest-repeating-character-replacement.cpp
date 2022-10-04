class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
            int ans=0,maxi=0,l=0,r=0;
            unordered_map<char,int>cnt;
            while(r<n){
                    cnt[s[r]]++;
                    maxi=max(maxi,cnt[s[r]]);
                    while(((r-l+1)-maxi)>k){
                            cnt[s[l]]--;
                            l++;
                    }
                   ans=max(ans,r-l+1);
                    r++;
            }
            return ans;
    }
};