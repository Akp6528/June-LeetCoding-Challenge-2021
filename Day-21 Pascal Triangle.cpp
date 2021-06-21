 class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>res;
        vector<int> v;
        if(numRows == 0) 
            return res;
        int row = 0;
        v.push_back(1);
        res.push_back(v);
        
        for(int i=0; i<numRows-1; i++) {
            int col = res[row].size();
            vector<int> v;
            v.push_back(1);
            
            for(int j=0; j<col-1; j++) {
                v.push_back(res[row][j] + res[row][j+1]);                
            }
            v.push_back(1);
            res.push_back(v);
            row++;
        }
        return res;
    }
};
