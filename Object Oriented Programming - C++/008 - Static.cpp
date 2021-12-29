#include<iostream>
#include<string>
using namespace std;

class User
{
    int id;
    static int next_id;

    public:
    static int next_user_id();
    User();
    int get_id();
};

int User::next_id = 0; //static variable can be approached from outside class only through class (class name and ::)
                        // no need to write down static with it again.

int User::next_user_id()
{
    next_id ++; // since function & variable both are static, therefore, when used together, the variable name does
    return next_id; // not need to have the class name.
}

User::User()
{
    id = User::next_user_id(); // Class name and :: must be used even when static function is called within body.
}

int User::get_id() // Here class name and :: have been used though get_id() is not a static funciton. Thus, at the
{                   // time of defining member function, class name and :: must be used even if the member function
    return id;      // is not a static one. But in the body when non-static function is called, then it will carry
}                   // the instance name and not class name and ::. Contrary to this, when a static function is
                    // called in the body, it must carry class name and ::.
                    //SUMMARY SO FAR: Class name and :: must be used when static variable and function are used
                    // irrespective of place of use. But non-static variables and functions will use only object
                    // name and not class name and :: except at the time of definition before {.
                    
int main()
{
    User U;
    cout <<"User U id: " <<U.get_id() <<endl; // since this is an object member or non-static function, therefore,
                                            // we can access it through object name and dot operator.
    User V;
    cout <<"User V id: " <<V.get_id() <<endl;

    return 0;
} 