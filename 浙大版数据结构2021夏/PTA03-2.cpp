/**
 * Created by Jayce on 2021/6/28.
 * 题目：03-树2 List Leaves (25 分)
 * 知识点：bfs
 */
#include <bits/stdc++.h>
using namespace std;

static const auto io_sync_off = []() {
    // 关闭同步
    ios::sync_with_stdio(false);
    // 关闭cin和cout流的绑定
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<int> node[10];
int cnt[10];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    int tmp, flag = 0;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (!node[tmp].size()) {
            if (flag)
                cout << ' ';
            else
                flag = 1;
            cout << tmp;
        }
        for (int i = 0; i < node[tmp].size(); i++) {
            q.push(node[tmp][i]);
        }
    }
}

int main() {
    int n;
    char a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a != '-') node[i].push_back(a - '0'), cnt[a - '0']++;
        if (b != '-') node[i].push_back(b - '0'), cnt[b - '0']++;
    }
    int root;
    for (root = 0; root < n; root++)
        if(!cnt[root]) break;
    bfs(root);
    return 0;
}