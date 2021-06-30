#include <stdio.h>
#include <math.h>

double calculateFunction(double x) {
    if (fabs(x)>2) {
        return pow(x,5) + 5*pow(x,3) + x + 1;
    } else {
        return sqrt(pow(M_E,2*x+1)+1) + 7;
    }
}

double calculateWithXY(double (*function)(double), double x, double y) {
    return pow((*function)(x)+(*function)(y),2);
}
void calculateBetween(double (*function)(double), double from, double to, double step, void (*callback)(double,double)) {
    double index = from-step;
    do {
        index += step;
        (*callback)(index,(*function)(index));
    } while (index < to);
}
void printWithFormat(double index, double result) {
    printf("<%0.2lf,%0.2lf>\n",index,result);
    return;
}

int main() {
    double x,y;
    printf("Cau 2\n");
    printf("Nhap x, y: ");
    scanf("%lf %lf",&x,&y);
    printf("%lf\n",calculateWithXY(calculateFunction,x,y));
    printf("Cau 3\n");
    calculateBetween(calculateFunction,-5.0, 3.0, 0.1, printWithFormat);
    return 0;
}