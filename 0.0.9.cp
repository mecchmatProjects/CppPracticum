#include <iostream>

int main()

{
    float x;
    std::cin>>x;
    float y = x * x; // 2
    float z = y * y; // 4
    std::cout<<"a)"<<z<<"\n";
    float d = y * y * y; // 6
    std::cout<<"б)"<<d<<"\n";
    float k = z * y * y * x; // 9
    std::cout<<"в)"<<k<<"\n";
    float g = d * z * y * y * x; // 15
    std::cout<<"г)"<<g<<"\n";
    float s = d * d * d * d * y * y; // 28
    std::cout<<"ґ)"<<s<<"\n";
    float r = g * g * g * g * y * y; // 64
    std::cout<<"д)"<<r<<"\n";
    
    
}

