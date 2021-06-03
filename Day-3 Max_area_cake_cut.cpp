#define mod 1000000007
class Solution {
public:
    int area(int l, vector<int>& v) {
     
        sort(v.begin(), v.end());
        
        int diff = v[0];
        
        for (int i = 1; i < v.size(); i++)
            diff = max(diff, v[i]-v[i-1]);
        
        diff = max(diff, l - v.back());
        return diff;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        return (long)area(h, horizontalCuts) * area(w, verticalCuts) % mod;
    }
};