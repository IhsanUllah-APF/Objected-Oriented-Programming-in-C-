#include<iostream> 
using namespace std;

//will be done by Photoshop
class Plugin //Declaration of class Plugin.
{
    public:
    virtual void apply_filter(int img[5][5]) = 0; 
    //Declaration of class Plugin pure virtual function, apply_filter(), inside class. 
};

//will be done by Photshop
void Plugin :: apply_filter(int img[5][5]) //Definition of class Plugin function, apply_filter(), outside class.
{
    cout <<"This is class Plugin function, apply_filter(). It does nothing" <<endl;
}

//will be done by Third Pary
class MakeItBlack : public Plugin // Declaration of a child class, MakeItBlack, of a parent, Plugin.
{
    public:
    void apply_filter(int img[5][5]); //Declaration of child class MakeItBlack function, apply_filter(), inside class. 
};

//will be done by Third Party
class MakeItWhite : public Plugin // Declaration of another child class, MakeItWhite, of a parent, Plugin.
{
    public:
    void apply_filter(int img[5][5]); //Declaration of child class MakeItWhite funciton, apply_filter(), inside class.
};

//will be done by Third Party
void MakeItBlack :: apply_filter(int img[5][5]) //Declaration of child class MakeItBlack function, apply_filter().
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            img[i][j] = 0;
        }
    }
}

//will be done by Third Party
void MakeItWhite :: apply_filter(int img[5][5]) //Definition of child class MakeItWhite function, apply_filter().
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            img[i][j] = 255;
        }
    }
}

//will be done by Photoshop
void init_matrix(int a[5][5]); //Declaration of an independent function.
void output_matrix(int a[5][5]); //Declaration of an independent funciton.
Plugin * slect_plugin(); // Declaration of an independent function, which will return Plugin pointer.

//will be done by Photoshop
void init_matrix(int a[5][5]) // Definition of 
{
    int val = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            a[i][j] = val;
            val++;
        }
    }
}

//will be done by Photoshop
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

//will be done by Third Party
Plugin * select_plugin()
{
    string plugin_name;
    plugin_name = "MIW";
    Plugin * p;

    if(plugin_name == "MIW")
    {
        p = new MakeItWhite; //class MakeItWhite is child of class Plugin, so address of it's object can be stored
        return p;           // in Plugin pointer, p.
    }

    else
    {
        p = new MakeItBlack;
        return p;
    }
}

int main() //Execution will start from function main. Note that all classes and functions have been defined before
{           //main.
    int pic[5][5]; // Declaration of integer 5 cross 5 arry, pic. The array will be empty/containing garbage values. 
    Plugin * p; // Declaration of pointer, p, which will store address of an object of type Plugin or it's child.

    init_matrix(pic); //Initialize currently empty array, pic. Return type is not written when function is called. 
                    // pic is integer 5 cross 5 array as required as argument by funciton init_matrix.
    cout <<"Before" <<endl; //

    output_matrix(pic);

    p = select_plugin(); //Plugin pointer, p, contains an address of object of child class.

    p -> apply_filter(pic); 
    // Go at address of object of child class and get in the object and call function, apply_filter. But this will
    // not happen. In fact, during Early Binding, compiler will decide on pointer type, which is Plugin, and execute 
    // apply_filter function in Plugin (parent) class. To ensure that the late binding, which binds the execution 
    // with address contained in pointer (which is the address of object of child class) rather than type of pointer
    // (which is of parent type - Plugin), occurs, we have to add a keyword Virtual to function, apply_filter, in 
    // parent's (Plugin) class. This will make the function virtual, which tells compiler that this is not a real 
    //function and should be overriden by the identical function in a child class. This function, apply_filter, in 
    //parent (Plugin) class can even be made pure virtual by setting it equal to 0. Making this function pure virtual
    //will make the parent (Plugin) class an Abstract class, which means that it's object cannot be created, which
    //makes it impossible for anyone to call apply_filter function in parent class. This is needed sometimes when
    //making an object of a parent's class does not make any sense. For instance, a university may be interested in
    //creating either an object of a faculty or student. Both may have common characteristics (names, phone no., 
    //addresses etc). They may be placed in a parent class, such as person, for ease whereas differences may be kept
    // in child classes of faculty and students. It doesn't make sense for a university to make an object of parent
    //(person). So, parent class may be made a virtual class so that no one can create it's object by making at 
    //least one of its functions pure virtual. Polymorphism means different meaning of a same thing depending on a 
    //context. p -> apply_filter() can call the function in parent's class as well as in child class depending on
    //making the function in parent's class virtual. In other words p -> can mean different things depending on the 
    //context, thus, this is Polymorphism.     

    cout <<"After Application of Plugin " <<endl;

    output_matrix(pic);

    return 0;
}