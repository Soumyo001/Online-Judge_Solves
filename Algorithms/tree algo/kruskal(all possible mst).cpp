#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] != vertex)
        parent[vertex] = findParent(parent[vertex], parent);
    return parent[vertex];
}

void unionVertices(int x, int y, vector<int>& parent, vector<int>& rank) {
    int xRoot = findParent(x, parent);
    int yRoot = findParent(y, parent);

    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}
void findAllSpanningTreesHelper(int edgeIndex, int edgeCount, int targetCount, vector<Edge>& edges,
                                vector<int>& parent, vector<int>& rank, vector<vector<Edge>>& spanningTrees) {
    if (edgeCount == targetCount) {
        spanningTrees.push_back(edges);
        return;
    }

    if (edgeIndex == edges.size()) {
        return;
    }

    int srcParent = findParent(edges[edgeIndex].src, parent);
    int destParent = findParent(edges[edgeIndex].dest, parent);

    if (srcParent != destParent) {
        unionVertices(srcParent, destParent, parent, rank);
        findAllSpanningTreesHelper(edgeIndex + 1, edgeCount + 1, targetCount, edges, parent, rank, spanningTrees);
        parent[destParent] = destParent; // backtrack to consider other possible spanning trees
    }

    findAllSpanningTreesHelper(edgeIndex + 1, edgeCount, targetCount, edges, parent, rank, spanningTrees);
}
void findAllSpanningTrees(int numVertices, vector<Edge>& edges, vector<vector<Edge>>& spanningTrees) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);

    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    findAllSpanningTreesHelper(0, 0, numVertices - 1, edges, parent, rank, spanningTrees);
}



int main() {
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, 2},
        {0, 3, 3},
        {1, 2, 4},
        {1, 3, 5},
        {2, 3, 6}
    };

    vector<vector<Edge>> spanningTrees;
    findAllSpanningTrees(numVertices, edges, spanningTrees);

    for (const auto& spanningTree : spanningTrees) {
        for (const auto& edge : spanningTree) {
            cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
        }
        cout << "-------------------" << endl;
    }

    return 0;
}
