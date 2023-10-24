struct Solution;

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

impl Solution {
    fn iterate_through_tree(
        root: Option<Rc<RefCell<TreeNode>>>,
        max_value: &mut Vec<i32>,
        depth: usize,
    ) {
        match root {
            Some(val) => {
                if max_value.len() <= depth {
                    max_value.push(val.as_ref().borrow().val)
                } else {
                    if max_value[depth] < val.as_ref().borrow().val {
                        max_value[depth] = val.as_ref().borrow().val
                    }
                }

                Self::iterate_through_tree(
                    val.as_ref().borrow().left.clone(),
                    max_value,
                    depth + 1,
                );

                Self::iterate_through_tree(
                    val.as_ref().borrow().right.clone(),
                    max_value,
                    depth + 1,
                );
            }
            None => {}
        }
    }

    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        Self::iterate_through_tree(root, &mut res, 0);

        res
    }
}

fn main() {
    {
        let root = TreeNode::new(5);
        let root = Some(Rc::new(RefCell::new(root)));
        let _res = Solution::largest_values(root);
    }
}
