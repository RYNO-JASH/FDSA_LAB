#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Practical 9 - Problem 1: Disaster Relief Earthquake Building Inspection (DFS & BFS)
class CityGraph {
private:
    int numBuildings;
    vector<vector<int>> adjList;

    // Helper function for Depth-First Search (Team 1)
    void dfsHelper(int current, vector<bool>& visited, vector<int>& visitOrder) {
        visited[current] = true;
        visitOrder.push_back(current);

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited, visitOrder);
            }
        }
    }

public:
    CityGraph(int n) {
        numBuildings = n;
        adjList.resize(n);
    }

    // Add road connecting building u and building v (undirected graph)
    void addRoad(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort adjacency lists to ensure deterministic traversal order
    void sortAdjacencyList() {
        for (int i = 0; i < numBuildings; i++) {
            sort(adjList[i].begin(), adjList[i].end());
        }
    }

    // Team 1: Depth-First Search (DFS)
    // Goes as deep into each road as possible before backtracking
    vector<int> performDFS(int startBuilding) {
        vector<bool> visited(numBuildings, false);
        vector<int> visitOrder;
        dfsHelper(startBuilding, visited, visitOrder);
        return visitOrder;
    }

    // Team 2: Breadth-First Search (BFS)
    // Spreads out level by level using a FIFO Queue
    vector<int> performBFS(int startBuilding) {
        vector<bool> visited(numBuildings, false);
        vector<int> visitOrder;
        queue<int> q;

        visited[startBuilding] = true;
        q.push(startBuilding);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            visitOrder.push_back(current);

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return visitOrder;
    }
};

int main() {
    int n, m;
    cout << "===== Practical 9 - Problem 1: Earthquake Disaster Relief Building Inspection =====" << endl;
    cout << "Enter number of buildings (e.g., 6, numbered 0 to " << "n-1): ";
    cin >> n;
    cout << "Enter number of connecting roads: ";
    cin >> m;

    CityGraph city(n);
    cout << "Enter each road as two connected building numbers (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Road " << (i + 1) << ": ";
        cin >> u >> v;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            city.addRoad(u, v);
        } else {
            cout << "Invalid building numbers! Must be between 0 and " << n - 1 << endl;
            i--;
        }
    }

    city.sortAdjacencyList();

    int startBuilding;
    cout << "\nEnter starting building ID for relief teams: ";
    cin >> startBuilding;

    if (startBuilding < 0 || startBuilding >= n) {
        cout << "Invalid starting building! Defaulting to 0." << endl;
        startBuilding = 0;
    }

    // Run DFS (Team 1)
    vector<int> dfsResult = city.performDFS(startBuilding);
    cout << "\n--------------------------------------------------" << endl;
    cout << "Team 1 Inspection Order (DFS - Deep Dive & Backtrack):" << endl;
    for (size_t i = 0; i < dfsResult.size(); i++) {
        cout << dfsResult[i];
        if (i + 1 < dfsResult.size()) cout << " -> ";
    }
    cout << endl;

    // Run BFS (Team 2)
    vector<int> bfsResult = city.performBFS(startBuilding);
    cout << "\nTeam 2 Inspection Order (BFS - Level by Level Radial Spread):" << endl;
    for (size_t i = 0; i < bfsResult.size(); i++) {
        cout << bfsResult[i];
        if (i + 1 < bfsResult.size()) cout << " -> ";
    }
    cout << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}
