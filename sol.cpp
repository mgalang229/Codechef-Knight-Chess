#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;        
		vector<long long> x(n), y(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];                                        
		}
		long long a, b;
		cin >> a >> b;
		// view the image in this repository for better understanding
		set<long long> s;
		// store all the possible moves of every knight in a set
		for (int i = 0; i < n; i++) {
 			s.insert((x[i] + 1) + (y[i] + 2));
			s.insert((x[i] - 1) + (y[i] + 2));
			s.insert((x[i] + 2) + (y[i] + 1));
			s.insert((x[i] + 2) + (y[i] - 1));
			s.insert((x[i] + 1) + (y[i] - 2));
			s.insert((x[i] - 1) + (y[i] - 2));
			s.insert((x[i] - 2) + (y[i] + 1));
			s.insert((x[i] - 2) + (y[i] - 1));
		}
		int flag = 0;
		// check if the original position of the king is in check
		// also, check if all the possible moves of the king are blocked by the knights
		// if the king cannot move at all, then it's considered as checkmate
		if (s.find(a + b) != s.end()) {
			flag++;
		} 
		if (s.find(a + (b + 1)) != s.end()) {
			flag++;
		}
		if (s.find((a + 1) + b) != s.end()) {
			flag++; 
		}
		if (s.find(a + (b - 1)) != s.end()) {
			flag++;
		}
		if (s.find((a - 1) + b) != s.end()) {	
			flag++;
		}
		cout << (flag == 5 ? "YES" : "NO") << '\n';	
  	}
	return 0;
}
