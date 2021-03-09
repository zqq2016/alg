//
// Created by zhouqq on 2021/3/9.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strstr_kmp.h"

int *gen_next(const char *pattern)
{
    int i;  // 后缀起始位置
    int j = 0;  // 前置起始位置
    size_t len = strlen(pattern);
    int *next = NULL;

    next = malloc(len*sizeof(int));
    if (next == NULL)
    {
        return NULL;
    }
    memset(next, 0, len);
    // 1 初始化next 数组
    next[0] = 0;
    for (i = 1; i < len; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = next[j-1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        next[i] = j;
    }
    return next;
}


const char *strstr_kmp(const char *str, const char *pattern)
{
    int *next = NULL;
    int i = 0, j = 0;
    if (str == NULL || pattern == NULL) return NULL;

    next = gen_next(pattern);
    if (next == NULL) return NULL;

    while (i < strlen(str) && j < strlen(pattern))
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
           if (j == 0)
           {
               i++;
               j = 0;
           }
           else
           {
               j = next[j-1];
           }
        }
        if (j == strlen(pattern))
        {
            free(next);
            return str + i - j;
        }
    }
    free(next);
    return NULL;
}
