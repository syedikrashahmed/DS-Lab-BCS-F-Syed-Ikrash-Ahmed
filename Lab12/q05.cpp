/*Question#5: For the following graph implement the following:
Create an Adjacency List and Adjacency Matrix. Display the list and matrix.
Traverse the graph using BFS and DFS.
Display the output for both the traversals.*/

#include <iostream>
#include <string>
using namespace std;

class Graph {
private:
    int nodes;
    int** adjMatrix;
    int* visited;
    
public:
    Graph(int n) : nodes(n) {
        adjMatrix = new int*[nodes];
        for(int i = 0; i < nodes; i++) {
            adjMatrix[i] = new int[nodes];
            for(int j = 0; j < nodes; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        
        visited = new int[nodes];
        for(int i = 0; i < nodes; i++) {
            visited[i] = 0;
        }
    }
    
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }
    
    void displayAdjMatrix() {
        for(int i = 0; i < nodes; i++) {
            cout << i << " ";
        }
        cout << endl;
        
        for(int i = 0; i < nodes; i++) {
            cout << i << " ";
            for(int j = 0; j < nodes; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void displayAdjList() {
        for(int i = 0; i < nodes; i++) {
            cout << i << ",";
            bool firstConnection = true;
            for(int j = 0; j < nodes; j++) {
                if(adjMatrix[i][j] == 1) {
                    if(!firstConnection) cout << ",";
                    cout << j;
                    firstConnection = false;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void BFS(int startNode) {
        for(int i = 0; i < nodes; i++) {
            visited[i] = 0;
        }
        
        int* temp = new int[nodes];
        int start = 0, end = 0;
        
        visited[startNode] = 1;
        temp[end++] = startNode;
        
        while(start < end) {
            int currentNode = temp[start++];
            cout << currentNode << " ";
            
            for(int i = 0; i < nodes; i++) {
                if(adjMatrix[currentNode][i] == 1 && !visited[i]) {
                    visited[i] = 1;
                    temp[end++] = i;
                }
            }
        }
        cout << endl;
        delete[] temp;
    }
    
    void dfs(int currentNode) {
        visited[currentNode] = 1;
        cout << currentNode << " ";
        
        for(int i = 0; i < nodes; i++) {
            if(adjMatrix[currentNode][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }
    
    void DFS(int startNode) {
        for(int i = 0; i < nodes; i++) {
            visited[i] = 0;
        }
        dfs(startNode);
    }

    ~Graph() {
        for(int i = 0; i < nodes; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
    }
};

int main() {
    Graph network(5);
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 3);
    network.addEdge(1, 4);
    network.addEdge(2, 3);
    network.addEdge(3, 4);
    network.displayAdjList();
    network.displayAdjMatrix();
    network.BFS(0);
    network.DFS(0);
}
