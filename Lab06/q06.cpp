/*Task 6 – Infix to Prefix Conversion using Stack
Write a program to convert an infix expression into prefix form using stack rules.
1. Include operator precedence and associativity handling.
2. Evaluate the prefix expression as well.*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class ArrayStack {
private:
    string* stackArray;
    int stackPointer;
    int maxSize;
public:
    ArrayStack(int capacity) {
        maxSize = capacity;
        stackArray = new string[maxSize];
        stackPointer = -1;
    }

    void addElement(string element) {
        if (stackPointer == maxSize - 1) return;
        stackArray[++stackPointer] = element;
    }

    string removeElement() {
        if (stackPointer == -1) return "";
        return stackArray[stackPointer--];
    }

    string checkTop() {
        if (stackPointer == -1) return "";
        return stackArray[stackPointer];
    }

    bool isEmpty() {
        return stackPointer == -1;
    }
    
    ~ArrayStack() {
        delete[] stackArray;
    }
};

class NumberStack {
private:
    float* numberArray;
    int stackPointer;
    int maxSize;
public:
    NumberStack(int capacity) {
        maxSize = capacity;
        numberArray = new float[maxSize];
        stackPointer = -1;
    }

    void addNumber(float number) {
        if (stackPointer == maxSize - 1) return;
        numberArray[++stackPointer] = number;
    }

    float removeNumber() {
        if (stackPointer == -1) return -1;
        return numberArray[stackPointer--];
    }

    bool isEmpty() {
        return stackPointer == -1;
    }
    
    ~NumberStack() {
        delete[] numberArray;
    }
};

class ExpressionProcessor {
private:
    int checkPriority(string operatorStr) {
        if (operatorStr == "^") return 3;
        if (operatorStr == "*" || operatorStr == "/") return 2;
        if (operatorStr == "+" || operatorStr == "-") return 1;
        return 0;
    }

    bool isNumberChar(char c) {
        return (c >= '0' && c <= '9') || c == '.';
    }
public:
    string convertToPostfix(string infixExpr) {
        ArrayStack operatorStack(50);
        string resultExpr = "";
        string currentNumber = "";
        
        for(int i = 0; i < infixExpr.length(); i++) {
            char currentChar = infixExpr[i];
            
            if (currentChar == ' ') {
                continue;
            }
            
            if (isNumberChar(currentChar)) {
                currentNumber += currentChar;
            } else {
                if (!currentNumber.empty()) {
                    resultExpr += currentNumber + " ";
                    currentNumber = "";
                }
                
                if (currentChar == '(') {
                    operatorStack.addElement("(");
                } else if(currentChar == ')') {
                    while(!operatorStack.isEmpty() && operatorStack.checkTop() != "(") {
                        resultExpr += operatorStack.removeElement() + " ";
                    }
                    operatorStack.removeElement();
                } else {
                    string currentOp(1, currentChar);
                    while (!operatorStack.isEmpty() && 
                           checkPriority(operatorStack.checkTop()) >= checkPriority(currentOp)) {
                        resultExpr += operatorStack.removeElement() + " ";
                    }
                    operatorStack.addElement(currentOp);
                }
            }
        }
        
        if (!currentNumber.empty()) {
            resultExpr += currentNumber + " ";
        }
        
        while (!operatorStack.isEmpty()) {
            resultExpr += operatorStack.removeElement() + " ";
        }
        
        return resultExpr;
    }

    string convertToPrefix(string infixExpr) {
        ArrayStack operatorStack(50);
        string resultExpr = "";
        string currentNumber = "";
        
        string reversedInfix = "";
        for(int i = infixExpr.length() - 1; i >= 0; i--) {
            char c = infixExpr[i];
            if(c == '(') reversedInfix += ')';
            else if(c == ')') reversedInfix += '(';
            else reversedInfix += c;
        }
        
        for(int i = 0; i < reversedInfix.length(); i++) {
            char currentChar = reversedInfix[i];
            
            if (currentChar == ' ') {
                continue;
            }
            
            if (isNumberChar(currentChar)) {
                currentNumber += currentChar;
            } else {
                if (!currentNumber.empty()) {
                    resultExpr = currentNumber + " " + resultExpr;
                    currentNumber = "";
                }
                
                if (currentChar == '(') {
                    operatorStack.addElement("(");
                } else if (currentChar == ')') {
                    while(!operatorStack.isEmpty() && operatorStack.checkTop() != "(") {
                        resultExpr = operatorStack.removeElement() + " " + resultExpr;
                    }
                    operatorStack.removeElement();
                } else {
                    string currentOp(1, currentChar);
                    while (!operatorStack.isEmpty() && 
                           checkPriority(operatorStack.checkTop()) > checkPriority(currentOp)) {
                        resultExpr = operatorStack.removeElement() + " " + resultExpr;
                    }
                    operatorStack.addElement(currentOp);
                }
            }
        }
        
        if (!currentNumber.empty()) {
            resultExpr = currentNumber + " " + resultExpr;
        }
        
        while(!operatorStack.isEmpty()) {
            resultExpr = operatorStack.removeElement() + " " + resultExpr;
        }    
        return resultExpr;
    }

    float evaluatePostfix(string postfixExpr) {
        NumberStack numberStack(50);
        string currentToken = "";
        
        for (int i = 0; i < postfixExpr.length(); i++) {
            char currentChar = postfixExpr[i];
            
            if (currentChar == ' ') {
                if (!currentToken.empty()) {
                    if (currentToken[0] >= '0' && currentToken[0] <= '9') {
                        numberStack.addNumber(stof(currentToken));
                    } else {
                        float secondNum = numberStack.removeNumber();
                        float firstNum = numberStack.removeNumber();
                        
                        if (currentToken == "+") 
                            numberStack.addNumber(firstNum + secondNum);
                        else if (currentToken == "-") 
                            numberStack.addNumber(firstNum - secondNum);
                        else if (currentToken == "*") 
                            numberStack.addNumber(firstNum * secondNum);
                        else if (currentToken == "/") 
                            numberStack.addNumber(firstNum / secondNum);
                        else if (currentToken == "^") 
                            numberStack.addNumber(pow(firstNum, secondNum));
                    }
                    currentToken = "";
                }
            } else {
                currentToken += currentChar;
            }
        }
        return numberStack.removeNumber();
    }

    float evaluatePrefix(string prefixExpr) {
        NumberStack numberStack(50);
        string currentToken = "";    
        for (int i = prefixExpr.length() - 1; i >= 0; i--) {
            char currentChar = prefixExpr[i];        
            if (currentChar == ' ') {
                if (!currentToken.empty()) {
                    if(currentToken[0] >= '0' && currentToken[0] <= '9') {
                        numberStack.addNumber(stof(currentToken));
                    } else {
                        float firstNum = numberStack.removeNumber();
                        float secondNum = numberStack.removeNumber();
                        
                        if (currentToken == "+") 
                            numberStack.addNumber(firstNum + secondNum);
                        else if (currentToken == "-") 
                            numberStack.addNumber(firstNum - secondNum);
                        else if (currentToken == "*") 
                            numberStack.addNumber(firstNum * secondNum);
                        else if (currentToken == "/") 
                            numberStack.addNumber(firstNum / secondNum);
                        else if (currentToken == "^") 
                            numberStack.addNumber(pow(firstNum, secondNum));
                    }
                    currentToken = "";
                }
            } 
            else {
                currentToken = currentChar + currentToken;
            }
        }
        
        if (!currentToken.empty()) {
            if (currentToken[0] >= '0' && currentToken[0] <= '9') {
                numberStack.addNumber(stof(currentToken));
            }
        } 
        return numberStack.removeNumber();
    }
};

int main() {
    ExpressionProcessor processor;
    string userExpression; 
    cout << "enter expression: ";
    getline(cin, userExpression);
    string postfixResult = processor.convertToPostfix(userExpression);
    string prefixResult = processor.convertToPrefix(userExpression);   
    cout << "postfix: " << postfixResult << endl;
    cout << "prefix: " << prefixResult << endl;   
    float prefixCalculation = processor.evaluatePrefix(prefixResult);
    cout << "result: " << prefixCalculation << endl;  
}
