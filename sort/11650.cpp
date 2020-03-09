#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int input1, input2;
	vector < pair<int, int>> input;
	while (n--) {
		cin >> input1 >> input2;
		input.push_back(make_pair(input1, input2));
	}

	sort(input.begin(), input.end());

	for (int i = 0; i < input.size(); i++) {
		cout << input[i].first <<" "<< input[i].second << '\n';
	}
}