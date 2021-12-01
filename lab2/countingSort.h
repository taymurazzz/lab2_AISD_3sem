#pragma once
#include <iostream>

using namespace std;

void countSort(char* arr, int size) {
	int symCodes[256];
	for (int i=0; i < 256; i++) {
		symCodes[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		symCodes[int(arr[i])] = symCodes[int(arr[i])] + 1;
	}
	int j=0;
	for (int i = 0; i < 256; i++) {
		while (symCodes[i] != 0) {
			arr[j] = i;
			j++;
			symCodes[i] = symCodes[i] - 1;
		}
	}
}