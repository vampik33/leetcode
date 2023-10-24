#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  void iterateThroughTree(TreeNode* root, vector<int>& max_value, unsigned int depth)
  {
    if(root)
    {
      if(max_value.size() <= depth )
        max_value.push_back(root->val);
      else
      {
        if( max_value[depth] < root->val )
          max_value[depth] = root->val;
      }

      iterateThroughTree(root->right, max_value, depth+1);
      iterateThroughTree(root->left, max_value, depth+1);
    }
  }

  vector<int> largestValues(TreeNode* root)
  {
    vector<int> res;

    iterateThroughTree(root, res, 0);

    return res;
  }
};

int main()
{
  try
  {
    {
      Solution s;
      TreeNode* root = nullptr;
      const auto res = s.largestValues(root);
      //cout << res << endl;
      int j = 0;
    }
  }
  catch ( const exception& e )
  {
    cerr << e.what();
  }

  return 0;
}