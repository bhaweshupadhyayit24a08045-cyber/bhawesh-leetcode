class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        // 1. Both from the front
        int front = maxIndex + 1;

        // 2. Both from the back
        int back = n - minIndex;

        // 3. min from front, max from back
        int both = (minIndex + 1) + (n - maxIndex);

        return min({front, back, both});
    }
};