#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> matrix(v, vector<int>(v, 0)); 
    for(int i = 0; i < e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    cout << "Adjacency Matrix:" << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
