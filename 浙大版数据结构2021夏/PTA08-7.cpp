/**
 * Created by Jayce on 2021/7/11.
 * 题目：08-图7 公路村村通 (30 分)
 * 知识点：最小生成树
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e3 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

struct edge{
    int a, b, h;
    bool operator < (const edge &ed) {
        return h < ed.h;
    }
}e[maxn * 3];

int fa[maxn];

int find(int x) {
    return fa[x] < 0 ? x : fa[x] = find(fa[x]);
}

int main() {
    int n = read(), m = read(), ans = 0, a, b;
    memset(fa, -1, sizeof(fa));
    bool flag = 0;
    for_(i, 0, m) e[i].a = read(), e[i].b = read(), e[i].h = read();
    sort(e, e + m);
    for_(i, 0, m) {
        a = find(e[i].a), b = find(e[i].b);
        if (a != b) {
            fa[b] += fa[a];
            fa[a] = b;
            ans += e[i].h;
        }
        if (fa[b] == -n) {
            flag = true;
            break;
        }
    }
    if (flag) cout << ans;
    else printf("-1");
    return 0;
}