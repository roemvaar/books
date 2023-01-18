// 12.3 Hash Table vs. STL Map: Compare and contrast a hash table and an STL map. How
// is a hash table implemented? If the number of inputs is small, which data structure
// options can be used instead of a hash table?
//
// https://www.geeksforgeeks.org/hash-table-vs-stl-map/
//
// Hash Table
// In a hash table, a value is stored by calling a hash function on a key
// * Values are not stored in sorted order
// * Additionally, since hash tables use the key to find the
// index that will store the value, an insert or lookup can be done in amortised O(1)
// assuming few collisions in the hash table.
// * In a hash table, one must also handle pottential collisions. This is often done by
// chaining, which means to create a linked list of all the values whose key map to
// a particular index.
//
// Hash Table Implementation (unordered_map in C++)
// A hash table is traditionally implemented with an array of linked lists. When we want
// to insert a key/value pair, we map the key to an index in the array using a hash function.
// The value is then instered into the linked list at that position.
//
// STL Map
// The container map is an associative container included in the standard library of C++.
// The definition of this class is in the header file "map" of the namespace std. Maps are
// associative containers that store elements in a mapped fashion. Each element has a key value
// and a mapped value. No two mapped values can have the same key values.
//
// STL Map Implementation
// It's implemented as a self-balancing red-black tree. To balance the tree after an insertion
// the algorithm uses the notion of rotations where the nodes of the tree are rotated to perform
// the re-balancing. The insert/delete operations are O(log n), and rotation is O(1).
//
// Hash Table vs STL Map
//
// 1. Null keys: STL Map allows one null key and multiple null values whereas hash table
// doesn't allow any null key or value.
//
// 2. Thread synchronization: Map is generally preferred over hash table if thread synchronization
// is not needed. Hash table is synchronized.
//
// 3. Thread safe: STL Maps are not thread safe whereas Hashmaps are thread safe and can be shared
// with many threads.
//
// 4. Value order: In STL Map, values are stored in sorted order whereas in hash table values
// are not stored in sorted order.
//
// 5. Searching time: You can use STL Map or binary tree for smaller data (altough it takes O(log n))
// time, the number of inputs may be small enough to make this time neglible) and for large amount
// of data, hash table is preferred.
//
