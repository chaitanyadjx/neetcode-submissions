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

using IntPair = std::pair<int, int>;

unordered_map<TreeNode*, bool> ptrRegistry;
unordered_map<TreeNode*, IntPair> ptrValue;

int returnMaxPair(IntPair p){
    if(p.first < 0 && p.second < 0) return 0;
    if(p.first > p.second) return p.first;
    return p.second;
}

int SumPair(IntPair p){
    return p.first + p.second;
}

IntPair calculateDistance(TreeNode* root){
    int leftValue = 0;
    int rightValue = 0;
    if(root == nullptr) return {leftValue, rightValue};
    if(ptrRegistry[root] == true){
        return ptrValue[root];
    }
    ptrRegistry[root] = true;
    if(root->right != nullptr){
        leftValue = max(root->right->val + returnMaxPair(calculateDistance(root->right)), 0);
    }
    if(root->left != nullptr){
        rightValue = max(root->left->val + returnMaxPair(calculateDistance(root->left)), 0);
    }
    return ptrValue[root] = {leftValue, rightValue};
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        IntPair rootValue = calculateDistance(root);
        int maxvalue = SumPair(rootValue) + root->val;
        for(const auto& [ptr, pairValue]: ptrValue){
            int nodevalue = SumPair(pairValue) + ptr->val;
            cout << ptr->val << " " << nodevalue << "\n";
            maxvalue = max(maxvalue, nodevalue);
        }
        ptrValue.clear();
        ptrRegistry.clear();
        return maxvalue;
    }
};
