#include <iostream>
#include <string>

using namespace std;

bool checkLower(char a)
{
  if (a >= 97 && a <= 122)
  {
    return true;
  }
  return false;
}

bool checkUpper(char a)
{
  if (a >= 65 && a <= 90)
  {
    return true;
  }
  return false;
}

bool checkNumber(char a)
{
  if (a >= 48 && a <= 57)
  {
    return true;
  }
  return false;
}

bool checkSpecial(char a)
{
  if (a == '@' || a == '#' || a == '%' || a == '&' || a == '?')
  {
    return true;
  }
  return false;
}

string checkPassword(string s)
{
  if (s.length() < 10)
  {
    return "NO";
  }
  bool lower_bool = false;
  bool upper_bool = false;
  bool number_bool = false;
  bool special_bool = false;
  if (checkLower(s[0]))
  {
    lower_bool = true;    
  }
  if (checkLower(s[s.length() - 1]))
  {
    lower_bool = true;
  }
  for (int i = 1; i < s.length() - 1; i++){
    if (!lower_bool)
    {
      if (checkLower(s[i]))
      {
        lower_bool = true;
      }
    }
    if (!upper_bool)
    {
      if (checkUpper(s[i]))
      {
        upper_bool = true;
      }
    }
    if (!number_bool)
    {
      if (checkNumber(s[i]))
      {
        number_bool = true;
      }
    }
    if (!special_bool)
    {
      if (checkSpecial(s[i]))
      {
        special_bool = true;
      }
    }
    if (lower_bool && upper_bool && number_bool && special_bool)
    {
      break;
    }
  }
  if (lower_bool && upper_bool && number_bool && special_bool)
  {
    return "YES";
  }
  return "NO";
}

int main()
{
  int T;
  string s;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> s;
    cout << checkPassword(s) << endl;
  }
  return 0;
}