#include <bits/stdc++.h>

using namespace std;

int arr[100001];

void isPossible(int n, int k, bool isOne)
{
  if (k % 2 == 1)
  {
    for (int i = 0; i < n; i++)
    {
      if (arr[i] != 0)
      {
        std::cout << "NO" << endl;
        return;
      }
    }
    std::cout << "YES" << endl;
    return;
  }
  else
  {
    if (isOne)
    {
      if (k & (k - 1) == 0)
      {
        std::cout << "YES" << endl;
        return;
      }
    }
    for (int i = 0; i < n; i++)
    {
      int temp = arr[i];
      if (temp == 0)
      {
        continue;
      }
      while (temp < k)
      {
        temp = temp * 2;
      }
      if (temp != k)
      {
        temp = k - arr[i];
        while (temp < k)
        {
          temp = temp * 2;
        }
        if (temp != k)
        {
          std::cout << "NO" << endl;
          return;
        }
      }
    }
    std::cout << "YES" << endl;
    return;
  }
}

int main()
{
  int T, n, k;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> n;
    cin >> k;
    int isOne = false;
    for (int j = 0; j < n; j++)
    {
      cin >> arr[j];
      arr[j] = arr[j] % k;
      if (arr[j] == 1 || (k - arr[j]) == 1)
      {
        isOne = true;
      }
    }
    isPossible(n, k, isOne);
  }
  return 0;
}