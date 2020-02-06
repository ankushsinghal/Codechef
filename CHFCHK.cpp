#include <iostream>
#include <climits>

int longestJump(int *arr, int N){
  int min = INT_MAX;
  for (int num = 0; num < N; num++)
  {
    if (arr[num] < min)
    {
      min = arr[num];
    }
  }
  return min;
}

int main()
{
  int T, N;
  int arr[100];
  std::cin >> T;
  for (int test_case = 0; test_case < T; test_case++)
  {
    std::cin >> N;
    for (int num = 0; num < N; num++)
    {
      std::cin >> arr[num];
    }
    std::cout << longestJump(arr, N) << std::endl;
  }
  return 0;
}