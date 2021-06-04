// Linked List in C++

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

