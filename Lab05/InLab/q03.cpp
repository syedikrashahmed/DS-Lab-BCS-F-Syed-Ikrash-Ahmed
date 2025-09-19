/*Task 3:
1. Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.
2. Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks.

*/
#include <iostream>
using namespace std;

int sumTail(int n, int total = 0) {
    if (n == 0){
        return total;
    }
    total += n;
    return sumTail(n - 1, total);
}

int sumNonTail(int n, int total = 0) {
    if (n == 0){
        return total;
    }
    total += n;
    int result = sumTail(n - 1, total);
    return result;
}

int main() {
    int num;
    cout << "Enter num:";
    cin>> num;
    int a = sumTail(num);
    int b = sumNonTail(num);
    cout << "sum from tail func: "<<a << " from nuntail :  "<<  b<<endl;
}
