class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int max_nums[n];
        int min_nums[n];
        for(int i=0;i<n;i++) {
            if(i==0) min_nums[i] = nums[i];
            else min_nums[i] = min(nums[i], min_nums[i-1]);
        }
        for(int i=n-1;i>=0;i--) {;
            if(i==n-1) max_nums[i] = nums[i];
            else max_nums[i] = max(nums[i], max_nums[i+1]);
        }
        for(int i=1;i<n-1;i++) {
            if(min_nums[i]<nums[i]&&nums[i]<max_nums[i]) return true;
        }
        return false;
    }
};
