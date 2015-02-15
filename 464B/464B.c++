#include <cmath>
#include <stdio.h>
#include <iostream>

using namespace std;

const double EPSILON = 0.3;

void permute(int* c, int x) {
	if(x == 0)
		return;
	else if(x == 1) {
		c[1] ^= c[2];
		c[2] ^= c[1];
		c[1] ^= c[2];
	} else if(x == 2) {
		c[0] ^= c[2];
		c[2] ^= c[0];
		c[0] ^= c[2];
	} else if(x == 3) {
		c[1] ^= c[2];
		c[2] ^= c[1];
		c[1] ^= c[2];
	} else if(x == 4) {
		c[0] ^= c[2];
		c[2] ^= c[0];
		c[0] ^= c[2];
	} else if(x == 5) {
		c[1] ^= c[2];
		c[2] ^= c[1];
		c[1] ^= c[2];
	}
}

float distance(int* a, int* b) {
	return sqrt(pow((a[0] - b[0]), 2) + pow((a[1] - b[1]), 2) + pow((a[2] - b[2]), 2));
}

bool verify(int (&cube)[8][3]) {
	long a;
	long b;
	long c;

	float cur[8];
	float min;
	for(int i = 0; i < 8; ++i) {
		min = 100000000000;
		a = 0; b = 0; c = 0;
		fill(cur, cur+8, 0);
		for(int j = 0; j < 8; ++j) {
			if(i != j) {
				cur[j] = distance(cube[i], cube[j]);
				if(cur[j] < min)
					min = cur[j];
			}
		}


		for(int j = 0; j < 8; ++j) {
			if(i != j) {
				if(min == cur[j]) {
					++a;
				} else if(abs((min * sqrt(2)) - cur[j]) < EPSILON) {
					++b;
				} else if(abs((min * sqrt(3)) - cur[j]) < EPSILON) {
					++c;
				} 
			}
		}
		if(a != 3 || b != 3 || c != 1)
			return false;
	}
	return true;
}

int main() {
	int cube[8][3];
	for(int i = 0; i < 8; ++i) {
		scanf("%d %d %d", &cube[i][0], &cube[i][1], &cube[i][2]);
	}

	for(int a = 0; a < 6; ++a) {
		permute(cube[0], a);
		for(int b = 0; b < 6; ++b) {
			permute(cube[1], b);
			for(int c = 0; c < 6; ++c) {
				permute(cube[2], c);
				for(int d = 0; d < 6; ++d) {
					permute(cube[3], d);
					for(int e = 0; e < 6; ++e) {
						permute(cube[4], e);
						for(int f = 0; f < 6; ++f) {
							permute(cube[5], f);
							for(int g = 0; g < 6; ++g) {
								permute(cube[6], g);
								for(int h = 0; h < 6; ++h) {
									permute(cube[7], h);
									if(verify(cube)) {
										printf("YES\n");
										for(int i = 0; i < 8; ++i)
											printf("%d %d %d\n", cube[i][0], cube[i][1], cube[i][2]);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("NO\n");
}