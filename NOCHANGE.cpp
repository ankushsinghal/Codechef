#include <iostream>

#define SIZE_N 1000

void noChange(int n, int p, int *arr)
{
  int numCoins[SIZE_N];
  int isSolution = 0;
  int firstIndex = -1;
  int secondIndex = -1;
  for (int num = 0; num < n; num++)
  {
    numCoins[num] = 0;
  }
  for (int num = 0; num < n; num++)
  {
    if (p % arr[num] != 0)
    {
      numCoins[num] = (p / arr[num]) + 1;
      isSolution = 1;
      break;
    }
  }
  if (!isSolution)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[i] > arr[j])
        {
          if (arr[i] % arr[j] != 0)
          {
            firstIndex = i;
            secondIndex = j;
            break;
          }
        }
        else if ((arr[j] > arr[i]))
        {
          if (arr[j] % arr[i] != 0)
          {
            firstIndex = j;
            secondIndex = i;
            break;
          }
        }
      }
      if (firstIndex >= 0 && secondIndex >= 0)
      {
        break;
      }
    }
    if (firstIndex >= 0 && secondIndex >= 0)
    {
      numCoins[firstIndex] = p / arr[firstIndex] - 1;
      numCoins[secondIndex] = (arr[firstIndex] / arr[secondIndex]) + 1;
      isSolution = 1;
    }
  }

  if (!isSolution)
  {
    std::cout << "NO" << std::endl;
  }
  else
  {
    std::cout << "YES ";
    for (int num = 0; num < n; num++)
    {
      std::cout << numCoins[num] << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  int T, N, P;
  int arr[SIZE_N];
  std::cin >> T;
  for (int test_case = 0; test_case < T; test_case++)
  {
    std::cin >> N;
    std::cin >> P;
    for (int num = 0; num < N; num++)
    {
      std::cin >> arr[num];
    }
    noChange(N, P, arr);
  }
}