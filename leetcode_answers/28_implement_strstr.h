#pragma once
#include <memory>

int strStr(char* haystack, char* needle) {
	int len1 = strlen(haystack), len2 = strlen(needle);
	if (len2 == 0) return 0;
	else if (len1 == 0 || len2 > len1) return -1;

	for (int i = 0; i < len1 - len2 + 1; i++)
	{
		if (haystack[i] == needle[0])
		{
			int j = i + 1, k = 1;
			for (k; k < len2; k++)
				if (haystack[j++] != needle[k]) break;
			if (k == len2) return i;
		}
	}
	return -1;
}