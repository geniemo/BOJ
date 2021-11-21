#include <bits/stdc++.h>
#define ti11    tuple<int, int, int, int, int, int, int, int, int, int, int>
#define D0      get<0>
#define D1      get<1>
#define D2      get<2>
#define D3      get<3>
#define D4      get<4>
#define D5      get<5>
#define D6      get<6>
#define D7      get<7>
#define D8      get<8>
#define D9      get<9>
#define D10     get<10>
using namespace std;

int dim[11];
vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> v;
queue<ti11> q;
int cnt;

int d0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};
int d1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0};
int d2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0};
int d3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0};
int d4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0};
int d5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d6[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d7[] = {0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d8[] = {0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d9[] = {0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int d10[] = {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void input() {
    for (int i = 0; i < 11; ++i) {
        cin >> dim[i];
    }
    reverse(dim, dim + 11);
    v.resize(dim[0]);
    for (int i0 = 0; i0 < dim[0]; ++i0) {
        v[i0].resize(dim[1]);
        for (int i1 = 0; i1 < dim[1]; ++i1) {
            v[i0][i1].resize(dim[2]);
            for (int i2 = 0; i2 < dim[2]; ++i2) {
                v[i0][i1][i2].resize(dim[3]);
                for (int i3 = 0; i3 < dim[3]; ++i3) {
                    v[i0][i1][i2][i3].resize(dim[4]);
                    for (int i4 = 0; i4 < dim[4]; ++i4) {
                        v[i0][i1][i2][i3][i4].resize(dim[5]);
                        for (int i5 = 0; i5 < dim[5]; ++i5) {
                            v[i0][i1][i2][i3][i4][i5].resize(dim[6]);
                            for (int i6 = 0; i6 < dim[6]; ++i6) {
                                v[i0][i1][i2][i3][i4][i5][i6].resize(dim[7]);
                                for (int i7 = 0; i7 < dim[7]; ++i7) {
                                    v[i0][i1][i2][i3][i4][i5][i6][i7].resize(dim[8]);
                                    for (int i8 = 0; i8 < dim[8]; ++i8) {
                                        v[i0][i1][i2][i3][i4][i5][i6][i7][i8].resize(dim[9]);
                                        for (int i9 = 0; i9 < dim[9]; ++i9) {
                                            v[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9].resize(dim[10]);
                                            for (int i10 = 0; i10 < dim[10]; ++i10) {
                                                cin >> v[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10];
                                                if (v[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 1)
                                                    q.push({i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10});
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool is_out_of_bounds(ti11 pos) {
    return D0(pos) < 0 || D0(pos) >= dim[0] ||
            D1(pos) < 0 || D1(pos) >= dim[1] ||
            D2(pos) < 0 || D2(pos) >= dim[2] ||
            D3(pos) < 0 || D3(pos) >= dim[3] ||
            D4(pos) < 0 || D4(pos) >= dim[4] ||
            D5(pos) < 0 || D5(pos) >= dim[5] ||
            D6(pos) < 0 || D6(pos) >= dim[6] ||
            D7(pos) < 0 || D7(pos) >= dim[7] ||
            D8(pos) < 0 || D8(pos) >= dim[8] ||
            D9(pos) < 0 || D9(pos) >= dim[9] ||
            D10(pos) < 0 || D10(pos) >= dim[10];
}

void spread() {
    int task_cnt = q.size();
    for (int i = 0; i < task_cnt; ++i) {
        ti11 cur = q.front(); q.pop();
        for (int j = 0; j < 22; ++j) {
            ti11 next = {D0(cur) + d0[j],
                        D1(cur) + d1[j],
                        D2(cur) + d2[j],
                        D3(cur) + d3[j],
                        D4(cur) + d4[j],
                        D5(cur) + d5[j],
                        D6(cur) + d6[j],
                        D7(cur) + d7[j],
                        D8(cur) + d8[j],
                        D9(cur) + d9[j],
                        D10(cur) + d10[j]};
            // 토마토밭을 벗어나거나 토마토의 영향을 줄 수 없는 곳이라면 넘어간다
            if (is_out_of_bounds(next) || v[D0(next)][D1(next)][D2(next)][D3(next)][D4(next)][D5(next)][D6(next)][D7(next)][D8(next)][D9(next)][D10(next)] != 0) continue;
            v[D0(next)][D1(next)][D2(next)][D3(next)][D4(next)][D5(next)][D6(next)][D7(next)][D8(next)][D9(next)][D10(next)] = 1;
            q.push(next);
        }
    }
}

bool is_complete() {
    for (int i0 = 0; i0 < dim[0]; ++i0) {
        for (int i1 = 0; i1 < dim[1]; ++i1) {
            for (int i2 = 0; i2 < dim[2]; ++i2) {
                for (int i3 = 0; i3 < dim[3]; ++i3) {
                    for (int i4 = 0; i4 < dim[4]; ++i4) {
                        for (int i5 = 0; i5 < dim[5]; ++i5) {
                            for (int i6 = 0; i6 < dim[6]; ++i6) {
                                for (int i7 = 0; i7 < dim[7]; ++i7) {
                                    for (int i8 = 0; i8 < dim[8]; ++i8) {
                                        for (int i9 = 0; i9 < dim[9]; ++i9) {
                                            for (int i10 = 0; i10 < dim[10]; ++i10) {
                                                if (v[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 0)
                                                    return false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

void sol() {
    while (!q.empty()) {
        spread();
        cnt++;
    }
    cout << (is_complete() ? cnt - 1 : -1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    sol();
    return 0;
}