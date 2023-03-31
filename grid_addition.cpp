#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Please enter the desired grid dimension: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> max_sum(n, vector<int>(n));
    vector<vector<int>> min_sum(n, vector<int>(n));

    cout << "Please enter the desired input:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            max_sum[i][j] = grid[i][j];
            min_sum[i][j] = grid[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                max_sum[i][j] = max(max_sum[i-1][j-1], max_sum[i-1][j]);
                min_sum[i][j] = min(min_sum[i-1][j-1], min_sum[i-1][j]);
            }
            if (j < n-1) {
                max_sum[i][j] = max(max_sum[i][j], max_sum[i-1][j+1]);
                min_sum[i][j] = min(min_sum[i][j], min_sum[i-1][j+1]);
            }
            max_sum[i][j] += grid[i][j];
            min_sum[i][j] += grid[i][j];
        }
    }

    int highest_sum = *max_element(max_sum[n-1].begin(), max_sum[n-1].end());
    int lowest_sum = *min_element(min_sum[n-1].begin(), min_sum[n-1].end());

    cout << "Highest Sum: " << highest_sum << endl;
    cout << "Lowest Sum: " << lowest_sum << endl;

    return 0;
}
