#include "ascii.h"
#include <stdio.h>

wchar_t ExtendAscii(char c) {
	if (c < 0) {
		switch (c) {
			case -55: return L'╔';
			case -51: return L'═';
			case -42: return L'╓';
			case -38: return L'┌';
			case -60: return L'─';
			case -73: return L'╖';
			case -77: return L'│';
			case -70: return L'║';
			case -68: return L'╝';
			case -44: return L'╘';
			default: printf("%d\n", (int)c);
		}
	}
	return (wchar_t)c;
}
