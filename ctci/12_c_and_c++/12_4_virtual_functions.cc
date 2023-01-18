// 12.4 Virtual Functions: How do virtual function work in C++
//
// Virtual functions are a C++ feature that allows you to redifine a method in
// an inherited class, i.e., the base clase defines a member function and the
// child class redifines the method.
//
// Pure virtual functions are a special type of virtual functions that are just
// declared at the base clase but can't be defined. The definition must be provided
// by the child class, i.e., the method is only an API from the base class perspective.
// If a class contains a pure virtual function, it's called an abstract class, and you
// can't instanciate an object of that class.
//
// Solution provided by the book:
// A virtual function depends on a "vtable" or "Virtual Table." If any function of a class
// is declared to be virtual, a vtable is constructed which stores addresses of the virtual
// functions of this class. The compiler also adds a hidden vptr variable in all such classes
// which points to the vtable of that class. If a virtual function is not overriden in the derived
// class, the vtable of the derived class stores the address of the function in its parent class.
// The vtable is used to resolve the address of the function when the virtual function is called.
// Dynamic binding in C++ is performed through the vtable mechanism.
//
// Thus, when we assign the derived class object to the base class pointer, the vptr variable points
// to the vtable of the derived class. This assignment ensures that the most derived virtual function
// gets called. 

#include <iostream>

// Virtual Function

class Shape {
    public:
        int edge_lenght;
        virtual void greet() = 0;   // pure virtual function
        virtual int circumference() // virtual function
        {
            std::cout << "Circumference of Base Class" << std::endl;
            return 0;
        }
};

class Triangle: public Shape {
    public:
        void greet() {
            std::cout << "I'm a triangle" << std::endl;
        }
        int circumference()
        {
            std::cout << "Circumference of Triangle Class" << std::endl;
            return 3 * edge_lenght;
        }
        
};

int main()
{
    // Shape *x = new Shape(); // Error if pure virtual function exists
    // x->circumference();

    Shape *y = new Triangle();
    y->greet();
    y->circumference();
	
	return 0;
}
