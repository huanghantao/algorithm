/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
/*
思路：
首先要明白，S和T动态变化的时候，要保证动态S长度要大于动态T（否则动态S比动态T还短，从动态S中删除字符更不可能匹配动态T了）
然后还有一个就是要明白，dp[i][j]至少会等于dp[i - 1][j]。
举个例子：动态字符串S为rab1b2，动态字符串T为rab。此时至少有rab1匹配rab对吧(也就是把b2删了)，此时相当于dp[i - 1][j]。又因为动态字符串S的第二个b（即动态字符串s的当前字符）和rab的b（即动态字符串T的当前字符）相同，
所以，我们为了让动态字符串S与动态字符串T匹配，就需要保证动态字符串S前面的三个字符（也就是rab1）与动态字符串T前面的两个字符（也就是ra）匹配，也就是固定动态字符串S的b2和动态字符串T的b（即保留b2，所以我们此时可以删掉b1），此时相当于dp[i - 1][j - 1]
*/
class Solution {
public:
	/*用删除的方法将串s变换到t，计算变换方法数*/
	int numDistinct(string s, string t) {
		if (s.empty() || t.empty())
			return 0;
		else if (s.length() < t.length())
			return 0;
		else
		{
			//动态规划
			int ls = s.length(), lt = t.length();
			/*保存由字符串s(0,i) --> t(0,j)的方法数*/
			vector<vector<int> > dp(ls + 1, vector<int>(lt + 1, 0));
			dp[0][0] = 1;
			for (int i = 0; i < ls; ++i)
			{
				/*s(0,i) 转换为 t(0)的方法数为1*/
				dp[i][0] = 1;
			}//for
			for (int i = 1; i <= ls; ++i)
			{
				for (int j = 1; j <= lt && j <= i; ++j)
				{
					/*首先不管当前字符是否相同，为dp[i][j]赋初值*/
					dp[i][j] = dp[i - 1][j];
					if (s[i-1] == t[j-1]) // 注意：当前字符i、j是第i、j个字符的意思，所以在数组中索引为i - 1、j - 1
					{
						/*如果s和t的当前字符相同，有两种选择保留或不保留*/
						dp[i][j] += dp[i - 1][j - 1];
					}//if
				}//for
			}//for
			return dp[ls][lt];
		}
	}	
};