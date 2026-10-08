class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int place = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                // duplicate, ignore
            }
            else {
                nums[place] = nums[i];
                place++;
            }
        }

        return place;
    }
};