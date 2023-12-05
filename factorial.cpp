#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n!=0)
    {
        return n*factorial(n-1);
    }
    else
    return 1;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int fact=factorial(n);
    cout<<"Factorial of "<<n<<" is "<<fact<<endl;
    return 0;
}

// Output:
// Enter the number: 6
// Factorial of 6 is 720