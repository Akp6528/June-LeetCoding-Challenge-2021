class Solution {
public:
    
    void explo(vector<vector<int>>& grid, int i, int j, int &cnt) {
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        
        grid[i][j] = 0 ;  // mark the cell as visited
        cnt++;
        
        explo(grid, i-1, j, cnt);
        explo(grid, i, j-1, cnt);
        explo(grid, i+1, j, cnt);
        explo(grid, i, j+1, cnt);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();

        int max_area = 0;
        
        for(int i=0; i<r; i++) {
            
            for(int j=0; j<c; j++) {
                int cnt = 0;
                if(grid[i][j] == 1) {
                    explo(grid, i, j, cnt);
                    max_area = max(max_area, cnt);
                }
            }
        }
    return max_area;
    }
};
