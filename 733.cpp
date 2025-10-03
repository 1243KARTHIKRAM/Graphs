#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int oldcolor, int newcolor)
    {
        int n = image.size();
        int m = image[0].size();

        ans[sr][sc] = newcolor;

        int delrow[] = { -1, 0, 1, 0 };
        int delcol[] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldcolor && ans[nrow][ncol] != newcolor)
            {
                dfs(nrow, ncol, ans, image, oldcolor, newcolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int oldcolor = image[sr][sc];

        vector<vector<int>> ans = image;
        if (oldcolor == color)
            return image;

        dfs(sr, sc, ans, image, oldcolor, color);
        return ans;
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m));
    cout << "Enter the image matrix (row-wise):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cout << "Enter starting row, column, and new color: ";
    cin >> sr >> sc >> color;
    Solution sol;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    cout << "Resulting image after flood fill:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}