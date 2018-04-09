#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

#define MAX 10000

//이게 문제
int arr[MAX] = { 0, };

inline void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
inline void showArr() {
	for (int sidx = 0; sidx < MAX; sidx++) {
		cout << arr[sidx] << " ";
	}
	cout << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	srand((unsigned int)time(NULL));
	int i, j;
	int r_time, r_cases, r_sum;
	int p_time, cases, sum;
	double r_ave, ave;
	bool time_out, sorted;

	cases = 0;
	ave = 0;
	sum = 0;

	r_cases = 0;
	r_ave = 0;
	r_sum = 0;

	cout << "Rec. start\n";
	while (true) {
		time_out = false;
		r_time = GetTickCount();
		arr[0] = 0;
		//arr, inx 초기화
		for (i = 1; i < MAX; i++) {
			arr[i] = arr[i - 1] + 1;
		}
		//arr shuffle
		for (i = 0; i < MAX; i++) {
			swap(&arr[i], &arr[rand() % MAX]);
		}
		r_time = GetTickCount() - r_time;
		r_sum += r_time;
		r_cases += 1;
		r_ave = (double)r_sum / (double)r_cases;
		cout << "Arr. Maked// ";
		cout << "Case : " << r_cases << " Time record : " << r_time << "ms, Ave : " << r_ave << "ms\n";

		//start
		p_time = GetTickCount();

		for (i = 0; i < MAX; i++) {
			int idx = i;
			int min = arr[i];
			for (j = i; j < MAX; j++) {
				if (min > arr[j]) {
					min = arr[j];
					idx = j;
				}
			}
			swap(&arr[i], &arr[idx]);
		}

		//end
		p_time = GetTickCount() - p_time;
		cout << "Sort. Ended// ";
		sorted = true;
		for (int i = 1; i < MAX; i++) {
			if (arr[i - 1] > arr[i]) {
				sorted = false;
				break;
			}
		}
		if (sorted)cout << "( ** sorted ** )  ";
		else { cout << "( ** ERROR ** )"; }
		if (time_out == false) {
			cases += 1;
			sum += p_time;
			ave = (double)sum / (double)cases;
			cout << "Case : " << cases << " Time record : " << p_time << "ms, Ave : " << ave << "ms\n";
		}
	}

	int q;
	cin >> q;
}
