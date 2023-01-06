class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int curMax = INT_MIN;
        int pro = 0, sum = 0;
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size(); i++) {
            pro += nums[i] * i;
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            curMax = pro > curMax ? pro : curMax;
            pro += (-(nums.size() -1) * nums[nums.size() - i - 1]);
            pro += (sum - nums[nums.size() - i - 1]);
        }
        return curMax;
    }
};
