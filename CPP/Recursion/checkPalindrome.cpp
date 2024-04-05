// ? Check Palindrome using Recursion <Intermediate>
#include <iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end)
{
    if(start > end) return true;
        // Empty string is also a palindrome
    if(str[start] == str[end]) {
        return checkPalindrome(str, ++start, --end);
    }
    else return false;

}
int main()
{
    string str;
    cin >> str;
    cout << checkPalindrome(str, 0, str.length()-1) << endl;
}