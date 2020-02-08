#include <iostream>
#include <algorithm>

long long diameterSum(long long *A, long long *B, long long N)
{
  std::sort(A, A + N);
  std::sort(B, B + N);
  long long total_sum = 0;
  for (long long num = 0; num < N; num ++)
  {
    if (A[num] < B[num])
    {
      total_sum += A[num];
    }
    else
    {
      total_sum += B[num];
    }
  }
  return total_sum;
}

int main()
{
  long long T, N;
  long long A[10000], B[10000];
  std::cin >> T;
  for (long long test_case = 0; test_case < T; test_case++)
  {
    std::cin >> N;
    for (long long num = 0; num < N; num++)
    {
      std::cin >> A[num];
    }
    for (long long num = 0; num < N; num++)
    {
      std::cin >> B[num];
    }
    std::cout << diameterSum(A, B, N) << std::endl;
  }
  return 0;
}