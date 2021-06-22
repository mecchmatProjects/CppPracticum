#include <iostream> 
#include <fstream> 
#include <string> 
 
using namespace std; 
 
bool contains(string str, char ch) 
{ 
    return (str.find(ch) != std::string::npos); 
} 
 
string removeUnmatched(string constraints, string toCheck) 
{ 
    string newString = ""; 
    for (int i = 0; i < toCheck.length(); i++) 
    { 
        if (contains(constraints, toCheck[i]) || toCheck[i] == ' ') 
        { 
            newString += toCheck[i]; 
        } 
    } 
    return newString; 
} 
 
class StringWithConstraints 
{ 
private: 
    string constraints; 
    int constraintsLength; 
    string enteredString; 
    int enteredLength; 
 
public: 
    StringWithConstraints() 
    { 
        this->constraints = ""; 
        this->enteredString = ""; 
        this->enteredLength = 0; 
        this->constraintsLength = 0; 
    } 
    StringWithConstraints(string constraints, string entered) 
    { 
        this->constraints = constraints; 
        this->enteredString = removeUnmatched(constraints, entered); 
        this->enteredLength = constraints.length(); 
        this->constraintsLength = entered.length(); 
    } 
    void setConstraints(string constr) 
    { 
        this->constraints = constr; 
        this->constraintsLength = constr.length(); 
    } 
    void setEntered(string entr) 
    { 
        this->enteredString = entr; 
        this->enteredLength = entr.length(); 
    } 
    int getLength() 
    { 
        return this->enteredLength; 
    } 
    string getConstraints() 
    { 
        return this->constraints; 
    } 
    string getEntered() 
    { 
        return this->enteredString; 
    } 
    void addConstraint(char ch) 
    { 
        if (!contains(this->constraints, ch)) 
        { 
            this->constraints += ch; 
        } 
    } 
    void deleteConstraint(char ch) 
    { 
        if (contains(this->constraints, ch)) 
        { 
            int pos = this->constraints.find(ch); 
            this->constraints.erase(this->constraints.begin() + pos); 
            this->setEntered(removeUnmatched(this->constraints, this->enteredString)); 
        } 
    } 
 
    StringWithConstraints operator+(const StringWithConstraints &other) 
    { 
        StringWithConstraints result; 
        string newConstraint = removeUnmatched(this->constraints, other.constraints); 
        string text = this->enteredString + other.enteredString; 
        cout << newConstraint << endl; 
        result.setConstraints(newConstraint); 
        result.setEntered(removeUnmatched(newConstraint, text)); 
        return result; 
    } 
 
    friend std::ostream &operator<<(std::ostream &os, const StringWithConstraints &p); 
    friend std::istream &operator>>(std::istream &is, StringWithConstraints &str); 
    // friend std::ifstream &operator<<(std::ifstream &file, const StringWithConstraints &str); 
    friend std::ifstream &operator>>(std::ifstream &file, const StringWithConstraints &str); 
    friend bool isInConstraints(StringWithConstraints &str); 
}; 
 
bool isInConstraints(StringWithConstraints &str) 
{ 
    for (int i = 0; i < str.enteredLength; i++) 
    { 
        bool isFound = (str.constraints.find(str.enteredString[i]) == std::string::npos); 
        bool isSpace = (str.enteredString[i] == ' '); 
        if (isFound && !isSpace) 
        { 
            return false; 
        } 
    } 
    return true; 
} 
 
std::ostream &operator<<(std::ostream &os, const StringWithConstraints &str) 
{ 
    return os << "(" << str.constraints << "): " << str.enteredString << endl; 
} 
 
std::ifstream &operator>>(std::ifstream &file, StringWithConstraints &example) 
{ 
    string str, buff; 
    int end; 
    getline(file, str); 
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] != ' ') 
            buff += str[i]; 
        else 
        { 
            end = i + 1; 
            break; 
        } 
    } 
    example.setConstraints(buff); 
    example.setEntered(str.substr(end, str.length())); 
    if (!isInConstraints(example)) 
    { 
        example.setEntered(removeUnmatched(example.getConstraints(), example.
        getEntered())); 
        cout << "One of Symbols that you entered is not allowed, so it was deleted!" << endl; 
    } 
    return file; 
} 
 
std::istream &operator>>(std::istream &is, StringWithConstraints &str) 
{ 
    string constr, entr; 
    cout << "Enter allowed chars in one string: "; 
    is >> constr; 
    is.ignore(); 
    str.setConstraints(constr); 
    cout << "Enter your string: "; 
    getline(is, entr); 
    str.setEntered(entr); 
    if (!isInConstraints(str)) 
    { 
        str.setEntered(removeUnmatched(str.constraints, str.enteredString)); 
        cout << "One of Symbols that you entered is not allowed, so it was deleted!" << endl; 
    } 
    return is; 
} 
 
int main() 
{ 
    string str; 
    string filename = "data.txt"; 
    ifstream file(filename); 
    if (file.fail()) 
    { 
        cout << "There is no file named '" << filename << "'"; 
    } 
    else 
    { 
        StringWithConstraints my_str; 
        file >> my_str; 
        cout << my_str.getLength() << endl; 
        cout << my_str << endl; 
 
        file >> my_str; 
        cout << my_str.getLength() << endl; 
        cout << my_str << endl; 
 
        file >> my_str; 
        cout << my_str.getLength() << endl; 
        cout << my_str << endl; 
 
        cout << endl 
             << "Adding 'k' to constraints - " << endl; 
        my_str.addConstraint('k'); 
        cout << my_str << endl; 
 
        cout << endl 
             << "Removing 'h' from constraints - " << endl; 
        my_str.deleteConstraint('h'); 
        cout << my_str << endl; 
 
        StringWithConstraints second("abcmhtxso", "some text"); 
        cout << second << endl; 
 
        cout << endl 
             << "Adding strings: " << endl; 
        StringWithConstraints third = my_str + second; 
        cout << third << endl; 
    } 
 
    // StringWithConstraints my_str; 
    // cin >> my_str; 
    // cout << endl; 
    // cout << my_str << endl; 
 
    return 0; 
}