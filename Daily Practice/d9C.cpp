class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)   return true;
        if (nums[0] == 0)   return false;
        
        int steps = nums[0];
        for (int i = 0; i < nums.size() - 1; i++){
            steps = std::max(steps, nums[i]);
            if (steps == 0) return false;
            steps -= 1;
        }
        return true;
    }
};
