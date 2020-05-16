#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Compute the minimum spanning tree of a graph.
 * It can be used to compute how to cheaply connect cities.
 *
 * @param n: number of nodes
 * @param edges: edge (node1, node2, weight)
 * */
int prims(int n, vector<vector<int>> edges) {
    int mst_cost = 0;
    auto compare_min = [](const vector<int>& a, const vector<int>& b){
        return a[2] > b[2];
    };
    make_heap(edges.begin(), edges.end(), compare_min);
    unordered_set<int> visited;

    for(int i = 0; i < n; i++){
        auto node = edges[0];
        int start = node[0], end = node[1], weight = node[2];

        pop_heap(edges.begin(), edges.end(), compare_min); edges.pop_back();

        if (visited.count(start) && visited.count(end)) continue;
        visited.insert(start);
        visited.insert(end);
        mst_cost += weight;
    }

    return mst_cost;
}
