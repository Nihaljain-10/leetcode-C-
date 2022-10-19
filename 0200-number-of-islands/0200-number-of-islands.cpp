class Solution {
public:
    void bfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
	    //for neighbouring elements or cell.
	    //you could use direct indexes too :)
            for(int del_row=-1;del_row<=1;del_row++){
                for(int del_col=-1;del_col<=1;del_col++){
		    //not to check the diagonal elements.
                    if((del_row==-1&&del_col==-1) || (del_row==-1&&del_col==1) || (del_row==1&&del_col==-1) || (del_row==1&&del_col==1)){
                        continue;
                    }
                    int nrow=row+del_row;
                    int ncol=col+del_col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size(), cnt=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(row,col,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};