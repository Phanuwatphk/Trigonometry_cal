#include <stdio.h>
#include <math.h>

int main(){
    int deg, q, a, degin;//deg = degree, q = quadrant, a = alfa, degin = degrees input
    char sinv[5][10] = {"0", "1/2", "sqrt(2)/2", "sqrt(3)/2", "1"};//0 30 45 60 90 degrees
    char cosv[5][10] = {"1", "sqrt(3)/2", "sqrt(2)/2", "1/2", "0"};//0 30 45 60 90 degrees
    char tanv[5][10] = {"0", "sqrt(3)/3", "1", "sqrt(3)", "undefine"};//0 30 45 60 90 degrees
    char sins, coss, tans;

    printf("Enter the angle in degrees : ");
    scanf("%d", &degin);

    if(deg > 360 || deg < -360){
        deg = degin % 360;
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
            printf("sin = %c%s\n", sins, sinv[0]);
            printf("cos = %c%s\n", coss, cosv[0]);
            printf("tan = %c%s\n", tans, tanv[0]);
            break;
        case 30:
            printf("sin = %c%s\n", sins, sinv[1]);
            printf("cos = %c%s\n", coss, cosv[1]);
            printf("tan = %c%s\n", tans, tanv[1]);
            break;
        case 45:
            printf("sin = %c%s\n", sins, sinv[2]);
            printf("cos = %c%s\n", coss, cosv[2]);
            printf("tan = %c%s\n", tans, tanv[2]);
            break;
        case 60:
            printf("sin = %c%s\n", sins, sinv[3]);
            printf("cos = %c%s\n", coss, cosv[3]);
            printf("tan = %c%s\n", tans, tanv[3]);
            break;
        case 90:
            printf("sin = %c%s\n", sins, sinv[4]);
            printf("cos = %c%s\n", coss, cosv[4]);
            printf("tan = %c%s\n", tans, tanv[4]);
            break;
        default:
            printf("sin = %f\n", sin(degin*0.0174532925));
            printf("cos = %f\n", cos(degin*0.0174532925));
            printf("tan = %f\n", tan(degin*0.0174532925));
            break;
    }

    return 0;
}