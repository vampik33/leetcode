#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto it = find(nums.cbegin(), nums.cend(), target);
    if(it == nums.cend())
      return {-1, -1};

    const int first = std::distance(nums.cbegin(), it);

    ++it;
    while(it != nums.cend())
    {
      if(*(it) != target)
        break;
      ++it;
    }

    return {first, (int)std::distance(nums.cbegin(), it-1)};
  }
};

// Time: O(logN)
// Space: O(1)
class Solution2 {
public:
  vector<int> searchRange(vector<int>& A, int target) {
    if (A.empty()) return {-1,-1};
    int N = A.size(), L = 0, R = N - 1;
    while (L <= R) {
      int M = (L + R) / 2;
      if (A[M] < target) L = M + 1;
      else R = M - 1;
    }
    if (L >= N || A[L] != target) return {-1,-1};
    int left = L;
    L = 0, R = N - 1;
    while (L <= R) {
      int M = (L + R) / 2;
      if (A[M] > target) R = M - 1;
      else L = M + 1;
    }
    return {left, R};
  }
};

class Solution3 {
public:
  vector<int> searchRange(vector<int>& A, int target) {
    if (A.empty()) return {-1,-1};
    int N = A.size(), L = 0, R = N - 1;
    while (L <= R) {
      int M = L + ((R - L) >> 1);
      if (A[M] < target) L = M + 1;
      else R = M - 1;
    }
    if (L >= N || A[L] != target) return {-1,-1};

    int left = L;
    R = N;
    while (L < R) {
      int M = L + ((R - L) >> 1);
      if (A[M] <= target)
        L = M + 1;
      else
        R = M;
    }
    return {left, L-1};
  }
};

int main()
{
  try
  {
    {
      Solution s;
      vector<int> nums = {5,7,7,8,8,10};
      const auto res = s.searchRange(nums, 8);
      int stop = 1;
    }

    {
      Solution2 s;
      vector<int> nums = {5,7,7,8,8,10};
      const auto res = s.searchRange(nums, 8);
      int stop = 1;
    }

    {
      Solution3 s;
      vector<int> nums = {5,7,7,8,8,10};
      const auto res = s.searchRange(nums, 8);
      int stop = 1;
    }
  }
  catch ( const exception& e )
  {
    cerr << e.what();
  }

  return 0;
}