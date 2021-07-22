#include <iostream>

using namespace std;

// A union is a struct in which all members are allocated at the same
// address so that the union occupies only as much space as its largest
// member. A union can hold a value for only one member at a time.

enum Type {str, num};

union Value {
    char* s;
    int i;
};

struct Entry {
    char* name;
    Type t;
    Value v;    // use v.s if t == s; use i if t == num
};

void check_for_t(Entry* p)
{
    if(p->t == str) {
        char cadena[] = "Roberto";
        cout << "Value is a string" << endl;
        p->v.s = cadena;
        cout << p->v.s << endl;
    }
    else if(p->t == num) {
        cout << "Value is a number" << endl;
        p->v.i = 50;
        cout << p->v.i << endl;
    }
}

int main()
{
    Entry entry1;
    Entry entry2;

    entry1.t = str;
    entry2.t = num;

    cout << sizeof(Value) << " bytes" << endl;

    check_for_t(&entry1);
    check_for_t(&entry2);
    
    return 0;
}
