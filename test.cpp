#include<bits/stdc++.h>

using namespace std;

int main() {
	srand (time(NULL));
	int T = rand() % 99   + 1;
	cout << T << '\n';
	vector<stack<vector<int>>> MOVES;
	while (T--) {
		int N = rand() % (int(2 * 1e1) - 1LL)  + 3; // 3 -> 20
		int K = rand() % N  + 1;
		cout << N << " " << K << '\n';
		vector<int> a(N + 1);
		for (int i = 1 ; i <= N ; ++i)
			a[i] = i ;
		stack<vector<int>> moves;
		while (K--) {
			int p1 = rand() % N + 1, p2, p3;
			while (true) {
				p2 = rand() % N + 1;
				if (p1 != p2) break;
			}
			while (true) {
				p3 = rand() % N + 1;
				if ( p1 != p3 && p2 != p3) break;
			}
			moves.push({p1, p2, p3});
			int temp = a[p1];
			a[p1] = a[p2];
			a[p2] = a[p3];
			a[p3] = temp;
		}
		MOVES.push_back(moves);
		for (int i = 1;  i <= N ; ++i) cout << a[i] << " ";
		cout << '\n';
	}
	for ( stack<vector<int>> moves : MOVES) {
		while (!moves.empty()) {
			vector<int> move = moves.top();
			moves.pop();
			cerr << '\t' << move[0] << " " << move[1] << " " << move[2] << '\n';
		}
		cerr << '\n';
	}
}
