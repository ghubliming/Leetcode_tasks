#include <iostream>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Helper function to track recursion depth
    void printIndent(int depth) {
        for(int i = 0; i < depth; i++) {
            cout << "  ";
        }
    }
    
    // Modified comparison function with debug prints
    bool isSameTreeWithDebug(TreeNode* p, TreeNode* q, int depth = 0) {
        printIndent(depth);
        cout << "Comparing nodes at depth " << depth << ":\n";
        
        printIndent(depth);
        cout << "Left tree node: " << (p ? to_string(p->val) : "NULL") << "\n";
        printIndent(depth);
        cout << "Right tree node: " << (q ? to_string(q->val) : "NULL") << "\n";
        
        if (p == NULL && q == NULL) {
            printIndent(depth);
            cout << "Both nodes are NULL -> returning true\n";
            return true;
        }
        
        if (p == NULL || q == NULL) {
            printIndent(depth);
            cout << "One node is NULL -> returning false\n";
            return false;
        }
        
        if (p->val == q->val) {
            printIndent(depth);
            cout << "Values match (" << p->val << "). Checking children...\n";
            
            printIndent(depth);
            cout << "Checking left children...\n";
            bool leftResult = isSameTreeWithDebug(p->left, q->left, depth + 1);
            
            printIndent(depth);
            cout << "Checking right children...\n";
            bool rightResult = isSameTreeWithDebug(p->right, q->right, depth + 1);
            
            printIndent(depth);
            cout << "Result for this subtree: " << (leftResult && rightResult ? "true" : "false") << "\n";
            
            return leftResult && rightResult;
        }
        
        printIndent(depth);
        cout << "Values don't match (" << p->val << " != " << q->val << ") -> returning false\n";
        return false;
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        cout << "\nStarting tree comparison...\n\n";
        return isSameTreeWithDebug(p, q);
    }
};

// Helper function to create a tree
TreeNode* createTree(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(val, left, right);
}

// Helper function to delete tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution solution;
    
    // Test Case 1: Identical trees
    cout << "Test Case 1: Identical trees\n";
    TreeNode* p1 = createTree(1,
                             createTree(2),
                             createTree(3));
    TreeNode* q1 = createTree(1,
                             createTree(2),
                             createTree(3));
    
    cout << "Result: " << (solution.isSameTree(p1, q1) ? "Trees are identical" : "Trees are different") << "\n\n";
    
    // Test Case 2: Different trees
    cout << "Test Case 2: Different trees\n";
    TreeNode* p2 = createTree(1,
                             createTree(2),
                             createTree(3));
    TreeNode* q2 = createTree(1,
                             createTree(2),
                             createTree(4));  // Different value here
    
    cout << "Result: " << (solution.isSameTree(p2, q2) ? "Trees are identical" : "Trees are different") << "\n\n";
    
    // Test Case 3: Different structure
    cout << "Test Case 3: Different structure\n";
    TreeNode* p3 = createTree(1,
                             createTree(2),
                             nullptr);
    TreeNode* q3 = createTree(1,
                             nullptr,
                             createTree(2));
    
    cout << "Result: " << (solution.isSameTree(p3, q3) ? "Trees are identical" : "Trees are different") << "\n\n";
    
    // Clean up memory
    deleteTree(p1);
    deleteTree(q1);
    deleteTree(p2);
    deleteTree(q2);
    deleteTree(p3);
    deleteTree(q3);
    
    return 0;
}
