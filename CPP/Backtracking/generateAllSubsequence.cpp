// TO generate all subsequence of a string
// Time Complexity: 2^n
#include <iostream>
#include <vector>
using namespace std;
void generate(string str, vector<string> &vec, int n, string s, int i) {
    vec.push_back(s);
    if(i == n)
        return;
    for(int j=i; j<n; j++) {
        s.push_back(str[j]);
        generate(str, vec, n, s, j+1);
        s.pop_back();
    }
}
vector<string>generateAllSubsequence(string str) {
    vector<string>vec;
    int n = str.length();
    generate(str, vec, n, "", 0);
    return vec;
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    vector<string>res = generateAllSubsequence(str);
    for(string st : res)
        cout << st << " ";
}