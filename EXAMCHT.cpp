#include <iostream>
#include <math.h>

int numDivisors(int x)
{
  int num_divisors = 0;
  int upper = floor(sqrt(x));
  for (int num = 1; num <= upper; num++)
  {
    if (x % num == 0)
    {
      if (num * num == x)
      {
        num_divisors++;
      }
      else
      {
        num_divisors += 2;
      }
    }
  }
  return num_divisors;
}

int numPossibilities(int A, int B)
{
  int diff = abs(A - B);
  if (diff == 0)
  {
    return -1;
  }
  else
  {
    return numDivisors(diff);
  }
}

int main(){
  int T, A, B;
  std::cin >> T;
  for (int test_case = 0; test_case < T; test_case++)
  {
    std::cin >> A;
    std::cin >> B;
    std::cout << numPossibilities(A, B) << std::endl;
  }
  return 0;
}