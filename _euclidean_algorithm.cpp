#include"_euclidean_algorithm.h"

int _euclidean(int a, int b) {
	int m, n, temp;
	if (a > b) {
		m = a;
		n = b;
	}
	while (m%n != 0) {
		temp = m%n;
		m = n;
		n = temp;
	}
	return n;
}