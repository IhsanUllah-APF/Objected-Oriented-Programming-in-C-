/*
 // To print the array elements:
#include<iostream>
using namespace std;
int main(){
    
    int a[] = {25, 30, 35};
    int i;

    for(i = 0; i < 3; i++)
        cout<< a[i]<<endl;

    return 0;
}
*/
/*
// To print the array elements in reverse order:
#include<iostream>
using namespace std;
int main(){
    
    int a[] = {25, 30, 35};
    int i; // if int i was declared in the loop, then its scope will be limited only to the loop.

    cout<<"The elements of array in reverse order are : " <<endl; // << is necessory before endl and endl before ;
    for(i = 2; i >= 0; i--)
        cout<<a[i]<<endl;
    
    cout<<i<<endl; // To print value in i at the end. 
    return 0;
}
*/
/*
// To store and print values in multidimensional array:
#include<iostream>
using namespace std;
int main(){
    int a[2][3]; // there can't be a variable in the []. It has got to be constant when array only declared. This
                // array, a, has 2 rows and 3 columns.
    for(int i = 0; i < 2; i++) // to store values in multidimensional array. Looping over rows.
    {                           // these {} are must sicne in this for body, there are mroe than one statment.
        for(int j = 0; j < 3; j++) // looping over columns.
        {                                           // no need for these {} since the body of loop contains only 1
            a[i][j] = i * j; // assignment operator, =, used. // instruction.
        }
    }

    for(int i = 0; i < 2; i++) // to print values in multidimensional array.
    {
        for(int j = 0; j < 3; j++)
        {
            cout<< a[i][j] <<endl; // <<endl are necessory for some reason. Maybe a syntax.
        }
    }

    return 0;
}
*/
/* // Character array and using it as a datatype for string.
#include<iostream>
using namespace std;
int main(){
    char a[] = "Hello"; // character array is a string. "" also indicates string. This arrays contains 6 elements
                                             // due to null terminator, \0, at the end of the string.
                        // cout<<a[]<<endl; cannot print array elements like this since it requires input in [].
    
    for(int i = 0; i < 6; i++) // to print all the elements of array. 
        cout << a ;
        //cout << a[i] <<endl;
    // OR
    cout << a; // it means loop was not necessory to prinout elements of array. This code also prints the array. 
    return 0; 
}
*/
/*
// Using string datatype for sting
#include<iostream>
#include<string>
using namespace std; 
int main(){
    string a = "Hello"; // this is exactly same as char a[] = "Hello";
    //cout<< a; // this perfectly works to print the string, a, without loop.

    // Or, we can produce its elements just like array using loop. It means that string, a, and array, a[], are same.
    for(int i = 0; i < 5; i++)
        cout<< a[i] <<endl;

    cout<< a.length()<<endl; // tells length of a string. This is not possible with array so using string has some advantages.
    cout<< a.empty()<<endl; // asking if the string is empty. Will get 0 (fals) if the string is not empty.


    return 0;
}
*/
// Structures:
#include<iostream>
#include<string>
using namespace std;
struct student{         // struct is a keyword which tells compiler to create a user defined datatype called student.
                        // student is like int or float but it is user defined datatype. Definition/strcutre of 
                        //student starts from { and ends at };. Variables created using this datatype, student, can
                        // contain member varaibles of different types such as chars, ints and floats.  
    string name;        // declaration of a string member variable of a variable of type student such as s1.
    int rollno;         // declaration of an integer member variable of a variable of type student such as s1.
};
int main(){
    student s1, s2; //declaration of a variable of type student. It's member variables are name and rollno. student is a
                // datatype like int or float. So, student s1 is like int x.

    s1.name = "Ali"; // Go inside (the box of) s1 and find variable name and store in it Ali.
    s1.rollno = 2;

    s2.name = "Bilal";
    s2.rollno = 26;

    cout<<s1.name<<endl;
    cout<<s1.rollno<<endl;
    cout<<s2.name<<endl;
    cout<<s2.rollno<<endl;

    // OR the same can be acheived using arrays as: (note that this array, student s[5], is just like int s[5]).

    //student s[5]; // array, s, of type student declared which will contain 5 contagious memory locations. Each memory
                  // location or element of array will contain a student's name and roll number.
    //s[0].name = "Ali"; // it is like s1.name.
    //s[0].rollno = 2; // Go inside zeroth indexed element of array,s, and find variable roll no in it and store in
                    // that variabe (roll no) 2.
    
    //s[1].name = "Bilal";
    //s[1].rollno = 26;
    
    //cout<< s[0].name<<endl;
    //cout<< s[0].rollno<<endl;
    //cout<< s[1].name<<endl;
    //cout<< s[1].rollno<<endl;
   
    return 0;
}






