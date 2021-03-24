
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
void funcC(char * str) { 
char buff[255]; 
int j=0; 
int i=0; 
while(str[i]!='\0') { 
   
  if(str[i] == 'p' && str[i+1] == 'h') { 
   buff[j] = 'f'; 
   j++; i+=2; 
  } 
  else { 
    buff[j] = str[i++];
   j++; 
  } 
 } 
 printf("%s", buff); 
} 

void funcG(char * str) { 
char buff[255]; 
int j=0; 
int i=0; 

for (int i = 0; i < strlen(str); i++) {
  if (str[i] == ' ') { 
    while (k!=0) { 
    buf[j] = ' '; 
    j++; 
    k = 1; 
   } 
  } 
 else { 
  buf[j] = str[i]; 
  j++; 
  k = 0; 
  } 
 }
 buf[j] = '\0'; 
cout << buf; 
}


void funcB(char *str) {
    std::string output;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == '+' && i + 1 < strlen(str) && isdigit(str[i + 1])) {
            continue;
        }
        output += str[i];
    }
    cout << output;
}



int main() {
 char lol[100]; 
  cin.getline(lol, 255);
 //fgets(lol, 255, stdin); 
 //gets(lol); 

 func(lol); 
return 0; 
}

/*
#include <iostream> using namespace std; int main() { 
char* str = new char[255]; char* buf = new char[255]; int j = 0; cin.getline(str, 255); int k = 0; 
return 0; 

*/
