/**
 * Created by Jayce on 2021/7/11.
 * 题目：07-图5 Saving James Bond - Hard Version (30 分)
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
int n, d, path[maxn];

double distance(int a, int b) {
    double dx = nodes[a].x - nodes[b].x;
    double dy = nodes[a].y - nodes[b].y;
    return sqrt(dx * dx + dy * dy);
}

bool check_edge(int a) {
    return 50 - abs(nodes[a].x) <= d || 50 - abs(nodes[a].y) <= d;
}

PII bfs(queue<PII> &q) {
    int cur, depth;
    while (!q.empty()) {
        cur = q.front().x;
        depth = q.front().y;
//        tie(cur, depth) = q.front();
        q.pop();
        if(check_edge(cur)) return {cur, depth + 1};
        for_(i, 0, n) {
            if(!vis[i] && distance(i, cur) <= d) {
                vis[i] = 1;
                q.push({i, depth + 1});
                path[i] = cur;
            }
        }
    }
    return {-1, -1};
}

void init(queue<PII> &q) {
    nodes[n].x = nodes[n].y = 0;
    vector<pair<double, int> > first;
    for_(i, 0, n) {
        double dis = distance(i, n);
        if (dis <= 15 / 2.0 + d) {
            path[i] = -1;
            vis[i] = 1;
            first.push_back({dis, i});
        }
    }
    sort(first.begin(), first.end());
    for(auto item : first) q.push({item.y, 1});
}

void print(int a) {
    if(~path[a]) print(path[a]);
    cout << nodes[a].x << ' ' << nodes[a].y << endl;
}

int main() {
    n = read(), d = read();
    if(15 / 2.0 + d >= 50) return 0 * puts("1");
    for_(i, 0, n) nodes[i].x = read(), nodes[i].y = read();

    queue<PII> q;
    init(q);
    PII ans = bfs(q);

    if(~ans.y) {
        cout << ans.y << endl;
        print(ans.x);
    } else puts("0");

    return 0;
}