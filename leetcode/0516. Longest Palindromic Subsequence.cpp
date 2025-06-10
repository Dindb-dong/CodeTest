#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  int longestPalindromeSubseq(string s)
  {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0)); // 행렬 초기화
    // dp[i][j]는 s[i]부터 s[j]까지의 가장 긴 회문 부분 수열의 길이
    // 대각선 왼쪽 위에서 오른쪽 아래로 채워짐
    for (int i = n - 1; i >= 0; i--)
    {
      // 대각선 채우기
      dp[i][i] = 1;
      for (int j = i + 1; j < n; j++)
      {
        if (s[i] == s[j])
        {
          // i번째와 j번째 문자가 같으면, 그 사이의 회문 부분 수열의 길이 + 2
          // 예: n = 10이고 i=3, j=7이면, dp[3][7] = dp[4][6] + 2
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
        else
        {
          // i번째와 j번째 문자가 다르면, 그 사이의 회문 부분 수열의 길이는 그 사이의 두 문자 중 더 긴 회문 부분 수열의 길이
          // 예: n = 10이고 i=3, j=7이면, dp[3][7] = max(dp[4][7], dp[3][6])
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[0][n - 1];
  }
};