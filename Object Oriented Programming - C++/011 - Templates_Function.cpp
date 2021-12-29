#include<iostream>
#include<string>
using namespace std;

//Templates help generalize functions and classes.

template <class T> 
//declaration of template. template and class are key words. This syntax tells compiler to have a place holder, T, 
// which be replaced later on by an appropriate data type such as int, float, string etc. 
T find_max(T a, T b) 
// definition of functional template starts here. T or other variables such as can be used as place holders.
{
    T result; //declaration of variable results with placeholder, T. T will be replaced by appropriate datatype.
    result = (a > b) ? a : b; //if a > b, use a, else use b. It works like if-else condition.
    return result;
}

int main()
{
    int x, y, k;
    x = 25;
    y = 30;

    k = find_max<int>(x, y); // call find_max function and in it replace all Ts by int.
    cout <<"Maximum of the integers is: " <<k <<endl;

    //for string, we can do as:
    string a, b, c;
    a = "Ali";
    b = "Usman";

    c = find_max<string>(a, b); // call the same function, find_max(), and in it replace all Ts by string.
    cout <<"The larger of the two names is: " <<c <<endl;

    return 0;
}