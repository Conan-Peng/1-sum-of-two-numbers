class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //用递归的方法，对每个子数组递归查找当前值是否应该加入该子数组，直到完成k个子数组返回true
        if (nums.empty()) return false;
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum%k) return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum/k, 0, 0, visited);
    }
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited){
        if (k == 1) return true;
        if (curSum == target) return helper(nums, k-1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); i++)
        {
            if (visited[i]) continue;
            visited[i] = true;
            if (helper(nums, k, target, i+1, curSum + nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};
