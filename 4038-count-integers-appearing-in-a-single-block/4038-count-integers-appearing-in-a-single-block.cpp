class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> seen;
        unordered_set<int> invalid;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                seen[nums[i - 1]] = 1;
            }

            if (seen.count(nums[i])) {
                invalid.insert(nums[i]);
            }
        }

        unordered_set<int> distinct;

        for (int x : nums) {
            distinct.insert(x);
        }

        for (int x : distinct) {
            if (!invalid.count(x)) {
                ans++;
            }
        }

        return ans;
    }
};
// class Solution {
// public:
//     int countSpecialIntegers(vector<int>& nums) {
//         int n=nums.size(); // ek qn me maine length kara tha
//         int ans=0;
//         for(int i=1; i<n;i++){
//             if(nums[i-1]==nums[i]){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };