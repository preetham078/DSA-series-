// #include<iostream>
// using namespace std;
// int maxx=5;
// int top=-1;
// bool isfull()
//     {
//         if(top==maxx-1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// bool isEmpty()
//     {
//         if(top==-1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }


// int main()
// {
//     int item;
//     int arr1[maxx];
//     for(int i=0;i<maxx;i++)
//     {
//         cin>>arr1[i];
//     }
//     if(isfull())
//     {
//         cout<<"Stack is full"<<endl;
//     }
//     else
//     {
//         top++;
//         arr1[top]=item;
//     }

//     cout<<isfull();
//     cout<<isEmpty();
    



   
// }



#include <iostream>
using namespace std;
int const MAX=5;
int stackArray[MAX];
int top = -1;

void push(int val){
    if(top==MAX-1){
        cout<<"overflow"<<endl;
    }
    else{
        top++;
        stackArray[top]=val;
        cout<<"pushed "<<val<<endl;
        
    }
}

void pop(){
    if(top==-1){
        cout<<"underflow"<<endl;
    }
    else{
        cout<<"popped "<<stackArray[top]<<endl;
        top--;
    }
}
void display(){
    if(top==-1){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack elements are: ";
        for(int i=top;i>=0;i--){
            cout<<stackArray[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}