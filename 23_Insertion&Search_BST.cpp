#include <iostream>
using namespace std;

// Define the structure for a node in the Binary Search Tree (BST)
struct TreeNode {
    int info;            // The value stored in the node
    TreeNode* left;      // Pointer to the left child (smaller values)
    TreeNode* right;     // Pointer to the right child (larger values)
};

// Function to insert a value into the BST
TreeNode* Insert(TreeNode* root, int item) {
    if (root == NULL) {
        // Base case: create a new node when we reach an empty subtree
        TreeNode* newNode = new TreeNode;
        newNode->info = item;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;  // New node becomes the root of this subtree
    }
    else if (item < root->info) {
        // If the item is smaller than the root's value, insert into left subtree
        root->left = Insert(root->left, item);
    }
    else {
        // If the item is larger than the root's value, insert into right subtree
        root->right = Insert(root->right, item);
    }

    return root;  // Return the unchanged root pointer
}

// Function to search for an item in the BST
void Retrieve(TreeNode* root, int item, bool &found) {
    if (root == NULL) {
        // If the tree/subtree is empty, item not found
        found = false;
    } else if (item < root->info) {
        // Search in the left subtree
        Retrieve(root->left, item, found);
    } else if (item > root->info) {
        // Search in the right subtree
        Retrieve(root->right, item, found);
    } else {
        // If the item is found, set found to true
        found = true;
    }
}

// Function to print the tree in-order (sorted order)
void InOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        InOrderTraversal(root->left);          // Visit left subtree
        cout << root->info << " ";             // Visit current node
        InOrderTraversal(root->right);         // Visit right subtree
    }
}

// Main function
int main() {
    TreeNode* root = NULL;  // Start with an empty tree

    // Sample values to insert into BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);  // Number of elements

    // Insert each value into the BST
    for (int i = 0; i < n; i++) {
        root = Insert(root, values[i]);
    }

    // Display the BST in sorted order (In-order Traversal)
    cout << "In-order traversal of BST: ";
    InOrderTraversal(root);
    cout << endl;

    // Ask user for a value to search in the BST
    int item;
    cout << "Enter a number to search in the BST: ";
    cin >> item;

    bool found = false;  // Initialize search result

    // Call the search function
    Retrieve(root, item, found);

    // Display search result
    if (found)
        cout << item << " is found in the BST." << endl;
    else
        cout << item << " is NOT found in the BST." << endl;

    return 0;  // End of program
}
