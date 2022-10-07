class Solution {
public:
    bool checkValidString(string s) {
        int leftmax=0,leftmin=0;
            for(char c:s){
                    if(c=='('){
                            leftmax++;
                            leftmin++;
                    }
                    else if(c==')'){
                            leftmax--;
                            leftmin--;
                    }
                    else{
                            leftmin--;
                            leftmax++;
                    }
                            if(leftmax<0)
                                    return false;
                            if(leftmin<0)
                                    leftmin=0;
                    
            }
            return leftmin==0;
    }
};