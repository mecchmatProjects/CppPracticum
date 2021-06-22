#include <iostream>

using namespace std;

typedef struct Book{
    string font;
    string author;
    string name;
} Book;

typedef struct Reader{
    int ticket;
    string surname;
    char* dt;
} Reader;

void input1(Book* book){
    cout << "font = ";
    cin >> book -> font;
    cout << "author = ";
    cin >> book -> author;
    cout << "name = ";
    cin >> book -> name;
}

void input2(Reader* reader){
    cout << " ticket= ";
    cin >> reader -> ticket;
    cout << "surname = ";
    cin >> reader -> surname;
    cout << "dt = ";
    cin >> reader -> dt;
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    Book books[n];
    Reader readers[n];
    for(int i = 0; i < n; i++){
        input1(&books[i]);
        input2(&readers[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << "\nYour book's font is " << books[i].font;
        cout << "\nYour book's author is " << books[i].author;
        cout << "\nYour book's name is " << books[i].name;
        cout << "\nYour reader's ticket is " << readers[i].ticket;
        cout << "\nYour reader's surname is " << readers[i].surname;
        cout << "\nYour reader's dt is " << readers[i].dt;
        }
    }