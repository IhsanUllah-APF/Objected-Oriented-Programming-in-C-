#include<iostream>
#include<string>
using namespace std;
// SEE THE OTHER FILE FOR SHORT AND DIRECT CONCEPT OF VIRTUAL FUNCTION AND POLYMORPHISM. May be the same happens
// when people add different packages to open source softwares. Polymorphism is ...
class Plugin // abstract class. Cannot make it's object. 
{
    public:
    virtual void apply_filter(int img[5][5]) = 0; // it has no body.
    //{
        
   // }
};
// Why to make abstract class? Suppose, we are basically interested in faculty and students. They both share some
// common characters such as names, addresses, and phone numbers. This common characteristics can be placed together
// in parent abstract class, whereas unique information can be placed in both, faculty and students, child classes.
// In this context, we are essentially interested in making object of either student or faculty, and without either
// of these two, it does not make sense for a university to have an object of parent class, person, itself. And we
// do not want anyone to make an object of person so we make it abstract which serves the purpose of keeping common
//information and also prevents its object being made.
class MakeItWhite : public Plugin
{
    public:
    void apply_filter(int img[5][5])
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                img[i][j] = 255;
            }
        }
    }
};

class MakeItBlack : public Plugin
{
    public:
    void apply_filter(int img[5][5])
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                img[i][j] = 0;
            }
        }
    }

};

void init_matrix(int a[5][5]); 
void output_matrix(int a[5][5]); 
Plugin * select_plugin(); // may be this is a function which will return plugin (datatye) pointer.

// these functions are independent functions. these functions have been declared before main but defined after main 
// and called from within manin. 

int main()
{
    int pic[5][5];

    init_matrix(pic);

    cout <<"Before: " <<endl;

    output_matrix(pic);

    //Plugin p; // create an object of class Plugin.
    //p.apply_filter(pic); // calling apply_filter() in class plugin.

    //Plugin *p1; // Extra work

    //MakeItBlack mib; // create an object of type/class MakeItBlack and name it, mib. Main plus extra work.
    //mib.apply_filter(pic); // Can't do this since third party would make this class.

    //p1 = &mib; // though it contains address of object of child class, MakeItBlack,but still it will call function in
    //p1 -> apply_filter(pic); // parent class, Plugin. These two instructions are extra work.

    // Go inside the object, mib, and call function apply_filter in child class, MakeItBlack, since the object                     
    // belongs to this class. So, the rule is the object will first search a function or variable in it's own class
    // and then in it's parent's class.

    //cout <<"After MakeItBlack: " <<endl;
    //output_matrix(pic);

    //MakeItWhite miw; // same interpretation as above in MakeItBlack.
    //miw.apply_filter(pic);

    //cout <<"After MakeItWhite: " <<endl;
    //output_matrix(pic);

    //init_matrix(pic);

    
    // return 0;

    // Let's do it another way...

    Plugin *p;

    p = select_plugin(); // function call and store the returned value/address in Plugin pointer, p.
    p -> apply_filter(pic); // 
    cout <<"After Plugin Application: " <<endl;
    output_matrix(pic);

    return 0;

}

Plugin * select_plugin() // definition of the function plugin whose return type is plugin pointer.
{
    string plugin_name = "MIB"; // declaration and initialization of local string variable, plugin_name.

    Plugin *p; // declaration of plugin pointer, p. This is also local.

    if(plugin_name == "MIW") 
        p = new MakeItWhite; // no {} because the body of if contains only one instruction.

    else
        p = new MakeItBlack;

    return p; // returning plugin pointer, p, as required in the return type.
    
    // check the if condition. If true, then create an object of class MakeItWhite, dynmic memory allocation,     
    // and store it's address in plugin pointer, p. Note that We are storing address of an object of a child class
    // (MakeItWhite - a seperate user defined data type as well) in pointer of parent's class (plugin - a seperate
    //  user defined data type. p is a plugin pointer). Do similar interpretation for MakeItBlack in else block.          
}

void init_matrix(int a[5][5])
{
    int val = 0; // declaration and initialization of integer variable, val.

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            a[i][j] = val;
            val++;
        }
    }
}

void output_matrix(int a[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout <<a[i][j] <<" ";
        }
        cout <<endl;
    }
}