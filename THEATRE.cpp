#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int findNumZeroes(std::vector<int> *vec)
{
  int numZeroes = 0;
  for (int num = 0; num < vec->size(); num++)
  {
    if (vec->at(num) == 0)
    {
      numZeroes++;
    }
  }
  return numZeroes;
}

void permutation(std::string str, std::string prefix, std::vector<std::string> *vec){
  if (str.length() == 0)
  {
    vec->push_back(prefix);
  }
  else
  {
    for (int num = 0; num < str.length(); num ++)
    {
      std::string rem = str.substr(0, num) + str.substr(num + 1);
      permutation(rem, prefix + str[num], vec);
    }
  }
}

int maxProfit(int arr[4][4])
{
  std::vector<std::string> all_permutations;
  std::vector<int> profits;
  permutation("ABCD", "", &all_permutations);
  for (int num = 0; num < all_permutations.size(); num ++)
  {
    std::string current_permutation = all_permutations[num];
    std::vector<int> requests;
    int current_score = 0;
    //std::cout << current_permutation << std::endl;
    for (int index = 0; index < 4; index ++)
    {
      requests.push_back(arr[current_permutation[index] - 'A'][index]);
    }
    std::sort(requests.begin(), requests.end());
    for (int index = 0; index < 4; index++)
    {
      current_score += (25 * (index + 1) * requests[index]);
    }
    current_score -= findNumZeroes(&requests) * 100;
    profits.push_back(current_score);
  }
  return *std::max_element(profits.begin(), profits.end());
}

int main()
{
  int T, N, t;
  char m;
  int arr[4][4];
  std::cin >> T;
  int total_profit = 0;
  for (int test_case = 0; test_case < T; test_case ++)
  {
    int test_case_profit = 0;
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        arr[i][j] = 0;
      }
    }
    std::cin >> N;
    for (int num = 0; num < N; num ++)
    {
      std::cin >> m;
      std::cin >> t;
      arr[m - 'A'][(t - 3) / 3]++;
    }
    // for (int i = 0; i < 4; i++)
    // {
    //   for (int j = 0; j < 4; j++)
    //   {
    //     std::cout << arr[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }
    test_case_profit = maxProfit(arr);
    total_profit += test_case_profit;
    std::cout << test_case_profit << std::endl;
  }
  std::cout << total_profit << std::endl;
  return 0;
}