/**
 * Created by Jayce on 2021/5/16.
 * 题目：01-复杂度2 Maximum Subsequence Sum (25 分)
 * 知识点：dp
 */
#include <stdio.h>
#define inf 0x3f3f3f3f
int nums[10005], k;
int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) scanf("%d", nums + i);
    int ans = -inf, sum = 0, l = -1, r = -1, index = -1;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
        if(sum > ans) {
            ans = sum;
            l = index + 1;
            r = i;
        }
        if(sum < 0) {
            sum = 0;
            index = i;
        }
    }
    if(ans < 0)
        printf("0 %d %d\n", nums[0], nums[k - 1]);
    else
        printf("%d %d %d\n", ans, nums[l], nums[r]);
    return 0;
}