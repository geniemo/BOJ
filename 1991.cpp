#include <bits/stdc++.h>
using namespace std;

int N;
int tree[26][2];
char node, l, r;

void preorder(int node) {
    if (node == -1)
        return;
    cout << static_cast<char>(node + 'A');
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

void inorder(int node) {
    if (node == -1)
        return;
    inorder(tree[node][0]);
    cout << static_cast<char>(node + 'A');
    inorder(tree[node][1]);
}

void postorder(int node) {
    if (node == -1)
        return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    cout << static_cast<char>(node + 'A');
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> node >> l >> r;
        tree[node - 'A'][0] = (l == '.') ? -1 : l - 'A';
        tree[node - 'A'][1] = (r == '.') ? -1 : r - 'A';
    }
    preorder(0); cout << '\n';
    inorder(0); cout << '\n';
    postorder(0);
    return 0;
}