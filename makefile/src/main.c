//
// Created by DEIN2023 on 2025/6/25.
//
#include<stdio.h>
#include "math.h"
#include "utils.h"

int main() {
    int a, b;
    printf("请输入两个整数：\n");
    scanf("%d %d", &a, &b);
    printf("%d\n", add(a, b));
    printf("%d\n", sub(a, b));
}