// Templates
//
// Temmplates are a way of reusing code to apply the same class to different
// data types. For example, we might have a list-like data structure which
// we would like to use for lists of various types.

#include <iostream>

template <class T> class ShiftedList {
    public:
        ShiftedList(int sz) : offset(0), size(sz) {
            array = new T[size];
        }

        ~ShiftedList() {
            delete [] array;
        }

        void ShiftBy(int n) {
            offset = (offset + n) % size;
        }

        T getAt(int i) {
            return array[convertIndex(i)];
        }
        
        void setAt(T item, int i) {
            array[convertIdex(i)] = item;
        }
    
    private:
        T* array;
        int offset;
        int size;

        int convertIndex(int i) {
            int index = (i - offset) % size;
            while (index < 0) index += size;
            return index;
        }
};
