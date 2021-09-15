/**
 * Created by Jayce on 2021/5/16.
 * 题目：01-复杂度1 最大子列和问题 (20 分)
 * 知识点：dp
 */
#include <stdio.h>
#define max(a, b) a > b ? a : b
int main() {
    int k, ans = 0, sum = 0, tmp;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &tmp);
        sum += tmp;
        if(sum < 0)
            sum = 0;
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}