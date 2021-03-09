//
// Created by zhouqq on 2021/3/9.
//

#include <stdio.h>
#include <string.h>
#include "strstr_bf.h"

/*
 * 当字符串和子串不匹配时,将字符串和子串都进行回溯, 时间复杂度为O(mn)
 */
#if 0
const char *strstr_bf(const char *buf, const char *pattern)
{
    int i = 0,j = 0;
    int buf_len = strlen(buf);
    int pattern_len = strlen(pattern);

    if (buf == NULL || pattern == NULL) return NULL;

    for (i = 0 ; i < buf_len; i++)
    {
        for (j = 0; j < pattern_len; j++)
        {
            if (buf[i+j] != pattern[j])
            {
                break;
            }
        }
        if (j == pattern_len)
        {
            return buf + i;
        }
    }
    return NULL;
}
#else
const char *strstr_bf(const char *buf, const char *pattern)
{
    int i = 0,j = 0;
    int buf_len = strlen(buf);
    int pattern_len = strlen(pattern);

    if (buf == NULL || pattern == NULL) return NULL;

    while (i < buf_len && j < pattern_len)
    {
        if (buf[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i-j+1;
            j = 0;
        }
        if (j == pattern_len)
        {
            return buf + i - j;
        }
    }
    return NULL;
}
#endif

