#include <iostream>
 
int main() {
    int last = 0, next = 1;
    long sum = 1;
    
        for(; next < 1000; next += last){
        last = next - last;
        sum += next;
    }
    std::cout << sum;
    return 0;
}
