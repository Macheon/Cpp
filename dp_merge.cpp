#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

#define MAX 1000000

//이게 문제
int arr[MAX] = { 0, };
int inx[MAX] = { 0, };
int m[MAX] = { 0, };

inline void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	srand((unsigned int)time(NULL));
	int i, j;
	int p_time, cases,sum;
	double ave;
	bool time_out, sorted;
	int le, re, size, r, l, sL, sR, move;

	cases = 0;
	ave = 0;
	sum = 0;

	cout << "Rec. start\n";
	while (true) {
		time_out = false;
		arr[0] = 0;
		inx[0] = 0;
		//arr, inx 초기화
		for (i = 1; i < MAX; i++) {
			arr[i] = arr[i - 1] + 1;
			inx[i] = inx[i - 1] + 1;
		}
		//arr shuffle
		for (i = 0; i < MAX; i++) {
			swap(&arr[i], &arr[rand() % MAX]);
			swap(&arr[i], &arr[rand() % MAX]);
		}
		cout << "Arr. Maked// ";

		//start
		p_time = GetTickCount();
		move = 0;
		for (int z = 0; z < MAX;z++) {
			le = inx[move];
			re = inx[le + 1];

			sL = le + 1;
			sR = re + 1;
			size = re - move + 1;

			l = move;
			r = le + 1;

			for (i = 0; i < size; i++) m[i] = ( r >= sR || (l < sL && arr[l] < arr[r]) ) ? arr[l++] : arr[r++];
			for (i = move, j = 0; i < sR; i++, j++) {
				arr[i] = m[j];
				inx[i] = re;
			};
			move = (sR < MAX) ? sR : 0;
			//if (cases != 0 && GetTickCount() - p_time > ave * 2) { cout << "**Timeout****Timeout****Timeout****Timeout****Timeout**\n"; time_out = true; break; }
		}{
		p_time = GetTickCount() - p_time;
		//end
		sorted = true;
		for (int i = 1; i < MAX; i++) {
			if (arr[i - 1] > arr[i]) {
				sorted = false;
				break;
			}
		}
		cout << "( ** sorted ** )  ";
		if (time_out == false) 
			cases += 1;
			sum += p_time;
			ave = (double)sum / (double)cases;
			cout << "Case : " << cases << " Time record : " << p_time << "ms, Ave : " << ave << "ms\n";
		}
		else {
			for (i = 0; i < MAX; i++) {
				cout << inx[i]<<" ";
			}
			break;
		}
	}

	int q;
	cin >> q;
}
