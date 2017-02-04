#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int a, b, c, m;

	cin >> a >> b >> c >> m;

	int val;
	string type;
	priority_queue<int, vector<int>, greater<int>> usb;
	priority_queue<int, vector<int>, greater<int>> ps2;
	for(int i = 0; i < m; ++i) {
		cin >> val >> type;
		if(type == "USB") {
			usb.push(val);
		} else {
			ps2.push(val);
		}
	}

	long long total = 0;
	long long price = 0;	

	while(a > 0 && !usb.empty()) {
		++total;
		price += usb.top();

		--a;
		usb.pop();
	}

	while(b > 0 && !ps2.empty()) {
		++total;
		price += ps2.top();

		--b;
		ps2.pop();
	}

	int u, p;
	while(c > 0 && (!usb.empty() || !ps2.empty())) {
		++total;

		if(!usb.empty() && !ps2.empty()) {
			u = usb.top();
			p = ps2.top();

			if(u > p) {
				price += p;
				ps2.pop();
			} else {	
				price += u;
				usb.pop();
			}
		} else if(!usb.empty()) {
			price += usb.top();
			usb.pop();
		} else {
			price += ps2.top();
			ps2.pop();
		}

		--c;
	}

	cout << total << " " << price << endl;
}
