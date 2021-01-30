#include <iostream>

using namespace std;

int main()
{
  int T, L, R;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> L;
    cin >> R;
    cout << 2 * (R - L) + 1 << endl;
  }
  return 0;
}