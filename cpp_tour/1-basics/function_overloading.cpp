#include <iostream>
#include <string>

using namespace std;

void print(int i_num)
{
    cout << "i_num is: " << i_num << endl; 
}

void print(double d_num)
{
    cout << "d_num is: " << d_num << endl;
}

void print(string s_message)
{
    cout << "s_message is: " << s_message << endl;
}

void user()
{
    print(42);  // calls print(int num)
    print(9.65);    // calls print(double num)
    print("D is for digital");  // calls print(string message)
}

int main()
{
    user();

    return 0;
}