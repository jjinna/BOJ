#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int sum = 0;
vector<int> pick;
int input[9];
bool visited[9] = { true, };
bool result[9] = { false, };
void finding(vector<int> &pick) {
	//base case
	if (pick.size() == 2) {
		if (input[pick[0]] + input[pick[1]] == sum - 100) {
			result[pick[0]] = true; result[pick[1]] = true;
		}
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (result[i] != false) return;
	}
	
	int index = pick.empty() ? 0 : pick.back() + 1;
	for (int i = index; i < 9; i++) {
		visited[i] = true;
		pick.push_back(i);

		finding(pick);
		
		visited[i] = false;
		pick.pop_back();
	}

}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> input[i];
		sum += input[i];
	}

	sort(input, input + 9);

	finding(pick);

	for (int i = 0; i < 9; i++) {
		if (result[i] == false)	cout << input[i] << endl;
	}
}