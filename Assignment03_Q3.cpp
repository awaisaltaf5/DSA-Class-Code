#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* insert(TreeNode *node, int data) {
    if (node == NULL) {
        TreeNode *newNode = new TreeNode();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

void Inorder(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    Inorder(node->left);
    cout << node->data << "  ,  ";
    Inorder(node->right);
}

void Preorder(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << "  ,  ";
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(TreeNode *node) {
    if (node == NULL) {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << "  ,   ";
}

int main() {
    TreeNode *root = NULL;

    root = insert(root, 23);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 65);
    root = insert(root, 91);
    root = insert(root, 3);
    root = insert(root, 22);

    cout << "Inorder:    ";
    Inorder(root);
    cout<<endl;
    cout << "Preorder:    ";
    Preorder(root);
     cout<<endl;
    cout << " Postorder:    ";
    Postorder(root);
    cout << endl;

    return 0;
}
