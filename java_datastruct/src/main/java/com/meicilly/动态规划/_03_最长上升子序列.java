package com.meicilly.动态规划;

public class _03_最长上升子序列 {
    /**
     * 假设数组是 nums， [10, 2, 2, 5, 1, 7, 101, 18]
     * dp(i) 是以 nums[i] 结尾的最长上升子序列的长度，i ∈ [0, nums.length)
     * 当nums[0] 10  结尾最长的上升子序列是 10 所以dp(0) = 1
     * 当nums[1] 2   结尾最长的上升子序列是 2 所以dp(1) = 1
     * 当nums[2] 2   结尾最长的上升子序列是 2 所以dp(2) = 1
     * 当nums[3] 5   结尾最长的上升子序列是 2 5 所以dp(3) = dp(1) + 1 = dp(2) + 1 = 2
     * 当nums[4] 1   结尾最长的上升子序列是 1  所以dp(4) = 1
     * 当nums[5] 7   结尾最长的上升子序列是 2 5 7 所以dp(5) = dp(3) + 1 = 3
     * 当nums[6] 101 结尾最长的上升子序列是 2 5 7 101 所以dp(6) = dp(5) + 1 = 4
     * 当nums[7] 18  结尾最长的上升子序列是 2 5 7 18  所以dp(7) = dp(5) +1 = 4
     *
     * 当nums[i] > nums[j]
     * nums[i]可以接在nums[j]的后面 长度是dp(j) + 1
     * 当nums[i] <= nums[j]
     * 跳过这次遍历
     *
     * @param nums
     * @return
     */
    public static int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0 )return 0;
        int[] dp = new int[nums.length];
        int max = dp[0] = 1;
        for(int i = 1;i < dp.length;i++){
            dp[i] = 1;
            for(int j = 0;j < i;j++){
                if(nums[i] <= nums[j]) continue;
                dp[i] = Math.max(dp[i],dp[j] + 1);
            }
            max = Math.max(dp[i],max);
        }
        return max;
    }

    public static void main(String[] args) {
        lengthOfLIS(new int[]{10, 2, 2, 5, 1, 7, 101, 18});
    }
}
