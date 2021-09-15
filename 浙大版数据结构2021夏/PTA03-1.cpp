/**
 * Created by Jayce on 2021/6/28.
 * 题目：03-树1 树的同构
 * 知识点：树
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

struct Node {
    char ch;
    int left, right;
}node1[10], node2[10];

int x[26], y[26];
int n, tmp;

void init() {
    char a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node1[i].ch >> a >> b;
        node1[i].left = a == '-' ? -1 : a - '0';
        node1[i].right = b == '-' ? -1 : b - '0';
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node2[i].ch >> a >> b;
        node2[i].left = a == '-' ? -1 : a - '0';
        node2[i].right = b == '-' ? -1 : b - '0';
    }
}

int main() {
    init();
    for (int i = 0; i < n; i++) {
        tmp = node1[i].ch - 'A';
        x[tmp] = ~node1[i].left ? node1[node1[i].left].ch : -1;
        y[tmp] = ~node1[i].right ? node1[node1[i].right].ch : -1;
        if (x[tmp] > y[tmp]) swap(x[tmp], y[tmp]);
    }
    for (int i = 0; i < n; i++) {
        tmp = node2[i].ch - 'A';
        int dx = ~node2[i].left ? node2[node2[i].left].ch : -1;
        int dy = ~node2[i].right ? node2[node2[i].right].ch : -1;
        if (dx > dy) swap(dx, dy);
        if (dx != x[tmp] || dy != y[tmp]) return 0 * printf("No");
    }
    printf("Yes");
    return 0;
}