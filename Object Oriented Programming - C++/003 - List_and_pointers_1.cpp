#include<iostream>
#include<string>
using namespace std;

struct student
{
    int rollno;
    string name;

};

int main()
{
    student s1;
    s1.name = "Ali";

    student *s;
    s = &s1;

    
    cout << "&s1 = " << &s1 << endl;
    cout << "pointer, s =" << s << endl;
   //cout << "*s =" << *s << endl; // will give error since s is pointing to s1 which contains two values (name and
                                // rollno. So, we need to tell which value we want to produce)
    cout << "name in s1 = " << (*s).name << endl;
    // OR
    cout << "s -> name = " << s -> name << endl; // s -> is exactly same as (*s). So, s -> name is same as (*s).name

    // Use of new to create a new student:

    s = new student; // will create new instance of type student and return its address to be saved in pointer, s.
    cout << "Address of the new instance is: " << s << endl;
    s -> name = "Usman"; // same as (*s).name = "Usman". Go inside the address contained in pointer,s, which is the
                        // address of new instance of type student and in the new instance, access member variable,
                        // name, and store in it Usman.
    (*s).name = "Usman";
    cout << "value in name in new instance is: " << (*s).name << endl;

    // delete new instance, created with new, to free up the memory.
    delete s; // works with instances created with new only. The pointer will still contain the address of the new
            //instance and new instance will still carry the value (Usman) but the memory will be available for
            // reallocation & won't be kept reserved for this program by OS. Operators - arrow, new, and delete.
    cout << "Address contained in s after deletion = " << s << endl;
     



    

    return 0;
}