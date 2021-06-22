TUTORIALS
        HOWTOS

C++ Howtos
        Split String by Space in C++
Print Out the Contents of a Vector in C++
Multiply Two Matrices in C++
Create a File in C++
Find Set Intersection in C++
HowToC++ HowtosReplace a Part of the String in C++
Replace a Part of the String in C++

Created: November-02, 2020 | Updated: December-10, 2020

Use replace() Method to Replace Part of the String in C++
Use Custom Function to Replace Part of the String in C++
Use regex_replace() Method to Replace Part of the String in C++
This article demonstrates multiple methods of how you can replace a part of the string in C++.

Use replace() Method to Replace Part of the String in C++
replace is the std::string class built-in method and provides the exact feature of replacing a given part of the string object. The first parameter of the function indicates the starting character where the given string is inserted. The next parameter specifies the length of the substring that should be replaced by a new string. Finally, the new string is passed as the third argument. Note that, replace method modifies the string object on which it’s called upon.

#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

int main(){
    string input = "Order $_";
    string order = "#1190921";

    cout << input << endl;

    input.replace(input.find("$_"), 2, order);

    cout << input << endl;

    return EXIT_SUCCESS;
}
Output:

Order $_
Order #1190921
Use Custom Function to Replace Part of the String in C++
Alternatively, you can construct a custom function that returns a separate modified string object instead of doing the replacement in-places. The function takes 3 references to string variables: the first string is for modifying, the second substring is for replacing, and the third string is for inserting. Here, you can notice that the function returns constructed string by the value since it has move semantics.
#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

string Replace(string& str, const string& sub, const string& mod) {
    string tmp(str);
    tmp.replace(tmp.find(sub), mod.length(), mod);
    return tmp;
}

int main(){
    string input = "Order $_";
    string order = "#1190921";

    cout << input << endl;

    string output = Replace(input, "$_", order);

    cout << output << endl;

    return EXIT_SUCCESS;
}
Output:

Order $_
Order #1190921
Use regex_replace() Method to Replace Part of the String in C++
Another useful method you can use to solve this problem is utilizing regex_replace; it’s part of the STL regular expressions library, which is defined in the <regex> header. This method uses regex to match the characters in a given string and replace the sequence with a passed string. In the following example, regex_replace constructs a new string object.
#include <iostream>
#include <string>
#include <regex>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::regex_replace; using std::regex;

int main(){
    string input = "Orderphgf";
    string order = "f";

    cout << input << endl;

    string output = regex_replace(input, regex("\\ph"), order);

    cout << output << endl;

    return EXIT_SUCCESS;
}