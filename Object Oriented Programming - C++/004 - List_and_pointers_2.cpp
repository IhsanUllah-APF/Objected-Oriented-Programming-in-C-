// A strucutre of variable length:
#include<iostream>
#include<string>
using namespace std;

// Define structure, node: structure must be defined at the start so that compiler knows what is node.
struct node{
    int val;
    node *next;
};

// Define a function to create node
node* create_node(node *current, int val){          // return type must be node* since we want to return n which
    node *n;                                        // is  a node pointer.
    n = new node;
    n -> val = val;
    n -> next = NULL;
    current -> next = n;
    return n;
}
// Define a function to create output list:
void output_list(node *head){
    node *current;
    current = head;
    cout << "[ ";
    while(current != NULL)
    {
        cout << current -> val << ",";
        current = current -> next;
    }
    cout << "]" << endl;
}
// Define a function to generate sum (or average etc) of numbers in the list/array.
int sum_list(node *head)
{
    int sum = 0;
    node *current;
    current = head;
    while(current != NULL)
    {
        sum = sum + current -> val;
        current = current -> next;
    }
    return sum;
} 
// Define a function to delete a number (node) - free up memory:
void delete_value(node *head){
    node *current;
    node *temp;
    
    current = head -> next;
    temp = current -> next;

    current -> next = current -> next -> next;

    delete temp;
}

int main(){
    node *head;
    node *current;
    int sum;
        
    head = new node;
    head -> val = 1;
    head -> next = NULL;
    current = head;

    //create more nodes through a function, creat_node:
    current = create_node(current, 5);
    current = create_node(current, 3);
    current = create_node(current, 10);

    //Generate the list/array of numbers in the list through a function.
    output_list(head);
    
    // Generate sum (or average etc) of the numbers in the list through a function.
    sum = sum_list(head);
    cout << "Sum of the numbers in the list is =" << sum << endl;

    // Delete a number from the list, say 3, through a funciton:
    delete_value(head);

    cout << "To confirm delettion of 3 from the list" << endl;
    output_list(head); 
    
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    // Produce the numbers in the list WIHTOU a function call:
    current = head;
    cout << "The integer values after deletion of integer 3 from arry or list are: " << endl;
    while(current != NULL)
    {
        cout << current -> val << endl;
        current = current -> next;
    }
    // Confirmation of a few things when current has NULL stored in it.
    cout << current << endl; // current contains zero since it has been set equal to NULL at end of above loop.
    cout << (*current).val << endl;  // this should have given error.
    cout << current -> val << endl;  // why it is not giving error? 

*/
