package com.meicilly.动态规划;

/**
 * https://leetcode.cn/problems/coin-change/
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 * 假设有25分 20分 5分 1分的硬币，现在要找给客户41分的零钱，如何办到最少
 * 第一次选择25分的硬币 dp(n)=dp(n-15) + 1;
 * 选择20分的硬币是 dp[n]=dp[n-20] + 1;
 * 选择5分 dp[n]=dp[n-5] + 1;
 * 选着1分 dp[n]=dp[n-1] +1;
 * 所以 dp(n) = min { dp(n – 25), dp(n – 20), dp(n – 5), dp(n – 1) } + 1
 */
public class _01_找零钱 {
    public static int coinChange(int n, int[] faces) {
        if(n < 1 || faces == null || faces.length == 0) return  -1;
        int[] dp = new int[n +1];
        for(int i = 1;i <= n;i++){
            int min = Integer.MAX_VALUE;
            for(int face:faces){
                if(i < face) continue;
                int v = dp[i - face];
                if(v < 0 || v >= min) continue;
                min = v;
            }
            if (min == Integer.MAX_VALUE) {
                dp[i] = -1;
            } else {
                dp[i] = min + 1;
            }
            System.out.println(dp[i]);
        }

        return dp[n];
    }

    public static void main(String[] args) {
        System.out.println(coinChange(19,new int[]{1,5,25,20}));
    }
}
