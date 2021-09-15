/**
 * Created by Jayce on 2021/8/6.
 * 题目：KMP 串的模式匹配 (25 分)
 * 知识点：kmp
 */
#include <stdio.h>
#define N 100005
int next[N];
void build(char pattern[]) {
    int i = 0, j = next[0] = -1;
    while (pattern[i]) {
        while (~j && pattern[i] != pattern[j]) j = next[j];
        next[++i] = ++j;
        if(pattern[i] == pattern[j]) next[i] = -1; //next数组优化成nextval数组next[i] = next[j]
    }
}

int index_kmp(char str[], char pattern[]) {
    int i = 0, j = 0;
    for (; str[i] && pattern[j]; i++, j++)
        while (~j && str[i] != pattern[j]) j = next[j];
    if(!pattern[j]) return i - j;
    return -1;
}

char str[N*10], pattern[N];
int main() {
    freopen("E:\\ProgramData\\CppProjects\\ACM\\input.txt", "r", stdin);
    scanf("%s", str);
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", pattern);
        build(pattern);
        int index = index_kmp(str, pattern);
        if(~index) printf("%s", str + index);
        else printf("Not Found");
        if(n) printf("\n");
    }
}