/*
BOJ 5639: 이진 검색 트리
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* l = nullptr;
    node* r = nullptr;
};

node* root;

void insert(node* cur, int val) {
    if (cur->val < val) {
        if (cur->r == nullptr) {
            cur->r = new node;
            cur->r->val = val;
        }
        else {
            insert(cur->r, val);
        }
    }
    else {
        if (cur->l == nullptr) {
            cur->l = new node;
            cur->l->val =val;
        }
        else {
            insert(cur->l, val);
        }
    }
}

void postorder(node* cur) {
    if (cur == nullptr) return;
    postorder(cur->l);
    postorder(cur->r);
    cout << cur->val << "\n";
    delete cur;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cur = 0;
    int a;
    cin >> a;
    root = new node;
    root->val = a;
    while (cin >> a) {
        insert(root, a);
    }
    postorder(root);
    return 0;
}