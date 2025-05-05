#include <iostream>  
using namespace std; 

// Define a structure (blueprint) for a tree node
struct TreeNode {
    int info;            // Value stored in the node
    TreeNode* left;      // Pointer to the left child
    TreeNode* right;     // Pointer to the right child
};

int main() {
    //  Manually creating nodes using `new` to allocate memory in the heap

    // Create root node with value 50 and no children yet
    TreeNode* root = new TreeNode{50, NULL, NULL};

    // Create additional nodes with values 30, 70, 20, and 40
    TreeNode* node1 = new TreeNode{30, NULL, NULL};  // Left child of root
    TreeNode* node2 = new TreeNode{70, NULL, NULL};  // Right child of root
    TreeNode* node3 = new TreeNode{20, NULL, NULL};  // Left child of node1
    TreeNode* node4 = new TreeNode{40, NULL, NULL};  // Right child of node1

    /*
       DRY RUN: Tree Building Step-by-Step (Visual Memory Picture)
      
         1. root → value: 50, left: NULL, right: NULL
         2. node1 → value: 30
         3. node2 → value: 70
         4. node3 → value: 20
         5. node4 → value: 40

         Now we link them like this:

                 50
               /    \
             30      70
            /  \
          20   40
    */

    //  Connect the nodes to form the tree manually
    root->left = node1;       // root's left child is 30
    root->right = node2;      // root's right child is 70
    node1->left = node3;      // node 30's left child is 20
    node1->right = node4;     // node 30's right child is 40

    //  Print values to confirm the tree structure

    cout << "Root value: " << root->info << endl;                // 50
    cout << "Left child of root: " << root->left->info << endl;  // 30
    cout << "Right child of root: " << root->right->info << endl; // 70
    cout << "Left child of node 30: " << node1->left->info << endl;  // 20
    cout << "Right child of node 30: " << node1->right->info << endl; // 40

    return 0;  // End of program
}
