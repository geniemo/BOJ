#include <bits/stdc++.h>
#define PAIR    pair<int, int>
#define X       first
#define Y       second
using namespace std;

enum {EAST, WEST, SOUTH, NORTH};

int N;
int field[505][505];
PAIR tornado;

int tor_dx[] = {0, 0, 1, -1};
int tor_dy[] = {1, -1, 0, 0};

int dx[4][9] = {
    {-1, 1, -1, 1, -2, 2, -1, 1, 0},
    {-1, 1, -1, 1, -2, 2, -1, 1, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2},
    {1, 1, 0, 0, 0, 0, -1, -1, -2}
};

int dy[4][9] = {
    {-1, -1, 0, 0, 0, 0, 1, 1, 2},
    {1, 1, 0, 0, 0, 0, -1, -1, -2},
    {-1, 1, -1, 1, -2, 2, -1, 1, 0},
    {-1, 1, -1, 1, -2, 2, -1, 1, 0}
};

double percentage[9] = {0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05};

int cnt;

bool is_out(PAIR pos) {
    return !(1 <= pos.X && pos.X <= N && 1 <= pos.Y && pos.Y <= N);
}

void scatter(int dir) {
    PAIR next = {tornado.X + tor_dx[dir], tornado.Y + tor_dy[dir]};
    PAIR dst;
    int a = field[next.X][next.Y];
    int amount;
    for (int i = 0; i < 9; i++) {
        dst = {next.X + dx[dir][i], next.Y + dy[dir][i]};
        amount = field[next.X][next.Y] * percentage[i];
        if (is_out(dst)) cnt += amount;
        else field[dst.X][dst.Y] += amount;
        a -= amount;
    }

    dst = {next.X + tor_dx[dir], next.Y + tor_dy[dir]};
    if (is_out(dst)) cnt += a;
    else field[dst.X][dst.Y] += a;

    field[next.X][next.Y] = 0;
    tornado = next;
}

void foo() {
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < i * 2 + 1; j++)
            scatter(WEST);
        for (int j = 0; j < i * 2 + 1; j++)
            scatter(SOUTH);
        for (int j = 0; j < i * 2 + 2; j++)
            scatter(EAST);
        for (int j = 0; j < i * 2 + 2; j++)
            scatter(NORTH);
    }
    for (int i = 0; i < N - 1; i++)
        scatter(WEST);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    tornado = {N / 2 + 1, N / 2 + 1};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> field[i][j];
    }
    foo();
    cout << cnt;
    return 0;
}