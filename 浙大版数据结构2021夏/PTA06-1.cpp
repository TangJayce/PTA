/**
 * Created by Jayce on 2021/7/5.
 * 题目：06-图1 列出连通集 (25 分)
 * 知识点：搜索
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

vector<int> nums[15];
bool vis[15];

void dfs(int x) {
    cout << x << ' ';
    for (int i : nums[x]) if(!vis[i]) vis[i] = 1, dfs(i);
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i : nums[cur])
            if(!vis[i]) vis[i] = 1, q.push(i);
    }
}

int main() {
    int a, b, n = read(), e = read();
    bool flag = true;
    for_(i, 0, e) {
        a = read(), b = read();
        nums[a].push_back(b);
        nums[b].push_back(a);
    }
    for_(i, 0, n) sort(nums[i].begin(), nums[i].end());
    memset(vis, 0, sizeof(vis));
    for_(i, 0, n) {
        if(!vis[i]) {
            if(flag) flag = 0;
            else cout << endl;
            cout << "{ ";
            vis[i] = 1;
            dfs(i);
            cout << "}";
        }
    }
    memset(vis, 0, sizeof(vis));
    for_(i, 0, n) {
        if(!vis[i]) {
            if(flag) flag = 0;
            else cout << endl;
            cout << "{ ";
            vis[i] = 1;
            bfs(i);
            cout << "}";
        }
    }
    return 0;
}