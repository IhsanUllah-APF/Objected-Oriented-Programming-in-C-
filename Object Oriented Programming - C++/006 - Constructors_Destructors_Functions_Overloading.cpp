#include<iostream>
#include<string>
using namespace std;

class Employee // class is key word like strucut and Employee is the datatype like int or float.
{
    public:
        string name; // fields, members or member variables of this class or object of this class.
        int cnic;
        int salary;
        int id;

        void sign_in(); // Methods or member functions of this class or object of this class. 
        void sign_out(); // Protoype Declaration of functions, constructors and destructor.
        Employee(); //contstructor to be called automatically when object of this class is created.
        Employee(int salary); // alternative constructor to be called when salary is passed as argument when object 
                                // of this class is created. Constructor and Destructor have NO return type.
        ~Employee(); // destructor of this class.
};

void Employee :: sign_in() // Employee :: to indicate that this function belongs to class, Employee.
{                           // Definition of this function.
    cout << "Signing in the employee: " << name << endl; // or + name instead of << name
}

Employee :: Employee() // Employee :: to indicate that this function/constructor belongs to class, Employee.
{
    cout << "Object employee created and it's constructor called ... " << endl;
    salary = 10000;
}

Employee :: Employee(int salary)
{
    this -> salary = salary; // this is pointer to object of class, employee, being created for which this constr-
                        // uctor is called. It means that Go at address of this object and get inside it and access
                        // its field or member variable, salary, and make it equal to the local variable, salary.
}

Employee :: ~ Employee() // Destructor of class employee defined here
{
    cout << "Object employee removed " << endl;
}

int main()
{
    Employee *e;

    e = new Employee; // will create object of class Employee in memory alongwith it's all member variables/fields
                        // and methods or member function and store it's address in pointer, e.
    cout << "Salary = " << e -> salary << endl;
    
    delete e; // will delete the address of object of class Employee currently stored in pointer, e. Will delete 
              // the object from HEAP as well.
    e = new Employee(2000); 
    cout << "Salary = " << e -> salary << endl;
    cout << " OR Salary = " << (*e).salary << endl; // Alternatively, use */value at address operator.
    
    delete e;
    e = NULL; // This is must otherwise the salaries are still produced using the following couts.

    cout << "End main" << endl;
    
    return 0;
}






