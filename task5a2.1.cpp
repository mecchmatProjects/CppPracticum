include<iostream>


using namespace std;

string f(string& s){
    size_t first_dot = s.find_first_of(".");
    size_t last_dot = s.find_last_of(".");
    return s.substr(first_dot+1, last_dot-first_dot-1);
}

int main() {
    string s;
    cin >> s;
    cout << f(s);
}
