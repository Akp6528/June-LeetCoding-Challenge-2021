class Solution {
public:
    int find(vector<int> &nums,int k){
        int s = 0;
        int i = 0;
        int n=nums.size();
        while (i < n) {
            if (nums[i] > k) {
                i++;
                continue;
            }
            int count = 0;
            while (i < n && nums[i] <= k) {
                i++;
                count++;
            }
            s += ((count * (count + 1)) / 2);
        }
        return s;
    }    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int ans=0;
        int cnt=0;
        return find(nums,right)-find(nums,left-1); 
    }
};
