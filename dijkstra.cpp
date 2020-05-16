#include <bits/stdc++.h>

using namespace std;

/**
 * @brief compute the shortest distance from the starting node to all other nodes.
 *
 * @param n: number of nodes
 * @param edges: weighted edge (node1, node2, weight)
 * @param s: starting node
 * */
vector<int> dikjstra(int n, vector<vector<int>> edges, int s) {
    vector<int> distances(n + 1, INT_MAX);
    distances[s] = 0;

    vector<bool> visited(n, false);

    // Build adjacency matrix;
    vector<vector<int>> adjacent(n + 1);
    map<pair<int, int>, int> costs;
    for (const auto &edge: edges) {
        int parent = edge[0], child = edge[1], cost = edge[2];
        adjacent[parent].push_back(child);
        adjacent[child].push_back(parent);
        costs[{parent, child}] = cost;
        costs[{child, parent}] = cost;
    }

    vector<pair<int, int>> pq = {{s, 0}}; // priorirty queue of distances

    auto compare_min = [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    };

    // Go through each promising node and relax weights
    while (!pq.empty()) {
        auto[node, cost] = pq[0];
        pop_heap(pq.begin(), pq.end(), compare_min);
        pq.pop_back();

        if (visited[node]) continue;
        visited[node] = true;

        for (const auto &child: adjacent[node]) {
            if (visited[child]) continue;
            distances[child] = min(distances[child], costs[{node, child}] + cost);
            pq.push_back({child, distances[child]});
            push_heap(pq.begin(), pq.end(), compare_min);
        }
    }

    vector<int> results;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (distances[i] == INT_MAX) distances[i] = -1;
        results.push_back(distances[i]);
    }

    return results;
}

int main() {
    return 0;
}