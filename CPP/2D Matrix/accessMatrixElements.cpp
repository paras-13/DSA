// Access Matrix Elements;
#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = {
                        {1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9}
                    };
    
    // Accessing elements from 2D array:
    cout << "First element of first row: " << arr[0][0]
         << "\n";
    cout << "Third element of second row: " << arr[1][2]
         << "\n";
    cout << "Second element of third row: " << arr[2][1]
         << "\n";

}