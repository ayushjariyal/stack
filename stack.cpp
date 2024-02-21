#include <iostream>
using namespace std;

#define MAX 10
class Stack{
    public:
        int arr[MAX];
        Stack(){
            top = -1;
        }

        void push(int item){
            if(top > MAX -1 ){
                cout << "Stack Overflow" << endl;
            }
            else{
                top += 1;
                arr[top] = item;
                cout << "Element added: " << item << endl;
            }
        }

        int pop(){
            if(top < 0){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            else{
                int item = arr[top--];
                return item;
            }
        }

        int peek(){
            if(top < 0){
                cout << "Stack Underflow" << endl;
            }
            else{
                int item = arr[top];
                return item;
            }
            return 0;
        }
        
        void PrintStack(){
            for (int i = top; i >= 0; i--){
                cout << arr[i] << endl;
            }
        }

    private:
        int top;
};

int main(){
    Stack st;
    int a;
    cout << "Enter how many items you want in stack: ";
    cin >> a;
    for(int i = 0; i < a; i++){
        int b;
        cout << "Enter element no. " << i << ": ";
        cin >> b;
        st.push(b);
    }

    int value = st.pop();
    if(value != -1){
        cout << "Deleted item: " << value << endl;
    }

    int top = st.peek();
    if(top != -1){
        cout << "Top Element: " << top << endl;
    }

    cout << "Stack: " << endl;

    st.PrintStack();

    return 0;
}