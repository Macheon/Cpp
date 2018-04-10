#include "_seive_of_eratosthenes.h"

void _eratosthenes(int *arr, int size) {
	arr[0] = -1;
	for (int i = 2; i < size+1; i++) {
		if (arr[i-1] != -1) {
			for (int j = 2; j <= size/i; j++) arr[j*i-1] = -1;
		}
		else continue;
	}
}