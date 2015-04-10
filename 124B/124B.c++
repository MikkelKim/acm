#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool operator < (const string& lhs, const string& rhs) {
	for(int i = 0; i < lhs.size(); ++i) {
		if(lhs[i] < rhs[i]) {
			return true;
		} else if (lhs[i] > rhs[i]) {
			return false;
		}
	}

	return true;
}

int diff(const vector<string>& board, int n) {
	int min = 0;
	int max = 0;

	for(int i = 1; i < n; ++i) {
		if(board[i] < board[min]) {
			min = i;
		} else if(board[max] < board[i]) {
			max = i;
		}
	}

	int ret = atoi(board[max].c_str()) - atoi(board[min].c_str());

	return ret;
}

void permute(vector<string>& board, int index, int& min, int k) {
	if(index == k - 1) {
		int d = diff(board, board.size());
		if(min > d) {
			min = d;
		}
	}

	for(int i = index; i < k; ++i) {
		for(int j = 0; j < board.size(); ++j) {
			swap(board[j][index], board[j][i]);
		}
		permute(board, index + 1, min, k);
		for(int j = 0; j < board.size(); ++j) {
			swap(board[j][index], board[j][i]);
		}
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

    vector<string> board;
    string temp;

    for(int i = 0; i < n; ++i) {
    	cin >> temp;
    	board.push_back(temp);
    }

    int min = 0x7FFFFFFF;
    permute(board, 0, min, k);
    cout << min << endl;
}
