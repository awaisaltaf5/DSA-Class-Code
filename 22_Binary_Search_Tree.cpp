#include <iostream>      // For input and output
using namespace std;

// Define the structure for a node in the Binary Search Tree
struct TreeNode {
    int info;              // The value stored in this node
    TreeNode* left;        // Pointer to left child (smaller value)
    TreeNode* right;       // Pointer to right child (larger value)
};

// Function to insert a value into the BST
TreeNode* Insert(TreeNode* root, int value) {
    // Base case: If tree or subtree is empty, create a new node
    if (root == NULL) {
        TreeNode* newNode = new TreeNode;
        newNode->info = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;  // Return the new node to be connected by parent
    }

    // Recursively go to left or right subtree based on value
    if (value < root->info) {
        // Value is smaller, go to left subtree
        root->left = Insert(root->left, value);
    } else if (value > root->info) {
        // Value is greater, go to right subtree
        root->right = Insert(root->right, value);
    }

    // If value already exists, do not insert (no duplicates in BST)
    return root;  // Return the unchanged root pointer
}

// Function to search for a value in the BST
void Retrieve(TreeNode* root, int item, bool &found) {
    if (root == NULL) {
        // Reached an empty subtree, item not found
        found = false;
    } else if (item < root->info) {
        // Search in the left subtree
        Retrieve(root->left, item, found);
    } else if (item > root->info) {
        // Search in the right subtree
        Retrieve(root->right, item, found);
    } else {
        // Value matches the current node, item found
        found = true;
    }
}

// In-order traversal: prints the BST in sorted order
void InOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        InOrderTraversal(root->left);          // Visit left subtree
        cout << root->info << " ";             // Visit current node
        InOrderTraversal(root->right);         // Visit right subtree
    }
}

int main() {
    TreeNode* root = NULL;  // Start with an empty tree

    // Sample values to insert into BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);  // Number of elements

    // Insert each value into the BST
    for (int i = 0; i < n; i++) {
        root = Insert(root, values[i]);
    }

    // Display the BST in sorted order
    cout << "In-order traversal of BST: ";
    InOrderTraversal(root);
    cout << endl;

    // Prompt user to enter a value to search
    int item;
    cout << "Enter a number to search in the BST: ";
    cin >> item;

    bool found = false;  // Initialize search result

    // Call the search function
    Retrieve(root, item, found);

    // Display result
    if (found)
        cout << item << " is found in the BST." << endl;
    else
        cout << item << " is NOT found in the BST." << endl;

    return 0;  // End of program
}
