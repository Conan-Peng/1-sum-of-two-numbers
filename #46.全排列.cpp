class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp(nums);
        if (nums.empty()) return res;
        backtrack(nums, 0, res, temp);
        return res;
    }
    void backtrack(vector<int> nums, int cur, vector<vector<int> >& res, vector<int>& temp)
    {
        int n = nums.size();
        if (cur == n) 
        {
            res.push_back(temp);
            return;
        }       
        for (int i = 0; i < n; i++)
        {
            if (!isValid(nums, cur, i, temp)) continue;
            temp[cur] = nums[i];
            backtrack(nums, cur + 1, res, temp);
            temp[cur] = nums[cur];
        }
    }
    bool isValid(vector<int> nums, int cur, int i, vector<int> temp)
    {
        if (cur == 0) return true;
        for (int k = 0; k < cur; k++)
        {
           if (temp[k] == nums[i]) return false;
        }
        return true;
    }
};
