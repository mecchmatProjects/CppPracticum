a) 4 за 2

#include <stdio.h>
#include <math.h>

int main(){
    float x;printf("x=");scanf("%f",&x);
    float a = x*x;
    printf("vyraz=%f", a*a);
    return 0;
}

б) 6 за 3

#include <stdio.h>
#include <math.h>

int main(){
    float x;printf("x=");scanf("%f",&x);
    float a = x*x;
    float b = a*a;
    printf("vyraz=%f", b*a);
    return 0;
}


в) 9 за 4

#include <stdio.h>
#include <math.h>

int main(){
    float x;printf("x=");scanf("%f",&x);
    float a = x*x;
    float b = a*a;
    float c = b*b;
    printf("vyraz=%f", c*x);
    return 0;
}


г) 15 за 5

#include <stdio.h>
#include <math.h>

int main(){
    float x;printf("x=");scanf("%f",&x);
    float a = x*x;
    float b = a*a;
    float x5 = b*x;
    float x15 = x5*x5*x5;
    printf("vyraz=%f", b, x15);
    return 0;
}


д) 28 за 6

#include <stdio.h>
#include <math.h>

int main(){
    float x;printf("x=");scanf("%f",&x);
    float a = x*x;
    float b = a*a;
    float c = b*b;
    float d = c*c;
    printf("vyraz=%f", d*c*b);
    return 0;
}
