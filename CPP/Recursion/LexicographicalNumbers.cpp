// Problem link -- > https://leetcode.com/problems/lexicographical-numbers/description/
#include <iostream>
#include <vector>
using namespace std;
void findOrder(vector<int> &v, int n, int num) {
    if(num > n)
        return;
    v.push_back(num);
    for(int i=0; i<=9; i++) {
        if(num*10 + i > n)
            return;
        findOrder(v, n, num*10 + i);
    }
    return;
}
vector<int> lexicalOrder(int n) {
    vector<int>v;
    for(int i=1; i<=9; i++) {
        if(i > n)
            break;
        findOrder(v, n, i);
    }
    return v;
}
int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector<int>LexOrder = lexicalOrder(n);
    for(int i=0; i<n; i++)
        cout << LexOrder[i] << " ";
}