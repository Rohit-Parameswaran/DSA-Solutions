class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        int i=0;
        while(i != slow) {
            i = nums[i];
            slow = nums[slow];
        }

        return i;
    }
};
