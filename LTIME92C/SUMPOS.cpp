#include <bits/stdc++.h>

using namespace std;

int main()
{
  int arr[3];
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    sort(arr, arr + 3);
    if (arr[2] == arr[1] + arr[0])
    {
      cout << "YES" << endl;
    }
    else 
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}