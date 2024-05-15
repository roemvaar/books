/* Linked List in C++
 *
 * When defining classes in C++, particularly in template form, it's best
 * to explicitly add copy constructors and assignments operators so you don't
 * depend on the compiler-generated versions. We skip that here, but doesn't
 * hurt to mention it on an interview.
 */

// A templated C++ singly linked list 
template <class T>
class ListElement {
    public:
        ListElement(const T &value): next(NULL), data(value) {}
        ~ListElement() {}

        ListElement *getNext() const {return next;}
        const T& value() const {return data;}
        void setNext(ListElement *elem) {next = elem;}
        void setValue(const T &value) {data = value;}
    
    private:
        ListElement *next;
        T data;
};
