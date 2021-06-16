  class Solution {
public:

bool static sortcol(vector<int>& v1, vector<int>& v2 ) 
    {
         return v1[1] < v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        int res = 0;
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        reverse(boxTypes.begin(), boxTypes.end());
        
        int i = 0;
        while(truckSize && i < boxTypes.size())
        {
            int box_no = min(boxTypes[i][0], truckSize);
            res += box_no * boxTypes[i][1];
            i++;
            truckSize -= box_no;
        }
        
        return res;
    }

};
