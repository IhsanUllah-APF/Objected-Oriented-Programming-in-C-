/*
//Pointers. 4 bytes, each having own address, are alloted for an integer on 32 bit machine. Pointer is a datatype
//which can store only 1 address at a time and is denoted by *.
//Pointer to a variable:
#include<iostream>
using namespace std;
int main(){
    int x = 25;
    int *p;
    p = &x;
    cout << x << endl;
    cout << *p << endl;
    cout << &x << endl;
    cout << p << endl;
    cout << &p << endl;
    return 0;
}
*/

// Pointer to an array:
#include<iostream>
using namespace std;
int main(){
    int a[] = {1, 2, 3};
    int *p;
    p = &a[0]; // this is same as p = a since value in a is address of a[0]. a is a pointer to a[0].
    cout<< "value of, a[0] = " << a[0] << endl;
    cout << "value at address contained in pointer p, *p = " << *p << endl;
    cout << "value at address contained in pointer, *a = " << *a << endl; // name of array is a pointer to the zeroth
    cout<< "address of a[0], &a[0] = " << &a[0] << endl;       // element of array, a[0]. So, *a will give value in a[0].
    cout << "address contained in pointer, p = " << p << endl;
    cout << "address contained in pointer, a = " << a << endl; // a will contain address of a[0] since a is a pointer
      
      // incrementing a pointer                                                          // to a[0].
    p = p + 1; // increment pointer p by 1, which will make the pointer to point to the next memory location of the
                // same type (integer in this case which contains 4 bytes).
    cout << "value at address contained in pointer, *p = " << *p <<endl;

    // Using loop to print out elements of an array using pointers:
    cout << "Using loop and pointer to print elements of an array declared and initialized above:" << endl;
    p = a; // a contains address of zeroth element of array, a, which will be assigned to pointer p.
    for(int i = 0; i < 3; i++) // Note that pointer does not know where array ends. So it can keep incrementing and
    {                           // producing garbage values if loop is run for more than number of elements in array
        cout << *p << endl;
        p++; // or p+1;
                            
    }

    // Must not leave a pointer uninitialized since it can randomly then point to some memory location. A pointer
    // can be initialized to null by typing as: int *q = NULL; which means pointer will point to the first chunk in
    // memory location which is reserved by operating system for its own use. So, accessing or changing value in that
    // particular location will not be permitted by the operating system causing the program to crash which is better
    // than mistakenly and unknowingly producing and using garbage values. NULL is a reminder to properly initialize
    // the pointer and don't forget it. Null pointer dereferncing crashes the program.

    return 0;
}













/*
why this funciton is not working? Ask Nouman sb. Most probably, the function needs to be called.
#include<iostream>
using namespace std;
void pointer_test(){
    int x = 10;
    cout << x << endl;
    cout << &x << endl;
}
*/



