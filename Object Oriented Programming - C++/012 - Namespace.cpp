#include<iostream> 
// It's kind of global scope which contains sub-global scopes called namespaces. Namespaces can contain declarations  
// and definitions of different identifiers (variables, functions, classes etc).

//using namespace std; 
// std is a namespace (sub-global scope) in a golbal scope (iostream), containing declarations and definitions of 
// couts etc. When included and used, all those declarations and definitions become part of our program.

namespace first //declaration and definition of namespace, first. Note that namespace is a keyword and first is the 
{               //name of this namespace that we are creating.
    int var = 5; // We can have variables, functions, structures, and classes in namespace between {}.
}

namespace second 
{
    double var = 3.1416;
}

int main()
{
    std :: cout <<first::var <<std::endl;
    std :: cout <<second::var <<std::endl;
    //In absence of 'using namespace std', we have to write down std :: cout. This tells compiler to use cout
    //from namespace std. Also, first::var tells compiler to use var from namespace, first. Second::var tells
    //compiler to use var from namespace, second. This resolves the scope and removes ambiguity for compiler.
    // 5 and 3.1416 are produced upon running the program.

    using namespace std; // Note that 'using namespace ...' can be used within function as well.

    cout <<first::var <<endl;
    cout <<second::var <<endl;
    //Now cout doesn't carry std:: because we have included 'using namespace std'. By doing so, declarations and  
    //definitions contained in namespace, std, including declaration and definition of cout become part of this 
    //program. Thus, there is no need to write the name of namespace, std, and :: with cout. Same applies to endl.

    //Similarly, 
    using namespace first;

    cout <<var <<endl;
    cout <<second::var <<endl;
    //results produced correctly.

    //Following will give error "reference to var is ambigious" since one var exist in namespace, first, and the other
    //var exists in namespace, second. The compiler is unable to resolve which var belongs to whic namespace, so it
    //is giving ambiguity error. So, the following three commands are commented out.
    //using namespace second;
    
    //cout <<var <<endl;
    //cout <<var <<endl;



    return 0;  
}