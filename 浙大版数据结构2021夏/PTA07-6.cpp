/**
 * Created by Jayce on 2021/7/11.
 * 题目：07-图6 旅游规划 (25 分)
 * 知识点：最短路
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> PII;
const int maxn = 505, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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
    int next, len, val;
    bool operator < (const edge &e) const {
        if(len == e.len) return val > e.val;
        return len > e.len;
    }
};

vector<edge> mp[maxn];
int dis[maxn], cost[maxn];
bool vis[maxn];

void spfa(int begin) {
    memset(dis, 0x3f, sizeof(dis));
    memset(cost, 0x3f, sizeof(cost));
    memset(vis, 0, sizeof(vis));
    cost[begin] = dis[begin] = 0;
    vis[begin] = true;
    queue<int> q;
    q.push(begin);
    int cur, node, len, value;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        vis[cur] = false;
        for (auto item : mp[cur]) {
            node = item.next, len = item.len, value = item.val;
            if(dis[cur] + len < dis[node]) {
                dis[node] = dis[cur] + len;
                cost[node] = cost[cur] + value;
                if(!vis[node]) {
                    vis[node] = true;
                    q.push(node);
                }
            } else if(dis[cur] + len == dis[node])
                cost[node] = min(cost[node], cost[cur] + value);
        }
    }
}

int main() {
    int n = read(), m = read(), begin = read(), end = read();
    int x, y, l, v;
    for_(i, 0, m) {
        x = read(), y = read(), l = read(), v = read();
        mp[x].push_back({y, l, v});
        mp[y].push_back({x, l, v});
    }
    spfa(begin);
    cout << dis[end] << ' ' << cost[end];
    return 0;
}