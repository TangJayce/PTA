/**
 * Created by Jayce on 2021/5/18.
 * 题目：02-线性结构4 Pop Sequence
 * 知识点：堆栈
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct SNode{
    ElementType data;
    struct SNode *next;
}SNode, *LinkNode;

typedef struct LinkStack{
    int size;
    LinkNode top;
}*stack;

stack CreateStack() {
    stack s = (stack)malloc(sizeof(struct LinkStack));
    s->top = NULL;
    s->size = 0;
    return s;
}
int is_empty(stack s) {
    return s->top == NULL;
}
void push(stack s, ElementType item) {
    SNode* tmp = (SNode*)malloc(sizeof(SNode));
    tmp->data = item;
    tmp->next = s->top;
    s->top = tmp;
    s->size++;
}
ElementType pop(stack s) {
    if(is_empty(s)) return NULL;
    LinkNode top_cell = s->top;
    s->top = top_cell->next;
    ElementType top_elem = top_cell->data;
    free(top_cell);
    s->size--;
    return top_elem;
}
ElementType top(stack s) {
    if(s->top) return s->top->data;
    return NULL;
}

int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    stack s = CreateStack();
    int num, index, flag;
    for (int i = 0; i < k; i++) {
        while (!is_empty(s)) pop(s);
        index = flag = 1;
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            if(!flag) continue;
            while (is_empty(s) || top(s) != num) {
                push(s, index++);
                if (s->size > m) {
                    flag = 0;
                    break;
                }
            }
            if (top(s) == num) pop(s);
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
