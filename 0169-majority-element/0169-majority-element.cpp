class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxVal=INT_MIN;
        int ans;
        for(int i : nums)
        {
            m[i]++;
        }
        for(auto i :m)
        {
            if(i.second>maxVal)
            {
                maxVal=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};