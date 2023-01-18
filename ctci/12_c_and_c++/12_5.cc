// 12.5 Shallow vs Deep Copy: What is the difference between deep copy and
// shallow copy? Explain how you would use each
//
// In general, creating a copy of an object means to create an exact replica
// of the objcet having the same literal value, data type, and resources.
//
// Depending upon the resources like dynamic memory held by the object, either
// we need to perform Shallow Copy or Deep Copy in order to create a replica
// of the object. In general, if the variables of an object have been dynamically
// allocated, then it is required to do a Deep Copy in order to create a copy of
// the object.
//
// Shallow Copy:
// In shallow copy, an object is created by symply copying the data of all
// variables of the original object. This works well if none of the variable
// of the object are defined in the heap section of the memory. If some variables
// are dynamically allocated memory from heap section, then the copied object
// variable will also reference the same memory location. This will create ambiguity
// and run-time errors, dangling pointer. Since both objects will reference to the
// same memory location, then changes made by one will reflect those changes in
// another object as well. Since we wanted to create a replica of the object, this
// purpose will not be filled by shallow copy.
//
// Deep Copy:
// In deep copy, an object is created by copying data of all variables, and it also
// allocates similar memory resources with the same value to the object. In order
// to perform deep copy, we need to explicitly define the copy constructor and
// assign dynamic memory as well, if required. Also, it is required to dynamically
// allocate memory to the variables in the other constructors, as well.
//
// Shallow vs Deep Copy:
// 
// 1. (shallow) When we create a copy of object by copying data of all member
//    variables as it is, then is is called shallow copy.
// 1. (deep) When we create an object by copying data of another object along
//    with the values of memory resources that reside outside the object, then
//    it is called deep copy.
//
// 2. (shallow) A shallow copy of an object copies all of the member values.
// 2. (deep) Deep copy is performed by implementing our own copy constructor.
//
// 3. (shallow) In shallow copy, the two objects are not independent.
// 3. (deep) It copies all fields, and makes copies of dynamically allocated
//    memory pointed to by the fields.
//
// 4. (shallow) It also creates a copy of the dynamically allocated objects.
// 4. (deep) If we do not create the deep copy in a rightful way then the copy will
//    point to the original, with disastrous consequences.
//
// Note: C++ compiler implicitly creates a copy constructor and overloads
// assignment operator in order to perform shallow copy at compile time.

#include <iostream>

class Box {
	private:
		int length;
		int breadth;
		int height;
	public:
		// Function that sets the dimensions
		void set_dimensions(int length1, int breadth1, int height1)
		{
			length = length1;
			breadth = breadth1;
			height = height1;
		}

		// Function to display the dimensions of the box
		void show_data()
		{
			std::cout << "Length = " << length << std::endl
					 << "Breadth = " << breadth << std::endl
					 << "Height = " << height << std::endl;
		}
};

class Dresser {
	private:
		int length;
		int *breadth;
		int height;
	public:
		// Constructor
		Dresser()
		{
			breadth = new int;
		}

		// Function to set the dimensions of the dresser
		void set_dimensions(int length1, int breadth1, int height1)
		{
			length = length1;
			*breadth = breadth1;
			height = height;
		}

		// Function to show the dimensions of the dresser
		void show_data()
		{
			std::cout << "Length = " << length << std::endl
					 << "Breadth = " << *breadth << std::endl
					 << "Height = " << height << std::endl;
		}

		// Parameterized constructors for implementing deep copy
		Dresser(Dresser &sample)
		{
			length = sample.length;
			breadth = new int;
			*breadth = *(sample.breadth);
			height = sample.height;
		}

		// Destructors
		~Dresser()
		{
			delete breadth;
		}
};

// Shallow copy example
int shallow_copy()
{
	Box box1;
	Box box3;

	// Set dimensions of box1
	box1.set_dimensions(13, 12, 16);
	box1.show_data();
	
	// When copying the data of object at the time of initialization
	// then copy is made through copy constructor.
	Box box2 = box1;
	box2.show_data();

	// When copying the data of object after initialization then the copy
    // is done through default assignment operator
	box3 = box1;
	box3.show_data();

	return 0;
}

// Deep copy example
int deep_copy()
{
	Dresser dresser1;

	dresser1.set_dimensions(12, 14, 16);

	dresser1.show_data();

	// When the data will be copied then all the resources will also get
	// allocated to the new object
	Dresser dresser2 = dresser1;
	
	dresser2.show_data();

	return 0;
}


int main()
{
	// Shallow copy example
	//shallow_copy();

	// Deep copy example
	deep_copy();

	return 0;
}

