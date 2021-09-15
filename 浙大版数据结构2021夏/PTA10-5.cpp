/**
 * Created by Jayce on 2021/8/6.
 * 题目：10-排序5 PAT Judge (25 分)
 * 知识点：简单排序
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

int score[5];
struct user {
    int id, grade[5], total, successed;
    user() {total = -1; memset(grade, -1, sizeof(grade));}
    bool operator < (const user &another) const {
        if(total != another.total) return total > another.total;
        if(successed != another.successed) return successed > another.successed;
        return id < another.id;
    }
}users[maxn];

int main() {
    int n = read(), k = read(), m = read();
    for_(i, 0, n) users[i].id = i + 1;
    for_(i, 0, k) score[i] = read();
    while (m--) {
        int a = read(), b = read(), c = read();
        int &num = users[a - 1].grade[b - 1], &tol = users[a - 1].total;
        if(c == -1) {
            num = max(num, 0);
            continue;
        }
        if(tol == -1) tol = 0;
        if(c > num) {
            if(~num) tol += c - num;
            else tol += c;
            num = c;
            if(c == score[b - 1]) users[a - 1].successed++;
        }
    }
    sort(users, users + n);
    int cur = 1;
    for_(i, 0, n) {
        cout << cur << ' ';
        printf("%05d %d", users[i].id, users[i].total);
        for_(j, 0, k) {
            cout << ' ';
            if(~users[i].grade[j]) cout << users[i].grade[j];
            else cout << '-';
        }
        if(users[i + 1].total == -1) break;
        if(users[i].total != users[i + 1].total) cur = i + 2;
        cout << endl;
    }
    return 0;
}