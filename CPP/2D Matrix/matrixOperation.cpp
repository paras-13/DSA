// Addition and Subtraction in Matrix
#include <iostream>
#include <vector>
using namespace std;
class Matrix {
    private:
    vector<vector<int>>matrix;
    int n, m;
    public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        matrix.resize(n, vector<int>(m));
    }
    void addElement() {
        int val;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << "[" << i << "][" << j << "]: ";
                cin >> val;
                matrix[i][j] = val;
            }
        }
    }
    vector<vector<int>> getMatrix(){
        return matrix;
    }
    void print() {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) 
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

// Adding two Matrix
void addMatrix(vector<vector<int>>M1, vector<vector<int>>M2, vector<vector<int>>&matrix){
    int r = M1.size();
    int c = M1[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            matrix[i][j] = M1[i][j] + M2[i][j];
    }
}

// Subtracting Two Matrix
void subtractMatrix(vector<vector<int>> M1, vector<vector<int>> M2, vector<vector<int>>&matrix) {
    int r = M1.size();
    int c = M1[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            matrix[i][j] = M1[i][j] - M2[i][j];
    }
}

void printMatrix(vector<vector<int>>&matrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int n1, n2, m1, m2;
    cout << "Matrix 1: " << endl;
    cout << "Enter number of rows and columns: ";
    cin >> n1 >> n2;
    Matrix M1(n1, n2);
    cout << "Enter elements: ";
    M1.addElement();

    cout << endl << "Matrix 2: " << endl;
    cout << "Enter number of rows and columns: ";
    cin >> m1 >> m2;
    Matrix M2(m1, m2);
    cout << "Enter elements: ";
    M2.addElement();

    vector<vector<int>>matrix1(n1, vector<int>(m2));
    vector<vector<int>>matrix2(n1, vector<int>(m2));

    addMatrix(M1.getMatrix(), M2.getMatrix(), matrix1);
    subtractMatrix(M1.getMatrix(), M2.getMatrix(), matrix2);
    cout << endl << "Matrix 1: "<<endl;
    M1.print();
    cout << endl << "Matrix 2: " << endl;
    M2.print();

    cout << endl << "After adding two matrices: " << endl;
    printMatrix(matrix1);
    cout << endl << "After subtracting two matrices: " << endl;
    printMatrix(matrix2);
}