#include <bits/stdc++.h>

using namespace std;

void update(int *tree, int N, int pos, int val) {
    int diff = val - tree[pos];
    bool done = false;
    while (true) {
        tree[pos] += diff;
        pos = (pos - 1) / 2;
        if (done) break;
        if (pos == 0) done = true;
    }
}

int query(int *tree, int N, int nodeL, int nodeR, int queryL, int queryR, int node) {
    cout << "Node: " << node << "\tRange: " << nodeL << ", " << nodeR << "\t" << "\tQuery : " << queryL << ", " << queryR << "\t" << node << endl;

    // Query range is outside node range.   (0, 1) (2N, 2N) (3, 4)
    if ((nodeL > queryR) || (nodeR < queryL)) return 0;

    // Node range is completely inside query range.  (2, 3)N (2, 5)Q
    if (nodeL >= queryL && nodeR <= queryR) { return tree[node - 1]; }

    // Query range partially overlaps node range
    int mid = (nodeL + nodeR) / 2;
    int ll = query(tree, N, nodeL, mid, queryL, queryR, 2 * node);
    int rr = query(tree, N, mid + 1, nodeR, queryL, queryR, 2 * node + 1);

    return ll + rr;
}


int main() {
    int k;
    cin >> k;
    int arr[k];

    for (int i = 0; i < k; i++) cin >> arr[i];

    int N = 2 * k - 1;
    int *tree = new int[N];

    fill(tree, tree + N, 0); // fill the tree with all zeros

    for (int i = 0; i < k; i++) {
        update(tree, N, N - i - 1, arr[i]);
    }

    for (int i = 0; i < N; i++)
        cout << tree[i] << " ";
    cout << endl;

    int q;
    cin >> q;
    int l, r;
    cin >> l >> r;
    cout << l << "\t" << r << endl;
    std::reverse(tree, tree + N);
    cout << query(tree, N, 0, k - 1, l, r, 1) << endl;

    // for(int i = 0; i < 1; i++){
    //     int l, r;
    //     cin >> r >> r;
    //     cout << l << ", " << r << "\t" << endl;
    //     auto res = query(tree, N, 0, k - 1, l, r, 0);
    //     cout << "Result : " << res << endl;
    // }
    return 0;

}