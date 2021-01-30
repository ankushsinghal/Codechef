#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T, N, num;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> N;
    int evens = 0;
    int odds = 0;
    for (int j = 0; j < N; j++)
    {
      cin >> num;
      if (num % 2 == 0)
      {
        evens++;
      }
      else
      {
        odds++;
      }
    }
    if (odds % 2 == 0)
    {
      cout << "1" << endl;
    }
    else
    {
      cout << "2" << endl;
    }
  }
  return 0;
}