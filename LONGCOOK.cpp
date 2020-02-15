#include <iostream>
#define ll long long

bool isLeapYear(ll num)
{
  if (num % 4 == 0)
  {
    if (num % 100 == 0)
    {
      if (num % 400 == 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return true;
    }
  }
  else
  {
    return false;
  }
}

ll overlap(ll m1, ll y1, ll m2, ll y2)
{
  ll overlap_days_till_year[401];
  ll day_of_year[401];
  ll year1 = y1;
  ll year2 = y2;
  for (ll num = 0; num < 401; num++)
  {
    overlap_days_till_year[num] = 0;
    day_of_year[num] = 0;
  }
  for (ll num = 2; num < 401; num++)
  {
    ll offest_days;
    if (isLeapYear(num - 1))
    {
      offest_days = 2;
    }
    else
    {
      offest_days = 1;
    }

    day_of_year[num] = (day_of_year[num - 1] + offest_days) % 7;

    if (day_of_year[num] == 2) // Saturday
    {
      overlap_days_till_year[num] = overlap_days_till_year[num - 1] + 1;
    }
    else if (day_of_year[num] == 3 && !isLeapYear(num)) // Sunday of a Non Leap Year
    {
      overlap_days_till_year[num] = overlap_days_till_year[num - 1] + 1;
    }
    else
    {
      overlap_days_till_year[num] = overlap_days_till_year[num - 1];
    }
    //std::cout << "Year " << num << " : " << overlap_days_till_year[num] << std::endl;
    //std::cout << "Day of Year " << num << " : " << day_of_year[num] << std::endl;
  }
  ll total_repeat_days = overlap_days_till_year[400];

  if (m1 > 2)
  {
    year1++;
  }
  if (m2 < 2)
  {
    year2--;
  }

  ll finalMultiple = year2 / 400;
  ll finalExtra = year2 % 400;
  ll firstMultiple = year1 / 400;
  ll firstExtra = year1 % 400;
  ll ans = 0;

  if (finalMultiple == firstMultiple)
  {
    if (firstExtra == 0)
    {
      ans = overlap_days_till_year[finalExtra];
    }
    else
    {
      ans = overlap_days_till_year[finalExtra] - overlap_days_till_year[firstExtra - 1];
    }
  }
  else if (finalMultiple > firstMultiple)
  {
    if (firstExtra == 0)
    {
      ans = ans = (finalMultiple - firstMultiple) * total_repeat_days + overlap_days_till_year[finalExtra];
    }
    else
    {
      ans = total_repeat_days - overlap_days_till_year[firstExtra - 1] + (finalMultiple - firstMultiple - 1) * total_repeat_days + overlap_days_till_year[finalExtra];
    }
  }
  else
  {
    ans = 0;
  }

  return ans;
}

int main()
{
  ll T, m1, y1, m2, y2;
  std::cin >> T;
  for (ll test_case = 0; test_case < T; test_case++)
  {
    std::cin >> m1;
    std::cin >> y1;
    std::cin >> m2;
    std::cin >> y2;
    std::cout << overlap(m1, y1, m2, y2) << std::endl;
  }
  return 0;
}