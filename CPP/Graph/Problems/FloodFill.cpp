// FLood Fill
/*
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. 
Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.

Time Complexity: O(n x m);
Space : O(n x m)
*/
#include <iostream>
#include <vector>
using namespace std;
void floodFill(vector<vector<int>> &grid, int n, int m, int i, int j, vector<int>&dx, vector<int>&dy, int color, int newColor) {
    if(i<0 || j<0 ||i >=n || j>=m || grid[i][j] != color)
        return;
    grid[i][j] = newColor;
    for(int k=0; k<4; k++) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        floodFill(grid, n, m, x, y, dx, dy, color, newColor);
    }
}
void print(vector<vector<int>> &image, int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout << image[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int n, m, newColor, sr, sc;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;
    vector<vector<int>> image(n, vector<int>(m));
    cout << "Enter elements row wise: ";
    for(int i=0; i<n; i++) {
        cout << "Enter row " << i+1 << " :" << endl;
        for(int j=0; j<m; j++) {
            cin >> image[i][j];
        }
    }
    vector<int>dx = {-1, 0, 1, 0};
    vector<int>dy = {0, 1, 0, -1};
    cout << "Enter new color number: ";
    cin >> newColor;
    cout << "Enter starting co-ordinate: ";
    cin >> sr >> sc;
    cout << "Original image: " << endl;
    print(image, n, m);
    if(image[sr][sc] != newColor)
        floodFill(image, n, m, sr, sc, dx, dy, image[sr][sc], newColor);
    cout << "Image after color change: " << endl;
    print(image, n, m);
}