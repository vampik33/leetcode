#include <algorithm>
#include <iostream>

using namespace std;

#include <math.h>
class Solution {
public:
  int integerBreak(int n) {
    if(n < 4)
      return n-1;

    int count_of_3 = 0;
    while(n > 4)
    {
      count_of_3++;
      n -= 3;
    }

    return n * pow(3, count_of_3);
  }
};

class Solution2 {
public:
  int integerBreak(int n) {
    if(n < 4)
      return n-1;

    int p = 1;
    while(n > 4)
    {
      p *= 3;
      n -= 3;
    }

    return n * p;
  }
};

int main()
{
  try
  {
    {
      Solution s;
      const auto res = s.integerBreak(4);
      cout << res << endl;
    }
    {
      Solution2 s;
      const auto res = s.integerBreak(10);
      cout << res << endl;
    }
  }
  catch ( const exception& e )
  {
    cerr << e.what();
  }

  return 0;
}