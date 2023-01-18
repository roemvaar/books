// 12.1 Last K Lines: write a method to print the last K lines of an
// input file using C++

#include <iostream>
#include <fstream>
#include <string>

// Solution 1: Read the file twice
// 1) Reads all the file and counts the number of lines
// 2) Returns the stream pointer to the beginning
// 3) Re-reads all the lines again until it finds the num_lines - k and
// prints the last k lines
void LastKLines(int k)
{
    std::string line;
    std::ifstream file("lorem_ipsum.txt");

    if (file.is_open())
    {
        // Count total number of lines
        int num_lines = 0;

        while (getline(file, line))
        {
            num_lines++;
        }

        // Print last k lines
        file.clear();
        file.seekg(0);
        int curr_line = 0;

        while (getline(file, line))
        {
            if (curr_line >= num_lines - k) {
                std::cout << line << std::endl;
            }

            curr_line++;
        }

        file.close();
    }
    else {
        std::cout << "Unable to open the text file" << std::endl;
    }
}

// Solution 2: Place file pointer at the end and read K lines before the end

// Solution from book - using circular array
void PrintLast10Lines(std::string filename)
{
    const int K = 10;
    std::ifstream file(filename);
    std::string L[K];
    int size = 0;

    // Read file line by line into a circular array
    // peek() so an EOF following a line ending is not considered a separate line
    while (file.peek() != EOF) {
        getline(file, L[size % K]);
        ++size;
    }

    // Compute start of circular array, and the size of it
    int start = size > K ? (size % K) : 0;
    int count = std::min(K, size);

    // Print elements in the order they were read
    for (int i = 0; i < count; ++i) {
        std::cout << L[(start + i) % K] << std::endl;
    }
}

int main()
{
    //LastKLines(10);
    PrintLast10Lines("lorem_ipsum.txt");

    return 0;
}
