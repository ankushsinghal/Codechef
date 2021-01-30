#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T, N, num;
  cin >> T;
  for (int i = 0; i < T; i++)  
  {
    int evens = 0;
    int odds = 0;
    cin >> N;
    for (int j = 0; j < N; j++){
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
    cout << min(odds, evens) << endl;
  }
  return 0;
}