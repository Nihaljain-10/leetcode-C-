class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if(hand.size()%groupSize!=0)
        return false;
    
    unordered_map<int,int> map;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto x:hand){
        map[x]++;
    }
    
    for(auto p:map){
        pq.push(p.first);
    }
    
    while(!pq.empty()){
        int val=pq.top();
        for(int i=0;i<groupSize;i++){
            if(map.find(i+val)==map.end())
                return false;
            
            map[i+val]--;
            if(map[i+val]==0)
            {
                if(i+val != pq.top())
                    return false;
                pq.pop();
            }
        }
    }
    return true;
    }
};