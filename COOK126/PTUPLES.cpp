#include <iostream>
#include <math.h>

#define MAX_N 1000000

using namespace std;

int prime_tuples_table[MAX_N];

bool isPrime(int a)
{
  if (a == 2 || a == 3)
  {
    return true;
  }
  if (a % 2 == 0)
  {
    return false;
  }
  int i = 3;
  while (i <= floor(sqrt(a)))
  {
    if ((a % i) == 0)
    {
      return false;
    }
    i += 2;
  }
  return true;
}

void primeTuples(int N)
{
  prime_tuples_table[1] = 0;
  prime_tuples_table[2] = 0;
  prime_tuples_table[3] = 0;
  prime_tuples_table[4] = 0;
  prime_tuples_table[5] = 1;
  
  int last_prime = 5;
  for (int i = 6; i <= N; i++)
  {
    if (i % 2 == 0)
    {
      prime_tuples_table[i] = prime_tuples_table[i - 1];
    }
    else
    {
      if (isPrime(i))
      {
        if (last_prime == i - 2)
        {
          prime_tuples_table[i] = prime_tuples_table[i - 1] + 1;
        }
        else{
          prime_tuples_table[i] = prime_tuples_table[i - 1];
        }
        last_prime = i;
      }
      else
      {
        prime_tuples_table[i] = prime_tuples_table[i - 1];
      }
    }
  }
}

int main()
{
  int T, N;
  cin >>T;
  primeTuples(MAX_N);
  for (int i = 0; i < T; i++)
  {
    cin >> N;
    cout << prime_tuples_table[N] << endl;
  }
  return 0;
}