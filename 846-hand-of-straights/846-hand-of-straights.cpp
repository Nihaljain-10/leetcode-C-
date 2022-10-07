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
        for(int i=val;i<val+groupSize;i++){
            if(map.find(i)==map.end())
                return false;
            
            map[i]--;
            if(map[i]==0)
            {
                if(i!= pq.top())
                    return false;
                pq.pop();
            }
        }
    }
    return true;
    }
};