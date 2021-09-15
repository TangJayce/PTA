/**
 * Created by Jayce on 2021/6/29.
 * 题目：05-树8 File Transfer (25 分)
 * 知识点：并查集
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int fa[maxn], nums[maxn];
int n, a, b;

int find(int x) {
    return fa[x] < 0 ? x : fa[x] = find(fa[x]);
}

void Input() {
    scanf("%d%d", &a, &b);
    fa[find(a)] = find(b);
}

void Check() {
    scanf("%d%d", &a, &b);
    if(find(a) == find(b))
        puts("yes");
    else
        puts("no");
}

void Stop() {
    int cnt = 0;
    rep_(i, 1, n) if(fa[i] < 0) cnt++;
    if(cnt == 1)
        printf("The network is connected.");
    else
        printf("There are %d components.", cnt);
}

int main() {
    char c;
    scanf("%d", &n);
    memset(fa, -1, sizeof(fa));
    do {
        scanf(" %c", &c);
        switch (c) {
            case 'I': Input(); break;
            case 'C': Check(); break;
            case 'S': Stop(); break;
        }
    } while (c != 'S');
    return 0;
}