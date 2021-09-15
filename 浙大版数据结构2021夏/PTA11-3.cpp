/**
 * Created by Jayce on 2021/7/22.
 * 题目：11-散列3 QQ帐户的申请与登陆 (25 分)
 * 知识点：散列
 */
#include <bits/stdc++.h>

using namespace std;
#define for_(i, a, b) for(int i=(a);i<(b);++i)
#define rep_(i, a, b) for(int i=(a);i<=(b);++i)
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;

static const auto io_sync_off = []() {
    // 关闭同步
    ios::sync_with_stdio(false);
    // 关闭cin和cout流的绑定
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

map<ll, string> m;

int main() {
    int n;
    char op;
    ll num;
    string pwd;
    cin >> n;
    while (n--) {
        cin >> op >> num >> pwd;
        if(op == 'N') {
            if(m.find(num) == m.end()) m[num] = pwd, puts("New: OK");
            else puts("ERROR: Exist");
        } else {
            if(m.find(num) == m.end()) puts("ERROR: Not Exist");
            else if(m[num] != pwd) puts("ERROR: Wrong PW");
            else puts("Login: OK");
        }
    }
    return 0;
}