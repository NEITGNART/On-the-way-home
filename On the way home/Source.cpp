#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> grid) {
	
	int row = grid.size();
	int col = grid[0].size();

	for (int i = 0; i < row; ++i) {
		grid[i][col - 1] = 1;
	}
	for (int j = 0; j < col; ++j) {
		grid[row - 1][j] = 1;
	}

	for (int i = row - 2; i >= 0; i--) {
		for (int j = col - 2; j >= 0; j--) {
			grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
		}
	}
	return grid[0][0];
}

int main(void) {

	int row = 3;
	int col = 3;
	vector<vector<int>> grid;

	for (int i = 0; i < row; ++i) {
		
		vector<int> temp;

		for (int j = 0; j < col; ++j) {
			temp.push_back(0);
		}
		grid.push_back(temp);
	}

	cout << "Have " << solve(grid) << " ways to come home." << endl;
	return 0;
}