#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) //base case 
        return n;
    else {
      //when n= 5 it will
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    cout << "The 15th fibonacci is: " << fibonacci(15);

    return 0;
}
