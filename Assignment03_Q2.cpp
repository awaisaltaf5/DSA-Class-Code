#include <iostream>
using namespace std;
void display_Matrix  (int matrix[][11], int vertices) {
    cout << "Adjacency Matrix:" <<endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << "      ";
        }
        cout << endl;
    }
}

int main() {
    const int vertices = 11;
    int adjacencyMatrix[11][11] = {0}; 
    int edges[][2] = { 
        {0, 1}, {0, 4}, {1, 2}, {1, 4}, {1, 5}, 
        {4, 3}, {4, 7}, {4, 5}, {5, 2}, {5, 6}, 
        {3, 7}, {3, 8}, {8, 9}, {9, 7}, {9, 10}, 
        {7, 6}, {7, 10} 
    };

    int numberOfEdges   = sizeof(edges) / sizeof(edges[0]);

    for (int i    = 0; i < numberOfEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyMatrix[u] [v] = 1;
    }

    display_Matrix  (adjacencyMatrix, vertices);

    return 0;
}
