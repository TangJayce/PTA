/**
 * Created by Jayce on 2021/8/6.
 * 题目：11-散列4 Hashing - Hard Version (30 分)
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

int nums[maxn], cnt[maxn], size;
vector<int> mp[maxn];
struct compare {
    bool operator()(int a, int b) {
        return nums[a] > nums[b];
    }
};
void toposort() {
    bool flag = true;
    priority_queue<int, vector<int>, compare> q;
    for_(i, 0, size) if(cnt[i] == 0 && nums[i] >= 0) q.push(i);
    while (!q.empty()) {
        if(flag) flag = false;
        else putchar(' ');
        int cur = q.top();
        cout << nums[cur];
        q.pop();
        for (auto item : mp[cur]) {
            cnt[item]--;
            if(!cnt[item]) q.push(item);
        }
    }
}
int main() {
    size = read();
    for_(i, 0, size) nums[i] = read();
    for_(i, 0, size) {
        if(nums[i] < 0) continue;
        int index = nums[i] % size;
        while (nums[index] != nums[i]) {
            mp[index].push_back(i);
            cnt[i]++;
            index = (index + 1) % size;
        }
    }
    toposort();
    return 0;
}