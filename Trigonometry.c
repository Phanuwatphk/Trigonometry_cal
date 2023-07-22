#include <stdio.h>
#include <math.h>

int main(){
    int deg, q, a;//deg = degree, q = quadrant, a = alfa
    char sin[5][10] = {"0", "1/2", "sqrt(2)/2", "sqrt(3)/2", "1"};//0 30 45 60 90 degrees
    char cos[5][10] = {"1", "sqrt(3)/2", "sqrt(2)/2", "1/2", "0"};
    char tan[5][10] = {"0", "sqrt(3)/3", "1", "sqrt(3)", "undefine"};
    char sins, coss, tans;

    printf("Enter degree : ");
    scanf("%d", &deg);

    if(deg > 360 || deg < 360){
        deg %= 360;
    }

    //check quadrant
    //q = (deg >= 270 || deg <= -270) ? (deg > 0) ? 4 : 1 : (deg >= 180 || deg <= -180) ? (deg > 0) ? 3 : 2 : (deg >= 90 || deg <= -90) ? (deg > 0) ? 2 : 3 : (deg > 0) ? 1 : 4;
    if(deg >= 270 || deg <= -270){
        q = deg > 0 ? 4 : 1;
    }
    else if(deg >= 180 || deg <= -180){
        q = deg > 0 ? 3 : 2;
    }
    else{
        q = (deg >= 90 || deg <= -90) ? (deg > 0) ? 2 : 3 : (deg > 0) ? 1 : 4;
    }

    if((deg <= 90 && deg > 0) || (deg > -90 && deg < 0)){
        a = abs(deg);
        goto j90;
    }
    if(deg >= 270 || deg <= -270){
        q = deg > 0 ? 4 : 1;
        a = 360 - abs(deg);
    }
    else if(deg < 270 && deg > 0){
        q = deg > 180 ? 3 : deg > 90 ? 2 : 1;
        a = deg > 180 ? deg - 180 : 180 - deg;
    }
    else if(deg > -270){
        q = deg < -180 ? 2 : deg < -90 ? 3 : 4;
        a = abs(deg + 180);
    }

    j90:
    sins = (q == 3 || q == 4) ? '-' : '\0';//sin
    coss = (q == 2 || q == 3) ? '-' : '\0';//cos
    tans = ((q == 2 && a != 0) || q == 4) ? '-' : '\0';//tan

    //print values
    switch(a){
        case 0:
            printf("sin = %c%s\n", sins, sin[0]);
            printf("cos = %c%s\n", coss, cos[0]);
            printf("tan = %c%s\n", tans, tan[0]);
            break;
        case 30:
            printf("sin = %c%s\n", sins, sin[1]);
            printf("cos = %c%s\n", coss, cos[1]);
            printf("tan = %c%s\n", tans, tan[1]);
            break;
        case 45:
            printf("sin = %c%s\n", sins, sin[2]);
            printf("cos = %c%s\n", coss, cos[2]);
            printf("tan = %c%s\n", tans, tan[2]);
            break;
        case 60:
            printf("sin = %c%s\n", sins, sin[3]);
            printf("cos = %c%s\n", coss, cos[3]);
            printf("tan = %c%s\n", tans, tan[3]);
            break;
        case 90:
            printf("sin = %c%s\n", sins, sin[4]);
            printf("cos = %c%s\n", coss, cos[4]);
            printf("tan = %c%s\n", tans, tan[4]);
            break;
        default:
            printf("Error");
            break;
    }

    return 0;
}