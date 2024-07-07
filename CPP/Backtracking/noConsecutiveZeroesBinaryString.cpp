// To generate a binary string of n numbers with no consecutive zeroes.
#include <iostream>
#include <vector>
using namespace std;

void generateString(int n, int ptr, string str, vector<string>&res) {
    if(ptr == n){
        res.push_back(str);
        return;
    }
    if(str == "" || str.back() == '1')
        generateString(n, ptr + 1, str + '0', res);
    generateString(n, ptr + 1, str + '1', res);
}
int main() {
    vector <string> result;
    int n;
    cout << "Enter length of string to generate: ";
    cin >> n;
    generateString(n, 0, "", result);
    for(string x : result)
        cout << x << " ";
}