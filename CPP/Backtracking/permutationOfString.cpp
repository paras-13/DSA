// Generate permutation of a string
#include <iostream>
#include <string>
using namespace std;
void generatePermutation(string &str, int left, int right) {
    if(left == right)
        cout << str << endl;
    else {
        for(int i=left; i<=right; i++)
        {
            swap(str[left], str[i]);
            generatePermutation(str, left+1, right);
            swap(str[left], str[i]);
        }
    }
}
int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    int n = str.length();
    generatePermutation(str, 0, n-1);
    return 0;
}