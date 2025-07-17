// LeetCode - 102 - Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal 
// of its nodes' values. (i.e., from left to right, then right to left for 
// the next level and alternate between).
//
// ex: root = [3,9,20,null,null,15,7] => [[3],[20,9],[15,7]]
// ex: root = [1] => [[1]]
// ex: root = [] => []
//
// Author: Thiru
//
// Time complexity: O(logn)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result{};
    if (!root) {
        return result;
    }

    std::queue<TreeNode*> queue;
    queue.emplace(root);

    // use this flag to alternate the direction
    bool leftToRight = true;

    while (!queue.empty()) {

        int levelsize = queue.size();
        std::vector<int> levelvec{};

        for (int i=0; i<levelsize; i++) {
            root = queue.front();
            queue.pop();

            levelvec.push_back(root->val);

            if (root->left) {
                queue.emplace(root->left);
            }

            if (root->right) {
                queue.emplace(root->right);
            }
        }

        // reverse the values in the container
        if (!leftToRight) {
            std::reverse(levelvec.begin(), levelvec.end());
        }

        if (levelvec.size()) {
            result.push_back(levelvec);
        }
        leftToRight = !leftToRight;
    }

    return result;
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    //TreeNode *root = new TreeNode(1);

    std::vector<std::vector<int>> res = zigzagLevelOrder(root);

    for (const auto& r: res) {
        for (const auto& e: r) {
            std::cout<<e<<" ";
        }
        std::cout<<", ";
    }
    std::cout<<std::endl;

    return 0;
}