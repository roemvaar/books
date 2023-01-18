// 12.5 Shallow vs Deep Copy: What is the difference between deep copy and
// shallow copy? Explain how you would use each
//
// A shallow copy copies all the members values from one object to another.
// A deep copy does all this and also deep copies any pointer objects.

struct Test {
	char *ptr;
}

// Example of shallow copy
void shallow_copy(Test &src, Test &dest)
{
	dest.ptr = src.ptr;
}

// Example of deep copy
void deep_copy(Test &src, Test &dest)
{
	dest.ptr = (char *)malloc(strlen(src.ptr) + 1;
	strcpy(dest.ptr, src.ptr);
}

// Note that shallow_copy may cause a lot of programming runtime errors,
// especially with the creation and deletion of objects. Shallow copy should
// be used very carefully and only when a programmer really understands
// what he wants to do.
//
// In most cases, shallow copy is used when there is a need to pass information
// about complex structure without actual duplication of data. One must also be
// careful with destruction of objects in a shallow copy.
//
// In real life, shallow copy is rarely used. Deep copy should be used in most
// cases, especially when the size of the copied structure is small.

