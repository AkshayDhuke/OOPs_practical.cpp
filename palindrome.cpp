#include<iostream>
using namespace std;

bool palindrome(string str,int n)
{
    int start=0;
    int end=n-1;
    bool flag=true;
    while ( start < end )
    {
       if(str[start]!=str[end])
       {
       return false;
       }
       start++;
       end--;
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter the String: ";
    cin>>str;
    int n=str.size();
    if ( palindrome(str,n) )
    {
        cout<<"The string \'"<<str<<"\' is a Palindrome."<<endl;
    }
    else
    {
        cout<<"The string \""<<str<<"\" is not a Palindrome."<<endl;
    }
    return 0;
}

// Output:

// Enter the String: 1234321
// The string '1234321' is a Palindrome.

// Enter the String: dffdg
// The string "dffdg" is not a Palindrome.