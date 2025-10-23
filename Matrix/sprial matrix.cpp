#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
       vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;
        int m = matrix[0].size();

        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cout << "Enter rows and columns: ";
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements (row-wise):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    Solution sol;
    vector<int> out = sol.spiralOrder(matrix);
    cout << "Spiral order:\n";
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
    return 0;
}