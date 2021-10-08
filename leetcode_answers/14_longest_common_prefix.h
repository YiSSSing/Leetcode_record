#pragma once

#include <stdio.h>
#include <xhash>


char* commonPrefix(char* leftStr, char* rightStr)
{
    int len = strlen(leftStr) < strlen(rightStr) ? strlen(leftStr) : strlen(rightStr);
    char* str = (char*)malloc((len + 1) * sizeof(char));
    memset(str, '\0', len + 1);
    for (int i = 0; i < len; i++)
    {
        if (leftStr[i] != rightStr[i])
        {
            strncpy(str, leftStr, i);
            return str;
        }
    }
    strncpy(str, leftStr, len);
    return str;
}

char* recurse(char** strs, int start, int end)
{
    if (start == end) return strs[start];
    int mid = (end - start) / 2 + start;
    char* leftStr = recurse(strs, start, mid);
    char* rightStr = recurse(strs, mid + 1, end);

    return commonPrefix(leftStr, rightStr);
}

char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strsSize <= 0) return "";
    return recurse(strs, 0, strsSize - 1);
}

void CheckAnswer()
{
    char arr[] = "abcd";
    char brr[] = "abcefg";
    char crr[] = "abfhe";
    char** carray = (char**)malloc(sizeof(char*) * 3);
    *carray = arr;
    *(carray + 1) = brr;
    *(carray + 2) = crr;
    printf("%s\n", longestCommonPrefix(carray, 3));
}