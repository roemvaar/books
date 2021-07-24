#include <iostream>

using namespace std;

// enum class: User-defined type for wich we can enumerate the values
// enum vs enum class: the main difference is that when you declare names
// inside an enum data type, then you're not going to be able to use those
// names in your whole program, this problem is solved by using enum class
// because it's strongly scoped. Also, enum class is strongly typed, implicit
// conversion from enum element to int is not allowed, with enum data type
// 0 compared with the first element of the enum will throw a true value, which
// is not necesarily the behaviour we're looking for. enum class was introduced
// on C++11

enum class Color {red, blue, green};
enum class Traffic_light {green, yellow, red};

Color col = Color::red;
Traffic_light light = Traffic_light::red;

// Note that enumarators (e.g. red) are in the scope of their enum class, so that
// they can be used repeatedly in different enum classes without confusion. This is
// not possible with enum data type.

int main()
{
    return 0;
}
