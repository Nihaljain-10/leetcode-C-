class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
           int n=stones.size();
            for(int i=0;i<n;i++)
                    pq.push(stones[i]);
            int first,second;
            while(n>1){
                   first=pq.top();
                    pq.pop();
                    second=pq.top();
                    pq.pop();
                    n-=2;
                    if((first-second)>0){
                            pq.push(first-second);
                            n++;
                    }
            }
            if(!pq.empty())
                    return pq.top();
            return 0;
                
            
    }
};