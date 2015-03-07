#include <deque>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int count_d(int& n, int d) {
	if(!n) {
		return 1000;
	}

	int count = 0;
	while(n % d == 0) {
		++count;
		n /= d;
	}
	return count;
}
  
int main() {
	int n;
	scanf("%d", &n);

	int m_2[n][n];
	int m_5[n][n];
	char path_2[n][n];
	char path_5[n][n];

	int t, f, m;
	bool zero = false;
	int zero_i, zero_j;

	for(int i = 0; i < n; ++i) {
		scanf("%d ", &m);

		if(!m) {
			zero = true;
			zero_i = 0;
			zero_j = i;
		}

		m_2[0][i] = count_d(m, 2);
		m_5[0][i] = count_d(m, 5);

		if(i != 0) {
			m_2[0][i] += m_2[0][i-1];
			m_5[0][i] += m_5[0][i-1];
			path_2[0][i] = 'R';
			path_5[0][i] = 'R';
		}
	}

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d ", &m);

			if(!m) {
				zero = true;
				zero_i = i;
				zero_j = j;
			}

			t = count_d(m, 2);
			f = count_d(m, 5);

			m_2[i][j] = t + m_2[i-1][j];
			m_5[i][j] = f + m_5[i-1][j];
			path_2[i][j] = 'D';
			path_5[i][j] = 'D';

			if(j > 0) {
				t += m_2[i][j-1];
				f += m_5[i][j-1];

				if(t < m_2[i][j]) {
					m_2[i][j] = t;
					path_2[i][j] = 'R';
				}

				if(f < m_5[i][j]) {
					m_5[i][j] = f;
					path_5[i][j] = 'R';
				}
			}
		}
	}

	if(zero && min(m_2[n-1][n-1], m_5[n-1][n-1]) != 0) {
		printf("1\n");
		for(int i = 0; i < zero_i; ++i)
			printf("D");
		for(int j = 0; j < zero_j; ++j)
			printf("R");
		for(int i = zero_i + 1; i < n; ++i)
			printf("D");
		for(int j = zero_j + 1; j < n; ++j)
			printf("R");
		printf("\n");
		return 0;
	}

	int i = n - 1;
	int j = n - 1;
	int size = i + j;
	deque<char> d(size);
	char temp;

	if(m_2[n-1][n-1] <= m_5[n-1][n-1]) {
		printf("%d\n", m_2[n-1][n-1]);
		for(int k = 0; k < size; ++k) {
			temp = path_2[i][j];
			d.push_front(temp);
			if(temp == 'R') {
				--j;
			} else {
				--i;
			}
		}	
	} else {
		printf("%d\n", m_5[n-1][n-1]);
		for(int k = 0; k < size; ++k) {
			temp = path_5[i][j];
			d.push_front(temp);
			if(temp == 'R') {
				--j;
			} else {
				--i;
			}
		}
	}

	for(int k = 0; k < size; ++k) 
		printf("%c", d[k]);
	printf("\n");
}
