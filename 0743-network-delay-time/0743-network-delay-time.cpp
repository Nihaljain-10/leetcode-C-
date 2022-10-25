class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1]; 
        
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX); 
        dist[k]=0;
     
        pq.push(make_pair(0,k));
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            vector<pair<int,int>>::iterator x;
            for(auto x:adj[node]){
                int next=x.first;
                int nextdist=x.second;
                if(dis+nextdist<dist[next]){
                    dist[next]=dis+nextdist;
                    pq.push(make_pair(dist[next],next));
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]!=INT_MAX){
                maxi=max(maxi,dist[i]);
            }
            else{
                maxi=-1;
                break;
            }
        }
        return maxi;
    }
};