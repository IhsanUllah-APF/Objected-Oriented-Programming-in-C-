#include<iostream>
#include<string>
using namespace std;

class Employee
{
    public: // make all of following member variables and member functions visibile/accessible from outside class.
    string name; // declaration of member variables of the class.
    int cnic;
    int id;

    void sign_in(); // prototype declaration of a member function of the function.
    void sign_out(); 
};

void Employee :: sign_in()
{
    cout << "Signing in the employee :" << name << endl; // member function sign_in can only be called through
}   // object of the class, such as e1.sign_in(). It means Get inside the object e1 and call it's member function,
    // sign_in. As per cout instruction in this function, the name printed will be the name stored in the variable,
    // name, for this object e1. The dot operator has already been used once when calling the function and musn't
    // be used again in the cout statement within the funciton.

int main()
{
    Employee e1;

    e1.name = "Ali";
    cout << e1.name << endl;
    e1.sign_in();

    Employee *e;
    e = new Employee;
    e -> name = "Usman"; // Go at address, of object, stored in pointer/reference variable, e, and get inside
                        // the object and access member variable, name, and store in it, Usman.
    e -> sign_in(); // Go at address, of object, stored in pointer, e, and get inside the object and call the
                    // member fuction, sign_in.
    return 0;
}