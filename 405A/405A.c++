#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int numRow;
	cin >> numRow;

	int boxes[numRow];
	int box;

	for(int i = 0; i < numRow; ++i){
		cin >> box;
		boxes[i] = box;
	}

	sort(boxes, boxes+numRow);

	for(int i = 0; i < numRow; ++i)
		cout << boxes[i] << " ";

	cout << endl;
}