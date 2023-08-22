// 12.7 Virtual Base Class: Why does a destructor in base class need to 
// to be declared virtual?
//
// Let's think about why we have a virtual methodd to start with. Suppose
// we have the following code:

#include <iostream>

class Foo {
	public:
		virtual ~Foo()
		//~Foo()
		{
			std::cout << "Foo destructor" << std::endl;
		}

		void f()
		{
			std::cout << "Foo::f()" << std::endl;
		}
};

class Bar : public Foo {
	public:
		~Bar()
		{
			std::cout << "Bar destructor" << std::endl;
		}

		void f()
		{
			std::cout << "Bar::f()" << std::endl;
		}
};

int main()
{
	Foo *p = new Bar();
	p->f();

	delete p;

	return 0;
}

// Calling p->f() will result in call to Foo::f(). This is because p is a
// pointer to Foo, and f() is not virtual.
//
// To ensure that p->f() will invoke the most derived implementation of f(),
// we need to declare f() to be a virtual function.
//
// Now let's go back to our destructor. Destructors are used to clean up
// memory and resources. If Foo's destructor were not virtual, then Foo's
// destructor would be called, even when p is really of type Bar.
//
// This is why we declare destructors to be virtual; we want to ensure that the
// destructor for the most derived class is called.

