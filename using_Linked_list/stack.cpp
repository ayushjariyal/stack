#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    public:
        Node *top;
        Stack(){
            top = NULL;
        }

        void push(int n){
            Node *newNode = new Node();
            newNode->data = n;
            if(top == NULL){
                newNode->next = NULL;
            }
            else{
                newNode->next = top;
            }
            top = newNode;
        }

        void pop(){
            Node *temp;
            if(top == NULL){
                cout << "Stack Underflow" << endl;
                return;
            }
            else{
                temp = top;
                top = top->next;
                delete temp;
            }
        }

            int peek(){
                if(top == NULL){
                    cout << "Stack Underflow" << endl;
                    return -1;
                }
                return top->data;
            }

            void display(){
                Node *temp;
                if(top == NULL){
                    cout << "Stack Underflow" << endl;
                }
                else{
                    temp = top;
                    while(temp != NULL){
                        cout << temp->data << " ";
                        temp = temp->next;
                    }
                    cout << endl;
                }
            }
    };

int main(){
    Stack stk;
    stk.push(30);
    stk.push(20);
    stk.push(50);
    stk.push(70);

    stk.display();
    
    int top_value = stk.peek();
    if(top_value != -1){
        cout << "Top value is: " << top_value << endl;
    }

    stk.pop();

    cout << "Element after pop operation: " << endl;
    stk.display();

    return 0;
}