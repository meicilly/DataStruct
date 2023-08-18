package com.meicilly.动态规划;

public class _02_最大连续子序列和 {
    /**
     * 比如 –2、1、–3、4、–1、2、1、–5、4 的最大连续子序列和是 4 + (–1) + 2 + 1 = 6
     *  状态定义
     * 假设 dp(i) 是以 nums[i] 结尾的最大连续子序列和（nums是整个序列）
     * ✓ 以 nums[0] –2 结尾的最大连续子序列是 –2，所以 dp(0) = –2
     * ✓ 以 nums[1] 1 结尾的最大连续子序列是 1，所以 dp(1) = 1
     * ✓ 以 nums[2] –3 结尾的最大连续子序列是 1、–3，所以 dp(2) = dp(1) + (–3) = –2
     * ✓ 以 nums[3] 4 结尾的最大连续子序列是 4，所以 dp(3) = 4
     * ✓ 以 nums[4] –1 结尾的最大连续子序列是 4、–1，所以 dp(4) = dp(3) + (–1) = 3
     * ✓ 以 nums[5] 2 结尾的最大连续子序列是 4、–1、2，所以 dp(5) = dp(4) + 2 = 5
     * ✓ 以 nums[6] 1 结尾的最大连续子序列是 4、–1、2、1，所以 dp(6) = dp(5) + 1 = 6
     * ✓ 以 nums[7] –5 结尾的最大连续子序列是 4、–1、2、1、–5，所以 dp(7) = dp(6) + (–5) = 1
     * ✓ 以 nums[8] 4 结尾的最大连续子序列是 4、–1、2、1、–5、4，所以 dp(8) = dp(7) + 4 = 5
     *
     * 定义状态方程
     * 如果dp[i - 1] =< 0 dp[i] = nums[i]
     *    dp[i - 1] >= 0 dp[i] = nums[i] + dp[i-1]
     * @param nums
     * @return
     */
    public static int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        int max = dp[0] = nums[0];
        for(int i = 1;i < dp.length;i++){
            int prev = dp[i - 1];
            if(prev > 0){
                dp[i] = prev + nums[i];
            }else {
                dp[i] = nums[i];
            }
            max = Math.max(max,dp[i]);
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println(maxSubArray(new int[]{-2,1,-3,4,-1,2,1,-5,4}));
    }
}
