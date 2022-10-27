class Solution {
public:
    vector<int>parent;
    vector<int>size;

    void disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i<=n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUparent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ultPu = findUparent(u);
        int ultPv = findUparent(v);
        if(ultPv == ultPu)
            return;
        if(size[ultPu] < size[ultPv]){ 
            parent[ultPu] = ultPv;
            size[ultPv] += size[ultPu];
        }
        else{
            parent[ultPv] = ultPu;
            size[ultPu] += size[ultPv];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint(n*n);
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int node = i * n + j;
                for(int ind = 0; ind<4; ind++){
                    int nRow = i + delrow[ind];
                    int nCol = j + delcol[ind];
                    if(nRow >=0 && nRow < n && nCol >= 0 && nCol<n){
                        if(grid[nRow][nCol] == 1){
                           int adjNode = nRow * n + nCol;
                           unionBySize(node,adjNode);
                        }
                    }
                }
                
            }
        }
       
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                set<int>s; 
                if(grid[i][j] == 1) continue;
                cnt++;
                int node = i * n + j;
                for(int ind = 0; ind<4; ind++){
                    int nRow = i + delrow[ind];
                    int nCol = j + delcol[ind];
                    if(nRow >=0 && nRow < n && nCol >= 0 && nCol<n){
                        if(grid[nRow][nCol] == 1){
                            int adjNode = nRow * n + nCol;
                            int parent = findUparent(adjNode);
                            s.insert(parent);
                        }
                    }
                }
                int tempans = 0;
                for(auto it : s){
                   tempans+=size[it]; 
                }

                ans = max(ans,tempans+1); 
                
            }
        }
        if(cnt==0)
                return n*n;
        return ans; 
    }
};