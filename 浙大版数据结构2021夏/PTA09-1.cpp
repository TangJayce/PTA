/**
 * @Auther: Jayce.
 * @Title：09-排序1 排序 (25 分)
 * @Description：sort永远滴神
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int nums[N];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        scanf("%d", nums + i);
    sort(nums, nums + n);
    for (int i = 0; i < n - 1; i ++)
        cout << nums[i] << ' ';
    cout << nums[n - 1];
}