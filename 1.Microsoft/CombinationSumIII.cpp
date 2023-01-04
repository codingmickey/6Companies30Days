class Solution {
public:

    void combinationSum(vector<vector<int>> &ans, vector<int> current, int n, int k, int i) {
        auto sum = 0;
        for(auto x:current) sum += x;

        if(k==0 && sum == n) {
            ans.push_back(current);
            return;
        }
        if (i>9) return;
        
        current.push_back(i);
        combinationSum(ans, current, n, k-1, i+1);
        current.pop_back();
        combinationSum(ans, current, n, k, i+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;

        combinationSum(ans, current, n, k, 1);
        return ans;
    }
};
