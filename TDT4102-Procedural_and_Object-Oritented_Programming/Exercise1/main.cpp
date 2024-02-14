#include "std_lib_facilities.h"

// a) Max of two numbers

int maxOfTwo(int a, int b)
{
    if (a > b)
    {
        cout << "A is greater than B" << endl;
        return a;
    }
    else
    {
        cout << "B is greater than A" << endl;
        return b;
    }
}

// c) Fibonacci numbers

int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers: " << endl;
    for (int x = 1; x < n + 1; ++x) // ++x increments the value of x
    { 
        cout << x << "," << b << endl;
        int temp = b; // temp is a temporary variable
        b += a;
        a = temp;
        cout << "----" << endl;
    }
    return b;
}

//d) Sum of squares

int squareNumberSum(int n)
{
    int totalSum = 0;
    for (int i = 1; i < n+1; ++i)
    {
        totalSum += i * i;
        cout << "The " << n << " first square numbers: " << i*i << endl;
    }
    cout << "Totalsum: " << totalSum << endl;
    return totalSum;
}

// e) Triangle numbers

void triangleNumbersBelow(int n) //void means that the function does not return anything
{
    int acc = 1; // acc is short for accumulator
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n)
    {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    cout << endl; // empty line
}

// f) Prime numbers (1)
bool isPrime(int n)
{
    for (int j = 2; j < n; ++j)
    {
        if (n % j == 0)
        return false;
    }
    return true;
}

// g) Prime numbers (2) 
void naivePrimeNumberSearch(int n)
{
    for (int number = 2; number < n; ++number)
    {
        if (isPrime(number))
        {
            cout << number << " is a prime" << endl;
        }
    }
}

// h) Navn og alder
void inputAndPrintNameAndAge()
{
    string name = "";
    string age = "";
    cout <<  "Enter a name: ";
    cin >> name;
    cout << "What is the age of " << name << "? ";
    cin >> age;
    cout << name << " is " << age << " years old." << endl;

}


// b) main-function

int main()
{
    // cout << "Task a)" << endl;
    // cout << maxOfTwo(5, 6) << endl;

    // cout << "Task c)" << endl;
    // cout << fibonacci(10) << endl;

    // cout << "Task d)" << endl;
    // squareNumberSum(5);

    // cout << "Task e)" << endl;
    // triangleNumbersBelow(100);

    // cout << "Task f)" << endl;
    // if (isPrime(7) == true)
    // {
    //     cout << "7 is a prime number" << endl;
    // }
    // else
    // {
    //     cout << "7 is not a prime number" << endl;
    // }

    cout << "Task g)" << endl;
    naivePrimeNumberSearch(14);

   // cout << "Task h)" << endl;
   // inputAndPrintNameAndAge();


    return 0; // return 0 indicates success
}