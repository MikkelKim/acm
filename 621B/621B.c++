#include <stdio.h>
#include <iostream>
#include <unordered_set>

namespace std {
	template <> struct hash<std::pair<int, int>> {
	    inline size_t operator()(const std::pair<int, int> &v) const {
	        std::hash<int> int_hasher;
	        return 1001 * int_hasher(v.first) + int_hasher(v.second);
	    }
	};
}

long long checkUpperLeftDiagonal(const std::unordered_set<std::pair<int, int>>& bishops) {
	long long numUpperLeftDiagonal = 0;
	long long numBishops;

	for(int i = 2; i < 1001; ++i) {
		int j = 1;
		int k = i;
		numBishops = 0;

		while(k > 0 && j < 1001) {
			if(bishops.find(std::make_pair(k, j)) != bishops.end()) {
				++numBishops;
			}

			++j;
			--k;
		}

		if(numBishops > 1) {
			numUpperLeftDiagonal += (numBishops * (numBishops - 1)) / 2;
		}
	}

	return numUpperLeftDiagonal;
}

long long checkLowerLeftDiagonal(const std::unordered_set<std::pair<int, int>>& bishops) {
	long long numLowerLeftDiagonal = 0;
	long long numBishops;

	for(int j = 2; j < 1000; ++j) {
		int i = 1000;
		int k = j;
		numBishops = 0;

		while(i > 0 && k < 1001) {
			if(bishops.find(std::make_pair(i, k)) != bishops.end()) {
				++numBishops;
			}

			--i;
			++k;
		}

		if(numBishops > 1) {
			numLowerLeftDiagonal += (numBishops * (numBishops - 1)) / 2;
		}
	}

	return numLowerLeftDiagonal;
}

long long checkLeftDiagonal(const std::unordered_set<std::pair<int, int>>& bishops) {
	return checkUpperLeftDiagonal(bishops) + checkLowerLeftDiagonal(bishops);
}

long long checkUpperRightDiagonal(const std::unordered_set<std::pair<int, int>>& bishops) {
	long long numUpperRightDiagonal = 0;
	long long numBishops;

	for(int i = 999; i > 0; --i) {
		int j = 1;
		int k = i;
		numBishops = 0;

		while(k < 1001 && j < 1001) {
			if(bishops.find(std::make_pair(k, j)) != bishops.end()) {
				++numBishops;
			}

			++j;
			++k;
		}

		if(numBishops > 1) {
			numUpperRightDiagonal += (numBishops * (numBishops - 1)) / 2;
		}
	}

	return numUpperRightDiagonal;
}

long long checkLowerRightDiagonal(const std::unordered_set<std::pair<int, int>>& bishops) {
	long long numLowerRightDiagonal = 0;
	long long numBishops;

	for(int j = 2; j < 1000; ++j) {
		int i = 1;
		int k = j;
		numBishops = 0;

		while(i < 1001 && k < 1001) {
			if(bishops.find(std::make_pair(i, k)) != bishops.end()) {
				++numBishops;
			}

			++i;
			++k;
		}

		if(numBishops > 1) {
			numLowerRightDiagonal += (numBishops * (numBishops - 1)) / 2;
		}
	}

	return numLowerRightDiagonal;
}

long long checkRightDiagonal(const std::unordered_set<std::pair<int, int>>& bishops) {
	return checkUpperRightDiagonal(bishops) + checkLowerRightDiagonal(bishops);
}

int main() {
	int n;
	scanf("%d", &n);

	int x, y;
	std::unordered_set<std::pair<int, int>> bishops;
	for(int i = 0; i < n; ++i) {
		scanf("%d %d\n", &x, &y);
		bishops.insert(std::make_pair(x, y));
	}

	long long canAttackEachOther = 0;
	canAttackEachOther += checkLeftDiagonal(bishops);
	canAttackEachOther += checkRightDiagonal(bishops);

	std::cout << canAttackEachOther << std::endl;
	return 0;
}