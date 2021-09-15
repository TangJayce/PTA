/**
 * Created by Jayce on 2021/7/11.
 * 题目：06-图2 Saving James Bond - Easy Version (25 分)
 * 知识点：bfs
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

PII nodes[maxn];
bool vis[maxn];
int n, d;

double distance(int a, int b) {
    double dx = nodes[a].x - nodes[b].x;
    double dy = nodes[a].y - nodes[b].y;
    return sqrt(dx * dx + dy * dy);
}

bool check_edge(int a) {
    return 50 - abs(nodes[a].x) <= d || 50 - abs(nodes[a].y) <= d;
}

bool bfs(queue<int> &q) {
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if(check_edge(cur)) return true;
        for_(i, 0, n) {
            if(!vis[i] && distance(i, cur) <= d) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    n = read(), d = read();
    for_(i, 0, n) nodes[i].x = read(),nodes[i].y = read();
    nodes[n].x = nodes[n].y = 0;
    queue<int> q;
    for_(i, 0, n) if (distance(n, i) <= 15 / 2.0 + d) vis[i] = 1, q.push(i);
    if(bfs(q)) cout << "Yes";
    else cout << "No";
    return 0;
}