// The code below demonstrates the implementation of a basic
// class with inheritance
//
// All data members and methods are private by default in C++.
// One can modify this by introducing keyword public.

#include <iostream>
#include <string>

//using namespace std;    // using namespace is not the greatest idea
                          // specially with large codebases because you polute
                          // the global namespace

//#define NAME_SIZE 50    // defines a macro
                        // not so cool in C++, use const instead
const int name_size = 50;

class Person {
    private:
        int id; // all members are private by default
                // I prefer to be explicit
        char name[name_size];

    public:
        void aboutMe() {
            std::cout << "I am a person." << std::endl;
        }

        // virtual function - can be overriden by inherited class
        virtual void currentLocation() {
            std::cout << "Main square." << std::endl;
        }
        
        // pure virtual - must be defined by inherited class, no implementation
        // on base class, i.e., it only works as an interface
        virtual bool addCourse(std::string s) = 0;
};

class Student : public Person {
    public:
        void aboutMe() {
            std::cout << "I am a student." << std::endl;
        }

        void currentLocation() {
            std::cout << "University library." << std::endl;
        }

        bool addCourse(std::string s) {
            std::cout << "Added course: " << s << " to student." << std::endl;
            return true;
        }
};

int main()
{
    Student *s = new Student();
    s->aboutMe();   // print "I am a student."
    s->currentLocation();
    delete s;

    Person *p = new Student();
    p->aboutMe();   // print "I am a person."
                    // the function aboutMe() is resolved at compile-time,
                    // in a mechanism known as static-binding
    p->currentLocation();
    p->addCourse("History");
    delete p;

    // By defining addCourse as a "pure virtual function", person is now an abstract
    // class and we can't instantiate it

    return 0;
}
