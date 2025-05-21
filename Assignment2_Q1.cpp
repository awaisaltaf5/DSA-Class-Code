#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

bool areSimilar(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return areSimilar(root1->left, root2->left) && areSimilar(root1->right, root2->right);
}

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int main() {
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;

    root1 = insertNode(root1, 5);
    root1 = insertNode(root1, 3);
    root1 = insertNode(root1, 7);

    root2 = insertNode(root2, 10);
    root2 = insertNode(root2, 6);
    root2 = insertNode(root2, 15);

    if (areSimilar(root1, root2)) {
        cout << "The two binary trees are similar." << endl;
    } else {
        cout << "The two binary trees are not similar." << endl;
    }

    return 0;
}
