// LeetCode - 100 - Same Tree
// Given the roots of two binary trees p and q, write a function to 
// check if they are the same or not. Two binary trees are considered the 
// same if they are structurally identical, and the nodes have the same value.
// 
// ex: p = [1,2,3], q = [1,2,3] => true
// ex: p = [1,2], q = [1,null,2] => false
// ex: p = [1,2,1], q = [1,1,2] => false
//
// Author: Thiru
//
// Time complexity: O(n)
// Space complexity: O(h) // height of the tree

#include <iostream>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {
    }
};

// Using BFS
bool isSameTree(TreeNode* p, TreeNode* q) {
    // null trees
    if (!p && !q) {
        return true;
    }

    // ane one of tree is null
    if (!p || !q) {
        return false;
    }
    
    std::queue<TreeNode*> pqueue;
    std::queue<TreeNode*> qqueue;
    pqueue.emplace(p);
    qqueue.emplace(q);

    while(!pqueue.empty() || !qqueue.empty()) {
        TreeNode *node1 = pqueue.front();
        TreeNode *node2 = qqueue.front();
        pqueue.pop();
        qqueue.pop();

        if (node1->val != node2->val) {
            return false;
        }

        if (node1->left && node2->left) {
            pqueue.emplace(node1->left);
            qqueue.emplace(node2->left);
        } else if (node1->left || node2->left) {
            return false;
        }

        if (node1->right && node2->right) {
            pqueue.emplace(node1->right);
            qqueue.emplace(node2->right);
        } else if (node1->right || node2->right) {
            return false;
        }
    }

    return pqueue.empty() && qqueue.empty();
}

int main() {
    // TreeNode *t1 = new TreeNode(1);
    // t1->left = new TreeNode(2);
    // t1->right = new TreeNode(3);

    // TreeNode *t2 = new TreeNode(1);
    // t2->left = new TreeNode(2);
    // t2->right = new TreeNode(3);

    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(1);

    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(2);
    
    std::cout<<"Same Tree "<<std::boolalpha<<isSameTree(t1, t2)<<std::endl;

    return 0;
}