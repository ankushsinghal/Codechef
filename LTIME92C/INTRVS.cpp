#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T, N, K;
  int arr[101];
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> N;
    cin >> K;
    int numSolved = 0;
    bool isSlow = false;
    bool isBot = true;
    for (int j = 0; j < N; j++)
    {
      cin >> arr[j];
      if (arr[j] != -1)
      {
        numSolved++;
      }
      if (arr[j] > K)
      {
        isSlow = true;
      }
      if (arr[j] > 1 || arr[j] < 0)
      {
        isBot = false;
      }
    }
    if (numSolved < ceil((1.0)*N / 2))
    {
      cout << "Rejected" << endl;
    }
    else if (isSlow)
    {
      cout << "Too Slow" << endl;
    }
    else if (isBot)
    {
      cout << "Bot" << endl;
    }
    else 
    {
      cout << "Accepted" << endl;
    }
  }
  return 0;
}