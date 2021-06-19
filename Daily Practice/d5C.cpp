class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                res = std::min(res, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};
