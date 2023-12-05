#include <iostream>
#include <string>
using namespace std;

class student;

class per_info
{
private:
    string lic, dob, blood;

public:
    per_info()
    {
        lic = "Akshay2003";
        dob = "20th dec 2003";
        blood = "A+";
    }

    ~per_info()
    {
        cout << "Personal detailed closed" << endl;
    }

    friend class student;
};

class student
{
private:
    string name, address, year;
    int rollno;
    static int count;
    long long mobile;
    per_info obj; // Add a per_info object here

public:
    student()
    {
        count++;
        name="Akshay";
        address="Pune";
        rollno=26;
        year="SY";
        mobile= 4623743424;
    }

    inline static void incount()
    {
        count++;
    }

    inline static void showcount()
    {
        cout << "The no. of student:- " << count << endl;
    }
    
    ~student()
    {
        cout << "Student detailed closed...." << endl;
    }

    // Copy constructor
    student(const student &obj)
    {
        this->name = obj.name;
        this->address = obj.address;
        this->rollno = obj.rollno;
        this->year = obj.year;
        this->mobile = obj.mobile;
        this->obj = obj.obj; // Copy the per_info object
    }

    void create(per_info &info); // Pass per_info by reference
    void display(per_info &info); // Pass per_info by reference
};

int student::count = 0;

void student::create(per_info &info)
{
    cout << "Enter Name:- ";
    cin >> name;
    cout << "Enter address:- ";
    cin >> address;
    cout << "Roll No.:- ";
    cin >> rollno;
    cout << "Year: ";
    cin >> year;
    cout << "Mobile:- ";
    cin >> mobile;
    // Set personal info from the provided info object
    obj = info;
    cout << "Enter Lic no:- ";
    cin >> obj.lic;
    cout << "Enter Date of Birth:- ";
    cin >> obj.dob;
    cout << "Enter Blood Group:- ";
    cin >> obj.blood;

}

void student::display(per_info &info)
{
    cout << "Name:- " << name << endl;
    cout << "address:- " << address << endl;
    cout << "Roll No.:- " << rollno << endl;
    cout << "year:- " << year << endl;
    cout << "Mobile:- " << mobile << endl;
    cout << "Lic.No.:- " << obj.lic << endl;
    cout << "Date of Birth:- " << obj.dob << endl;
    cout << "Blood Group:- " << obj.blood << endl;
}

int main()
{
    int n;
    int ch;
    char ans;

    cout << "\nENTER NO OF STUDENTS : " << endl;
    cin >> n;

    student *sobj = new student[n];
    per_info *pobj = new per_info[n];

    do
    {
        cout << ("\n Menu \n 1. Create Database \n 2. Display Database \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)");
        cout << "\n Enter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                sobj[i].create(pobj[i]);
                sobj[i].incount();
            }
            break;
        }

        case 2:
        {
            sobj[0].showcount();

            for (int i = 0; i < n; i++)
            {
                sobj[i].display(pobj[i]);
            }
            break;
        }

        case 3:
        {
            student obj1;
            per_info obj2;
            obj1.create(obj2);
            student obj3(obj1);
            cout << "\n Copy Constructor is called \n";
            obj3.display(obj2);
            break;
        }

        case 4:
        {
            student obj1;
            per_info obj2;
            cout << "\n Default Constructor is called \n";
            obj1.display(obj2);
            break;
        }

        case 5:
        {
            delete[] sobj;
            delete[] pobj;
            break;
        }
        }
        cout << "\n Want to continue:(y/n):- ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}