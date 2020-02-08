#include <iostream>
#define SIZE_ARRAY 100000

void printArray(long long *arr, long long N)
{
  for (long long i = 0; i < N; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout <<std::endl;
}

long long minExtraCoins(long long *arr, long long N, long long K)
{
  long long coinsToRemove[SIZE_ARRAY];
  long long  coinsToAdd[SIZE_ARRAY];
  coinsToRemove[0] = arr[0] % K;
  for (long long num = 1; num < N; num++)
  {
    coinsToRemove[num] = coinsToRemove[num - 1] + (arr[num] % K);
  }
  coinsToAdd[N - 1] = K - (arr[N - 1] % K);
  for (long long num = N - 2; num >= 0; num--)
  {
    coinsToAdd[num] = coinsToAdd[num + 1] + (K - (arr[num] % K));
  }
  //printArray(coinsToRemove, N);
  //printArray(coinsToAdd, N);
  long long finalAnswer = K + 1;
  long long atleastOneAnswer = 0;
  for (long long num = 0; num < N - 1; num++)
  {
    if ((coinsToRemove[num] - coinsToAdd[num + 1]) >= 0 && (coinsToRemove[num] - coinsToAdd[num + 1]) % K < finalAnswer)
    {
      finalAnswer = (coinsToRemove[num] - coinsToAdd[num + 1]) % K;
      atleastOneAnswer = 1;
    }
  }
  if (atleastOneAnswer == 0)
  {
    finalAnswer = coinsToRemove[N - 1];
  }
  return finalAnswer;
}

int main()
{
  long long T, N, K;
  long long arr[SIZE_ARRAY];
  std:: cin >> T;
  for (long long test_case = 0; test_case < T; test_case++)
  {
    std::cin >> N;
    std::cin >> K;
    for (long long num = 0; num < N; num++)
    {
      std::cin >> arr[num];
    }
    std::cout << minExtraCoins(arr, N, K) << std::endl;
  }
  return 0;
}