#include<iostream>
using namespace std;

int CountExtremeNumber(int n, float a[][100]) {
	int countResult = 0;
	for (int i = 1; i < n-1; i++)
		for (int j = 1; j < n-1; j++) {
			int count1 = 0, count2 = 0;
			for (int k = i - 1; k <= i + 1; k++) {
				if (a[i][j] > a[k][j - 1])
					count1++;
				else if (a[i][j] < a[k][j - 1])
					count2++;
			}
			for (int k = i - 1; k <= i + 1; k += 2) {
				if (a[i][j] > a[k][j])
					count1++;
				else if (a[i][j] < a[k][j])
					count2++;
			}
			for (int k = i - 1; k <= i + 1; k++) {
				if (a[i][j] > a[k][j + 1])
					count1++;
				else if (a[i][j] < a[k][j + 1])
					count2++;
			}
			if (count1 == 8 || count2 == 8)
				countResult++;
		}
	return countResult;
}

void Input(int& n, float a[][100]) {
	cout << "Input row & column: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "The input matrix is: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "    ";
		cout << endl;
	}
}

int main() {
	int n;
	float a[50][100];
	Input(n, a);
	int count = CountExtremeNumber(n, a);
	cout << "The number of extreme elements in matrix is " << count;
}