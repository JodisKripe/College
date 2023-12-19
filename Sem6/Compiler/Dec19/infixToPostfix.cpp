#include <iostream>

#include <string>


using namespace std;

class stack {
    public:
        int top;
        int arr[5];
        char topchar;
        stack() {
            top = -1;
            for (int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }

        bool isEmpty() {
            if (top == -1)
                return true;
            else
                return false;
        }

        bool isFull() {
            if (top == 4)
                return true;
            else
                return false;
        }

        void push(int val) {
            if (isFull()) {
                cout << "Stack Overflow" << std::endl;
            } else {
                top++;
                arr[top] = val;
                topchar = val;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << std::endl;
                return 0;
            } else {
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                topchar = arr[top];
                return popValue;
            }
        }

        int count() {
            return (top + 1);
        }

        int peek(int pos) {
            if (isEmpty()) {
                cout << "Stack Underflow" << std::endl;
                return 0;
            } else {
                return arr[pos];
            }
        }

        void change(int pos, int val) {
            arr[pos] = val;
            cout << "Value changed at location " << pos << std::endl;
        }

        void display() {
            std::cout << "All values in the Stack are " << std::endl;
            for (int i = 4; i >= 0; i--) {
                cout << arr[i] << std::endl;
            }
        }
};


// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    string postfix;
    stack stack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
            //cout << "( started ( )";
        } else if (c == ')') {
            //cout << " ) stopping ( )";
            while (!stack.isEmpty() && stack.topchar != '(') {
                postfix += stack.topchar;
                stack.pop();
            }
            stack.pop(); // Discard the '('
        } else if (isOperator(c)) {
            cout << c<<" " << stack.topchar <<" " << !stack.isEmpty()<< getPrecedence(stack.topchar) << getPrecedence(c) << endl;
            while (!stack.isEmpty() && getPrecedence(stack.topchar) >= getPrecedence(c)) {
                cout<<"AA: "<<c<<" "<<postfix<<endl;
                postfix += stack.topchar;
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.topchar;
        stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
