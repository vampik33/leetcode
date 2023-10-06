#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string res;
    res.reserve(s.size());
    string word;
    for (auto c : s) {
      if (c == ' ') {
        reverse(word.begin(), word.end());
        res += word + c;
        word.clear();
      } else {
        word += c;
      }
    }
    reverse(word.begin(), word.end());
    res += word;

    return res;
  }
};

// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution2 {
public:
  string reverseWords(string s) {
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      int j = i;
      while (j < N && s[j] != ' ') ++j;
      int next = j;
      j-=1;

      for (--j; i < j;) swap(s[i++], s[j--]);
      i = next;
    }
    return s;
  }
};

// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution3 {
public:
  string reverseWords(string s) {
    for (int i = 0, begin = 0, N = s.size(); i <= N; ++i) {
      if (i == N || s[i] == ' ') {
        reverse(s.begin() + begin, s.begin() + i);
        begin = i + 1;
      }
    }
    return s;
  }
};

int main()
{
  try
  {
    {
      Solution s;
      const auto res = s.reverseWords("Let's take LeetCode contest");
      cout << res << endl;
      int j = 0;
    }
    {
      Solution s;
      const auto res = s.reverseWords("God Ding");
      cout << res << endl;
      int j = 0;
    }
  }
  catch ( const exception& e )
  {
    cerr << e.what();
  }

  return 0;
}