/*Question#6: Use Dijkstra&#39;s algorithm to find the shortest path from node B to node E
in the graph below.*/

#include <iostream>
#include <string>
using namespace std;

class Graph {
private:
    int nodes;
    int** adjMatrix;
    int* visited;
    int* distance;
    int* previous;
    const int INF = 9999;
    
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
        distance = new int[nodes];
        previous = new int[nodes];
        
        for(int i = 0; i < nodes; i++) {
            visited[i] = 0;
        }
    }
    
    void addWeightedEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; 
    }
    
    int findMinDistance() {
        int minDist = INF;
        int minNode = -1;
        
        for(int i = 0; i < nodes; i++) {
            if(!visited[i] && distance[i] < minDist) {
                minDist = distance[i];
                minNode = i;
            }
        }
        return minNode;
    }
    
    void Dijkstra(int source, int target) {
        for(int i = 0; i < nodes; i++) {
            visited[i] = 0;
            distance[i] = INF;
            previous[i] = -1;
            if(i == source) {
                distance[i] = 0;
            }
        }
        
        while(!visited[target]) {
            int selectedNode = findMinDistance();
            if(selectedNode == -1) break;
            visited[selectedNode] = 1;
            
            for(int v = 0; v < nodes; v++) {
                if(!visited[v] && adjMatrix[selectedNode][v] != 0) {
                    int alt = distance[selectedNode] + adjMatrix[selectedNode][v];
                    if(alt < distance[v]) {
                        distance[v] = alt;
                        previous[v] = selectedNode;
                    }
                }
            }
        }
        printPathAndDistance(source, target);
    }
    
    void printPathAndDistance(int source, int target) {
        cout << "Shortest path from " << char('A' + source) << " to " << char('A' + target) << ": ";
        if(distance[target] == INF) {
            cout << "No path exists" << endl;
            return;
        }
        cout << "Distance = " << distance[target] << ", Path = ";
        printPath(target);
        cout << endl;
    }
    
    void printPath(int node) {
        if(previous[node] == -1) {
            cout << char('A' + node);
            return;
        }
        printPath(previous[node]);
        cout << " -> " << char('A' + node);
    }

    ~Graph() {
        for(int i = 0; i < nodes; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
        delete[] distance;
        delete[] previous;
    }
};

int main() {
    Graph graph(6);
    graph.addWeightedEdge(0, 1, 4);   
    graph.addWeightedEdge(0, 2, 8);  
    graph.addWeightedEdge(1, 2, 9);  
    graph.addWeightedEdge(1, 3, 8); 
    graph.addWeightedEdge(2, 4, 6);   
    graph.addWeightedEdge(3, 4, 14);
    graph.addWeightedEdge(3, 5, 3);  
    graph.addWeightedEdge(4, 5, 9);   
    graph.Dijkstra(1, 4);
}
