#include <iostream>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int remainingPillow = m - n;
    int maxHeight = 1;
    int beg = k - 1;
    int end = n - k;
    int left = 0;
    int right = 0;

    while(left + right < remainingPillow && (left < beg || right < end))
    {
        remainingPillow = remainingPillow - left - right - 1;
        ++maxHeight;
        if(left < beg){
        	++left;
        }
        if(right < end) {
        	++right;
        }
    }
    maxHeight = maxHeight + remainingPillow / n;
    cout<< maxHeight << endl;
}
