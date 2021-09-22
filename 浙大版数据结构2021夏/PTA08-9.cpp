/**
 * Created by Jayce on 2021/7/22.
 * 题目：08-图9 关键活动 (30 分)
 * 知识点：拓扑排序
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
#define x first
#define y second
typedef pair<int, int> PII;
typedef long long ll;
const int maxn = 1e2 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

vector<PII> e[maxn], re[maxn];
int ans, n, m, out[maxn], in[maxn], cost[maxn], rcost[maxn];

bool topo() {
    queue<int> q;
    rep_(i, 1, n) if(in[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int tmp = q.front();
        cnt++;
        q.pop();
        for (auto item : e[tmp]) {
            in[item.x]--;
            cost[item.x] = max(cost[item.x], cost[tmp] + item.y);
            if(in[item.x] == 0) q.push(item.x);
        }
    }
    return cnt == n;
}

void retopo() {
    rep_(i, 1, n) ans = max(ans, cost[i]);
    queue<int> q;
    rep_(i, 1, n) {
        rcost[i] = ans;
        if (out[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (auto item : re[tmp]) {
            out[item.x]--;
            rcost[item.x] = min(rcost[item.x], rcost[tmp] - item.y);
            if(out[item.x] == 0) q.push(item.x);
        }
    }
}

void print() {
    cout << ans << endl;
    rep_(i, 1, n)
        if(cost[i] == rcost[i])
            for (int j = e[i].size() - 1; ~j; j--) {
                int cur = e[i][j].x, len = e[i][j].y;
                if(cost[i] == rcost[cur] - len)
                    cout << i << "->" << cur << endl;
            }
}

int main() {
    n = read(), m = read();
    while (m--) {
        int a = read(), b = read(), c = read();
        e[a].push_back({b, c});
        re[b].push_back({a, c});
        in[b]++;
        out[a]++;
    }
    if(topo()) {
        retopo();
        print();
    } else cout << 0;
    return 0;
}