#include <bits/stdc++.h>
using namespace std;

int netIncome(int N){
  int tax = 0;
  if(N > 1500000){
    tax = 187500 + ((N - 1500000)*30)/100;
  }
  else if(N > 1250000){
    tax = 125000 + ((N - 1250000) * 25) / 100;
  }
  else if (N > 1000000)
  {
    tax = 75000 + ((N - 1000000) * 20) / 100;
  }
  else if (N > 750000)
  {
    tax = 37500 + ((N - 750000) * 15) / 100;
  }
  else if (N > 500000)
  {
    tax = 12500 + ((N - 500000) * 10) / 100;
  }
  else if (N > 250000)
  {
    tax = ((N - 250000) * 5) / 100;
  }

  return N - tax;
}

int main(){
  int T, N;
  cin >> T;
  for(int test_case = 0; test_case < T; test_case++){
    cin >> N;
    cout << netIncome(N) << endl;
  }
  return 0;
}