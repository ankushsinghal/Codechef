#include <iostream>
#include <algorithm>

using namespace std;

string row_string[11];

int minOperationsStartStar(int N, int M)
{
  int answer = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i % 2 == 0)
      {
        if (j % 2 == 0)
        {
          if (row_string[i][j] == '.')
          {
            answer++;
          }
        }
        else
        {
          if (row_string[i][j] == '*')
          {
            answer++;
          }
        }
      }
      else
      {
        if (j % 2 == 0)
        {
          if (row_string[i][j] == '*')
          {
            answer++;
          }
        }
        else
        {
          if (row_string[i][j] == '.')
          {
            answer++;
          }
        }
      }
    }
  }
  return answer;
}

int minOperationsStartDot(int N, int M)
{
  int answer = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i % 2 == 0)
      {
        if (j % 2 == 0)
        {
          if (row_string[i][j] == '*')
          {
            answer++;
          }
        }
        else
        {
          if (row_string[i][j] == '.')
          {
            answer++;
          }
        }
      }
      else
      {
        if (j % 2 == 0)
        {
          if (row_string[i][j] == '.')
          {
            answer++;
          }
        }
        else
        {
          if (row_string[i][j] == '*')
          {
            answer++;
          }
        }
      }
    }
  }
  return answer;
}

int minOperations(int N, int M)
{
  if ((N % 2 == 1) && (M % 2 == 1))
  {
    return minOperationsStartStar(N, M);
  }
  else
  {
    return min(minOperationsStartStar(N, M), minOperationsStartDot(N, M));
  }
}

int main()
{
  int T, N, M;
  cin >>T;
  string s;
  for (int test_case = 0; test_case < T; test_case++)
  {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
      cin >> row_string[i];
    }
    cout << minOperations(N, M) << endl;
  }
  return 0;
}