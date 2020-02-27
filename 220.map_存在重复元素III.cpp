class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //用两个快慢指针来”维护“一个索引之间距离小于k的范围
        //判断这个范围内有没有两个元素的差的绝对值小于等于t的情况，可以通过map数据结构的lower_bound操作来实现
        //由于差值绝对值为t，可以在一个一维坐标上来看，使当前元素回退t，即nums[i]-t，当map中的其他数比该位置还要靠左时，一定不满足距离小于t的条件，这时候只需选相对于该位置的lower_bound判断是否为合题元素即可。
        map<long, int> m;
        int j = 0;//慢指针
        for (int i = 0; i < nums.size(); i++)
        {
            if (i - j > k) m.erase(nums[j++]);//维护一个范围小于等于k的map
            auto a = m.lower_bound((long)nums[i] - t);
            if (a != m.end() && abs(nums[i] - a->first) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
