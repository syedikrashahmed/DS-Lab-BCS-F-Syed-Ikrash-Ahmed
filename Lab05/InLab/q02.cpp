/*Task 2:
1. Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly.
2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.
*/
#include <iostream>
using namespace std;
void functionB(int n);
void printNumbers(int n){
    if (n <= 1) {
        cout << n <<endl;
        return;
    }
    cout << n << " ";
    printNumbers(n - 1);
}

void functionA(int n) {
    if (n == 0) {
        return;
    }
    cout << n<<" ";
    functionB(n-2);
}

void functionB(int n) {
    if (n == 0) {
        return;
    }
    cout <<n  <<    " ";
    functionA(n-2);
}

int main() {
    int num;
    cout << "Enter num:";
    cin>> num;
    printNumbers(num);
    functionA(num);
}
