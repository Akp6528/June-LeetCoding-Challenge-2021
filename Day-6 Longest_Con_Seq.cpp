class Solution {
public:
    int longestConsecutive(vector<int>& nums) {  
        unordered_set<int> s;
        int n = nums.size();
        int ans = 0;
        
        for(int i=0; i<n; i++) 
            s.insert(nums[i]); 
        
        for(int i=0; i<n; i++) {
            if(s.find(nums[i]-1) != s.end()) 
                continue;
            else {
                int x = nums[i];
                int cnt = 0;
                while(s.find(x) != s.end()){
                    cnt++;
                    x++;
                }
                ans = max(ans, cnt);   
            } 
        }
    return ans;
    }
};