class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long runningSum = 0;
        long minSum = 100001;
        long minIndex = 0;
        long leftAverage;
        long rightAverage;
        for (int i = 0; i < nums.size(); i++) {
            totalSum -= nums[i];
            runningSum += nums[i];
            leftAverage = (runningSum / (i + 1));
            if (i != nums.size() - 1) {
                rightAverage = (totalSum / (nums.size() - i - 1));
            } else {
                rightAverage = 0;
            }   
            if (abs(leftAverage - rightAverage) < minSum) {
                // cout << rightAverage << " " << leftAverage << " " << abs(leftAverage - rightAverage) << '\n';
                minSum = abs(leftAverage - rightAverage);
                minIndex = i;
            }
        }

        return minIndex;
    }
};
