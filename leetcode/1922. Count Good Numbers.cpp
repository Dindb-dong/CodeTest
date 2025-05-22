#include <iostream>
#include <cmath>
class Solution
// 0부터 시작하는 인덱스의 짝수 위치에 짝수가 오고 홀수 위치에 소수가 오면
// 좋은 수
{
public:
  // modulo 지수 연산을 위한 함수
  long long modPow(long long base, long long exp, long long mod)
  {
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
      if (exp % 2 == 1)
      {
        result = (result * base) % mod;
      }
      base = (base * base) % mod;
      exp = exp / 2;
    }
    return result;
  }

  int countGoodNumbers(long long n)
  {
    const long long MOD = 1e9 + 7;
    long long evenCount = 0;
    long long oddCount = 0;
    if (n % 2 == 0)
    {
      evenCount = n / 2;
      oddCount = n / 2;
    }
    else
    {
      evenCount = (n + 1) / 2;
      oddCount = (n - 1) / 2;
    }

    // modulo 지수 연산 사용
    long long evenResult = modPow(5, evenCount, MOD);
    long long oddResult = modPow(4, oddCount, MOD);
    return (int)((evenResult * oddResult) % MOD);
  }
};

int main()
{
  Solution solution;
  long long n = 806166225460393;
  int result = solution.countGoodNumbers(n);
  std::cout << "Result for n=" << n << ": " << result << std::endl;
  return 0;
}

// 개인적으로 이 문제는 modulo 지수 연산을 모르면 절대 못 푸는 문제였다.
// 수업시간에 배운 적이 없었기 때문에, 찾아보는 데에 애를 먹었다.
// 또 int로 선언 시 숫자 오버플로우 문제가 생길 수 있다는 걸 처음 알았다.
// (이정도로 큰 수를 처리하는 알고리즘을 처음 짜봤다.)
// 우여곡절이 있긴 했지만, modulo 연산과 long long 자료형을 이용하니
// 나머지는 어려움 없었다.