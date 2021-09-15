/**
 * Created by Jayce on 2021/7/11.
 * 题目：07-图4 哈利·波特的考试 (25 分)
 * 知识点：最短路
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int N = 1e2 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

inline int read() {
    char ch = getchar();
    int f = 1, x = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f * x;
}

int dis[N][N];

void floyd(int n) {
    rep_(k, 1, n) rep_(i, 1, n) rep_(j, 1, n)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main() {
    int n = read(), m = read(), x, y, z;
    memset(dis, 0x3f, sizeof(dis));
    rep_(i, 1, n) dis[i][i] = 0;
    while (m--) {
        x = read(), y = read(), z = read();
        dis[x][y] = z;
        dis[y][x] = z;
    }
    floyd(n);
    int ans = 0, len = inf, mx;
    rep_(i, 1, n) {
        mx = 0;
        rep_(j, 1, n) mx = max(mx, dis[i][j]);
        if(mx < len) {
            len = mx;
            ans = i;
        }
    }
    if(len == inf) cout << 0;
    else cout << ans << ' ' << len;
    return 0;
}