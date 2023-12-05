#include<iostream>

using namespace std;

class account
{
    private:
       string name;
       int age;
       char gender;
       string mono;
       string pan;
       string ac;
    public:
      float b=5000;
      float balance();
      float withD(float);
      float deposit(float);
      void get_info()
      {
        cout <<"Enter Name: ";
        cin >> this->name;
        cout <<"Enter Age: ";
        cin >> age;
        cout <<"Enter Gender(M/F): ";
        cin >> gender;
        cout <<"Enter Mo.No: ";
        cin >> mono;
        cout <<"Enter PAN : ";
        cin >> pan;
        cout << "Enter Account: ";
        cin >> ac;
      }
    void put_info()
    {
        cout <<"Name: " <<name <<"\n";
        cout <<"Gender: " <<gender <<"\n";
        cout <<"Age: " <<age <<"\n";
        cout <<"Mobile Number: " <<mono <<"\n";
        cout <<"PAN: " <<pan <<"\n";
        cout <<"Account Number: " <<ac<<"\n";
        cout <<"Current Balance: " <<b<<"\n";
    }
};

float account::balance()
{
    cout <<"Current Balance=" << b <<"\n";
    return b;
}

float account::withD(float d)
{

    if(b<500)
      cout <<"Insufficient Balance\n";
    else
      b = b-d;
    
    balance();
    return b;
}

float account::deposit(float d)
{
    b+=d;
    balance();
    return b;
}

class Minor: public account
{
    public:
    void display()
    {
        get_info();
        cout <<"Account Details: \n";
        put_info();
    }
};
class Major: public account
{
    public:
    void display()
    {
        get_info();
        cout <<"Account Details: \n";
        put_info();
    }
};
class Joint: public account
{
    public:
    void display()
    {
        get_info();
        cout <<"Account Details: \n";
        put_info();
    }
};

int main()
{
    int c;
    cout <<"1.Minor\n2.Major\n3:Joint\n";
    cout <<"Enter Account Type: ";
    cin >> c;
    switch(c)
    {
        case 1:
        {
            int ch;
            Minor min;
            min.display();
            int con=1;
            while(con!=4)
            {
            cout <<"1:Balance\n2:Withdrawl\n3:Deposit\n4.EXIT\n";
            cin >> ch;
            switch(ch)
            {
                case 1: min.balance();
                        break;
                case 2: float w;
                        cout <<"Enter Amount to Withdrawl: "; 
                        cin >> w;
                        min.withD(w);
                        break;
                case 3: float d;
                        cout <<"Enter Amount to Deposit: ";
                        cin >> d;
                        min.deposit(d);
                        break;
                case 4: cout <<"EXIT";
                        con=4;
                        break;
                default: cout <<"Invalid Choice\n";
            }
            }
            break;
        }
        case 2:{
            int ch;
            Major max;
            max.display();
            int con=1;
            while(con!=4)
            {
            cout <<"1:Balance\n2:Withdrawl\n3:Deposit\n4:EXIT\n";
            cin >> ch;
            switch(ch)
            {
                case 1: max.balance();
                        break;
                case 2: float w;
                        cout <<"Enter Amount to Withdrawl: "; 
                        cin >> w;
                        max.withD(w);
                        break;
                case 3: float d;
                        cout <<"Enter Amount to Deposit: ";
                        cin >> d;
                        max.deposit(d);
                        break;
                case 4:cout <<"EXIT";
                       con=4;
                       break;
                default: cout <<"Invalid Choice\n";
            }
            }
            }
            break;
        case 3:{
            int ch;
            Joint j[2];
            j[0].display();
            j[1].display();
            int con=1;
            while(con!=4)
            {
            cout <<"1:Balance\n2:Withdrawl\n3:Deposit\n4.EXIT\n";
            cin >> ch;
            switch(ch)
            {
                case 1: j[0].balance();
                        break;
                case 2: float w;
                        cout <<"Enter Amount to Withdrawl: "; 
                        cin >> w;
                        j[0].withD(w);
                        break;
                case 3: float d;
                        cout <<"Enter Amount to Deposit: ";
                        cin >> d;
                        j[0].deposit(d);
                        break;
                case 4: cout <<"EXIT\n";
                        con=4;
                        break;
                default: cout <<"Invalid Choice\n";
            }
            }
            
        }
        break;
        default:"Invalid Choice\n";
    }
    return 0;
}