#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

class Node{
    public:
    float data;
    Node* next;
    Node(float val) : data(val), next(nullptr) {} 
};

class Stack{
    public:
    Node* top;
    Stack() : top(nullptr) {}
    void push(float val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    float pop() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return -1;
        }
        float retVal = top->data;
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
        return retVal;
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class Nodechr{
    public:
    char data;
    Nodechr* next;
    Nodechr(char val) : data(val), next(nullptr) {} 
};

class Stackchr{
    public:
    Nodechr* top;
    Stackchr() : top(nullptr) {}
    void push(char val) {
        Nodechr* newNode = new Nodechr(val);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack  empty" << endl;
            return -1;
        }
        char retVal = top->data;
        Nodechr* toDelete = top;
        top = top->next;
        delete toDelete;
        return retVal;
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }
    
    char peek() {
        if (isEmpty()) { 
            return ' ';
        }
        return top->data;
    }

    ~Stackchr() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class PostfixCalculator {
    private:
    Stack stack;
    public:
    float postfixCalculator(const string& postfixExpression) {
        istringstream str(postfixExpression);
        string element;
        while (str >> element) {
            if (element != "+" && element != "-" && element != "*" && element != "/" && element != "^") {
                try {
                    float elementfloat = stof(element);
                    stack.push(elementfloat);
                }
                catch(const std::exception& e) {
                    cerr << e.what() << endl;
                }
            }
            else if (stack.top == nullptr || stack.top->next == nullptr) {
                cout << "Not enough operands: " << element << endl;
                return -1;
            }
            else {
                float numRight = stack.pop();
                float numLeft = stack.pop();
                if (element == "+") {
                    stack.push(numLeft + numRight);
                } 
                else if (element == "-") {
                    stack.push(numLeft - numRight);
                } 
                else if (element == "*") {
                    stack.push(numLeft * numRight);
                } 
                else if (element == "/") {
                    if (numRight == 0) {
                        cout << "Division by zero error" << endl;
                        return -1;
                    }
                    stack.push(numLeft / numRight);
                } else if (element == "^") {
                    stack.push(pow(numLeft, numRight));
                }
            }
        }
        return stack.top->data;
    }

    string toPostfix(const string& infinixExpression) {
        Stackchr stackcr;
        istringstream str(infinixExpression);
        string element;
        string postfixexp = "";
        bool firstElement = true;
        while (str >> element) {
            if (element == "(") {
                stackcr.push('(');
            }
            
            else if (element == ")") {
                char thiscr;
                do {
                    thiscr = stackcr.pop();
                    if (thiscr != '(') {
                        postfixexp = postfixexp + " " + thiscr;
                    }
                } while(thiscr != '(');
            }
            
            else if (element == "+") {
                char thiscr;
                while (stackcr.peek() == '+' || stackcr.peek() == '-' || stackcr.peek() == '*' || stackcr.peek() == '/' || stackcr.peek() == '^') {
                    thiscr = stackcr.pop();
                    postfixexp = postfixexp + " " + thiscr;
                }
                stackcr.push('+');
            }
            
            else if (element == "-") {
                char thiscr;
                while (stackcr.peek() == '+' || stackcr.peek() == '-' || stackcr.peek() == '*' || stackcr.peek() == '/' || stackcr.peek() == '^') {
                    thiscr = stackcr.pop();
                    postfixexp = postfixexp + " " + thiscr;
                }
                stackcr.push('-');
            }
            
            else if (element == "*") {
                char thiscr;
                while (stackcr.peek() == '*' || stackcr.peek() == '/' || stackcr.peek() == '^') {
                    thiscr = stackcr.pop();
                    postfixexp = postfixexp + " " + thiscr;
                }
                stackcr.push('*');
            }
            
            else if (element == "/") {
                char thiscr;
                while (stackcr.peek() == '*' || stackcr.peek() == '/' || stackcr.peek() == '^') {
                    thiscr = stackcr.pop();
                    postfixexp = postfixexp + " " + thiscr;
                }
                stackcr.push('/');
            }
            
            else if (element == "^") {
                char thiscr;
                while (stackcr.peek() == '^') {
                    thiscr = stackcr.pop();
                    postfixexp = postfixexp + " " + thiscr;
                }
                stackcr.push('^');
            }
            else {
                if (firstElement) {
                    postfixexp = element;
                    firstElement = false;
                } else {
                    postfixexp = postfixexp + " " + element;
                }
            }   
        }
        
        while (!stackcr.isEmpty()) {
            postfixexp += ' ';
            postfixexp += stackcr.pop();
        }
        
        return postfixexp;
    }
};

int main() {
    char stack[100];
    int top = -1;
    string infix, postfix = "";
    cout << "Enter infix (like 3+4*5): ";
    cin >> infix;
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (c >= '0' && c <= '9') {
            postfix += c;  
        }
        else if (c == '(') {
            stack[++top] = c;  
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix += stack[top--]; 
            }
            top--; 
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (top >= 0 && ((c == '+' || c == '-') && (stack[top] == '*' || stack[top] == '/'))) {
                postfix += stack[top--];
            }
            stack[++top] = c;
        }
    }
    
    while (top >= 0) {
        postfix += stack[top--];
    }
    cout << "Postfix: " << postfix << endl;
    
    int evalStack[100];
    int evalTop = -1;
    for (char c : postfix) {
        if (c >= '0' && c <= '9') {
            evalStack[++evalTop] = c - '0';
        }
        else {
            int b = evalStack[evalTop--];
            int a = evalStack[evalTop--];
            
            if (c == '+') evalStack[++evalTop] = a + b;
            else if (c == '-') evalStack[++evalTop] = a - b;
            else if (c == '*') evalStack[++evalTop] = a * b;
            else if (c == '/') evalStack[++evalTop] = a / b;
        }
    }
    cout << "Result: " << evalStack[evalTop] << endl;
}
