/**
 * Created by Jayce on 2021/7/11.
 * 题目：06-图3 六度空间 (30 分)
 * 知识点：BFS
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

bool vis[maxn];
vector<int> nums[maxn];

int solve(int x) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    int cur, cnt = 1, tail, last = x, depth = 0;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int item : nums[cur]) {
            if(!vis[item]) {
                cnt++;
                vis[item] = 1;
                q.push(item);
                tail = item;
            }
        }
        if(cur == last)
            depth++, last = tail;
        if(depth == 6) break;
    }
    return cnt;
}

int main() {
    int a, b, n = read(), m = read();
    rep_(i, 1, n) nums[i].clear();
    for_(i, 0, m) {
        a = read(), b = read();
        nums[a].push_back(b);
        nums[b].push_back(a);
    }
    rep_(i, 1, n)
        printf("%d: %.2lf%%\n", i, 100.0 * solve(i) / n);
    return 0;
}