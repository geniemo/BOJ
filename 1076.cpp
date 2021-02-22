#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    unordered_map<string, pair<int, long long>> color;
    color["black"] = {0, 1};
    color["brown"] = {1, 10};
    color["red"] = {2, 100};
    color["orange"] = {3, 1000};
    color["yellow"] = {4, 10000};
    color["green"] = {5, 100000};
    color["blue"] = {6, 1000000};
    color["violet"] = {7, 10000000};
    color["grey"] = {8, 100000000};
    color["white"] = {9, 1000000000};

    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    cout << (color[c1].first * 10 + color[c2].first) * color[c3].second;
    return 0;
}