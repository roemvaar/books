/* Linked Lists
 * 
 * Mainly used for handling dynamic data / lists
 * 
 * Types: singly linked list, doubly linked list, and circular linked list
 * 
 * The next pointer can be anywhere in the struct, but placing it at the
 * beginning makes it easier to write generic list-handling routines that
 * work no matter what data element holds by casting the pointer to be of
 * the generic list element type.
 */


// The simplest singly linked list element
typedef struct ListElement {
    struct ListElement *next;
} ListElement;

// A more useful singly linked list element
typedef struct IntElement {
    struct IntElement *next;
    int data;
} IntElement;

