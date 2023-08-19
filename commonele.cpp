// You are using GCC
// Hello C++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2, i, j;
    int commonsize = 0;
    int common[100];
    
    cin >>n1; 
    int arr1[n1];
    for(i=0; i<n1; i++)
    cin >> arr1[i];
    
    cin >> n2;
    int arr2[n2];
    for(i=0; i<n2; i++)
    cin >> arr2[i];
    cout << "Common Elements: ";
    for(i=0; i<n1; i++)
    {
        for(j=0; j<n2; j++)
        {
            if(arr1[i] == arr2[j])
            {
            common[commonsize++] = arr1[i];
            break;
            }
        }
    }
    
    if(commonsize == 0) cout <<"None";
    else{
        for(i=0; i<commonsize; i++)
        cout << common[i] << " ";
    }
    
}
