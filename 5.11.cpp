#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Get_Up_and_Low_Symbol(char& up_symbol, char& low_symbol, char symbol)
{
  int position = (int)symbol;
  if (position >= 97)
  {
    up_symbol = (char)symbol - 32;
  }
  else
  {
    low_symbol = (char)symbol + 32;
  }
}

string Change_Word(string& word)
{
  string new_word;

  for (int i = 0; i < word.size(); i++)
  {
    if (((int)word[i] >= 65 && (int)word[i] <= 90) || ((int)word[i] >= 97 && (int)word[i] <= 122))
    {
      new_word += word[i];
    }
  }
  return new_word;
}

int main()
{
  char symbol;
  cout << "Enter symbol: ";
  cin >> symbol;

  char up_symbol = symbol, low_symbol = symbol;
  Get_Up_and_Low_Symbol(up_symbol, low_symbol, symbol);

  string word;
  ifstream fin("text.txt"); 
  ofstream fout("answer.txt");
  while (fin >> word)
  {
    word = Change_Word(word);
    if (up_symbol == word[0] || low_symbol == word[0])
    {
      fout << word << " ";
    }
  }
  cout << "Result is in the file" << endl;
}
