// Simple calculator using Class Templates

#include <iostream>

using namespace std;

template <class T>
class Calculator
{
    private:
        T num1;
        T num2;
    public:
        Calculator(T n1, T n2) {
            num1 = n1;
            num2 = n2;
        }

        void displayResult() {
            cout << "Numbers are: " << num1 << " and " << num2 << endl;
            cout << "Addition is: " << add() << endl;
            cout << "Subtraction is: " << subtract() << endl;
            cout << "Product is: " << multiply() << endl;
            cout << "Division is: " << divide() << endl;
        }

        T add() { return num1 + num2; }

        T subtract() { return num1 - num2; }
         
        T multiply() { return num1 * num2; }

        T divide() {
            if(num2 != 0)
                return num1 / num2;
            else
                return -1;
        } 
};

int main(void)
{
    Calculator<int> intCalc(2,1);
    Calculator<float> floatCalc(2.4, 0);
    Calculator<double> doubleCalc(242.45, 34.94);

    cout << "Int results: " << endl;
    intCalc.displayResult();

    cout << "Float results: " << endl;
    floatCalc.displayResult();

    cout << "Double results: " << endl;
    doubleCalc.displayResult();

    return 0;
}
