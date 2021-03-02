#include <bits/stdc++.h>
using namespace std;

enum {RIGHT, LEFT, DOWN, UP}; // 오, 왼, 아, 위

int N;
int board[20][20];
int mx = -1;

void move(int d) {
    queue<int> q;
    switch (d) {
    case RIGHT:
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j] != 0) {
                    q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = N - 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (board[i][idx] == 0)
                    board[i][idx] = cur;
                else if (cur == board[i][idx])
                    board[i][idx--] *= 2;
                else
                    board[i][--idx] = cur;
            }
        }
        break;
    case LEFT:
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != 0) {
                    q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (board[i][idx] == 0)
                    board[i][idx] = cur;
                else if (cur == board[i][idx])
                    board[i][idx++] *= 2;
                else
                    board[i][++idx] = cur;
            }
        }
        break;
    case DOWN:
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                if (board[j][i] != 0) {
                    q.push(board[j][i]);
                    board[j][i] = 0;
                }
            }
            int idx = N - 1;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (board[idx][i] == 0)
                    board[idx][i] = cur;
                else if (cur == board[idx][i])
                    board[idx--][i] *= 2;
                else
                    board[--idx][i] = cur;
            }
        }
        break;
    case UP:
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[j][i] != 0) {
                    q.push(board[j][i]);
                    board[j][i] = 0;
                }
            }
            int idx = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (board[idx][i] == 0)
                    board[idx][i] = cur;
                else if (cur == board[idx][i])
                    board[idx++][i] *= 2;
                else
                    board[++idx][i] = cur;
            }
        }
    }
}

void dfs(int cnt) {
    // 5번 다 옮겼다면 return
    if (cnt == 5) {
        for (int i = 0; i < N; i++)
            mx = max(mx, *max_element(board[i], board[i] + N));
        return;
    }
    // 원래 상태로 돌려주기 위함
    int cpy[20][20] = {0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cpy[i][j] = board[i][j];
    }
    for (int d = RIGHT; d <= UP; d++) {
        move(d);
        dfs(cnt + 1);
        // 원래 상태로 돌리기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                board[i][j] = cpy[i][j];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    dfs(0);
    cout << mx;
    return 0;
}