#include <bits/stdc++.h>
using namespace std;

int earliestResult(int N, string shots){
  int currA = 0;
  int currB = 0;
  for(int i = 0; i < 2*N; i++){
    if(i % 2 == 0){
      if(shots[i] == '1'){
        currA++;
      }
      if(currA + (N - (i/2) - 1) < currB){
        return i + 1;
      }
      else if(currB + (N - (i/2)) < currA){
        return i + 1;
      }
    }
    else{
      if(shots[i] == '1'){
        currB++;
      }
      if (currA + (N - ((i-1) / 2) - 1) < currB)
      {
        return i + 1;
      }
      else if (currB + (N - ((i - 1) / 2) - 1) < currA)
      {
        return i + 1;
      }
    }
  }
  return 2*N;
}

int main(){
  int T, N;
  string shots;
  cin >> T;
  for (int test_case = 0; test_case < T; test_case++){
    cin >> N;
    cin >> shots;
    cout << earliestResult(N, shots) << endl;
  }
  return 0;
}