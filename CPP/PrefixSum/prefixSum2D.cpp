// 2D prefixSum pattern
// To find a submatrix sum
// Pattern is that
// Formula
// prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];

// To find for submatrix, we will just mold this formula
// submatrix area = prefixSum[i][j] + prefixSum[i-1][j-1] - prefixSum[i-1][j] - prefixSum[i][j-1];
#include <iostream>
#include <vector>
using namespace std;
class Solve
{
private:
    vector<vector<long long>> prefixSum;

public:
    Solve(vector<vector<int>> &matrix, int n, int m)
    {
        prefixSum.resize(n + 1, vector<long long>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }
    int findArea(int x1, int y1, int x2, int y2)
    {
        long long area = prefixSum[x2][y2] + prefixSum[x1 - 1][y1 - 1] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1];
        return area;
    }
};
int main()
{
    int n, m, q;
    cout << "Enter number of rows in matrix: ";
    cin >> n;
    cout << "Enter number of columns in matrix: ";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter elements in matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements in row " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter number of queries you want to make: ";
    cin >> q;
    Solve obj1(matrix, n, m);
    while (q--)
    {
        int x1, y1, x2, y2;
        cout << "Enter top-left and bottom-right co-ordinates (1 based): ";
        cin >> x1 >> y1 >> x2 >> y2;
        long long area = obj1.findArea(x1, y1, x2, y2);
        cout << "Area of sub-matrix is: " << area << endl;
    }
    return 0;
}