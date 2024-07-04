// Backtracking approach to find all subset of a set
#include <iostream>
#include <vector>
using namespace std;

void generateSubset(vector<int> set, int i, vector<int> temp, vector<vector<int>> &subset) {
    subset.push_back(temp);

    //base case
    if(i == set.size())
        return;

    for(int j=i; j<set.size(); j++) {
        temp.push_back(set[j]);
        generateSubset(set, j+1, temp, subset);
        temp.pop_back();
    }
}
int main() {
    vector<vector<int>> subset;
    int n, val;
    cout << "Enter size of set: ";
    cin >> n;
    vector<int>set;
    cout << "Enter elements of set: ";
    for(int i=0; i<n; i++) {
        cin >> val;
        set.push_back(val);
    }
    generateSubset(set, 0, {}, subset);
    for(int i=0; i<subset.size(); i++) {
        for(int j=0; j<subset[i].size(); j++) 
            cout << subset[i][j] << " ";
        cout << endl;
    }

}