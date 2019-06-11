#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>


using namespace std;

const float delta = 0.00001,
            e = 0.0001;

float func(float x){
    return exp(x);
}

double func2(double x1,double x2,double x3, double x4){
    return 100*pow((x2-pow(x1,2)),2)+pow((1-x1),2)+
    90*(x4-pow(x3,2))+pow((1-x3),2)+10,2*pow((x2-1),2)+
    pow((x4-1),2)+19,8*(x2-1)*(x4-1);
}

int fibonacci(int k){
    int F(1), lastF(1), lastlastF(1), n(2);

    if (k == 1 || k == 2)
        return 1;

    while (n != k) {
        lastlastF = lastF;
        lastF = F;
        F = lastF + lastlastF;
        n++;
    }
    return F;
}

float meth1 (float a, float b){
    cout << "___Method 1___" << endl << endl;

    int n(0);
    float x1(0), x2(0);

    while (b - a > e) {
        x1 = ((a + b) / 2.0) - delta;
        x2 = ((a + b) / 2.0) + delta;
        n++;
        if (func(x1)< func(x2))
            b = x2;
        else
            if (func(x1) > func(x2))
                a = x1;
            else {
                a = x1;
                b = x2;
            }
        float f1 = func(x1),
                f2 = func(x2);
        printf("%d %.5f %.5f %.5f %.5f %.5f %.5f\n", n, a, x1, x2, b, f1, f2);
    }

    return (x1+x2)/2.0;
}

float meth2 (float a, float b){

    int n(0);
    cout << "___Method 2___" << endl << endl;
    float x1(0), x2(0);

    while (b - a > e) {
        x1 = a + 0.38197*(b - a);
        x2 = a + 0.61801*(b - a);
        n++;
        if (func(x1)< func(x2))
            b = x2;
        else
            if (func(x1) > func(x2))
                a = x1;
            else {
                a = x1;
                b = x2;
            }
        cout << n << " ";
        float f1 = func(x1),
                f2 = func(x2);
        printf("%d %.5f %.5f %.5f %.5f %.5f %.5f\n", n, a, x1, x2, b, f1, f2);
    }

    return (x1+x2)/2.0;
}

float meth3 (float a, float b){
    cout << "___Method 3___" << endl << endl;

    int n(1), k(1);
    double x1(0), x2(0);

    while (((b - a)/ e) >= fibonacci(n+2))
        n++;

    while (k != n) {
        x1 = a + (fibonacci(n-k+1)*(b-a))/(fibonacci(n-k+3));
        x2 = a + (fibonacci(n-k+2)*(b-a))/(fibonacci(n-k+3));

        if (func(x1)< func(x2))
            b = x2;
        else
            if (func(x1) > func(x2))
                a = x1;
            else {
                a = x1;
                b = x2;
            }

        float f1 = func(x1),
                f2 = func(x2);
        printf("%d %.5f %.5f %.5f %.5f %.5f %.5f\n", k, a, x1, x2, b, f1, f2);
        k++;
    }

    return (x1+x2)/2.0;

}

int counter = 0;

double f( double x1, double x2, double x3, double x4) {
    return 100 * pow((x2 - pow(x1, 2)), 2) + pow((1 - x1), 2) +
    90 * (x4 - pow(x3, 2)) + pow((1 - x3), 2) + 10, 2 * pow((x2 - 1), 2) +
    pow((x4 - 1), 2) + 19, 8 * (x2 - 1)*(x4 - 1);
}

double gradX1( double x1, double x2, double x3, double x4) {
    return -400 * x1*(x2 - pow(x1, 2) - 2 * (1 - x1));
}

double gradX2( double x1, double x2, double x3, double x4) {
    return 200 * (x2 - pow(x1, 2)) + 20, 4 * (x2 - 1) + 19, 8 * (x4 - 1);
}

double gradX3 (double x1, double x2, double x3, double x4) {
    return -180 * x3 - 2 * (1 - x3);
}

double gradX4( double x1, double x2, double x3, double x4) {
    return 90 + 2 * (x4 - 1) + 19, 8 * (x2 - 1);
}

void output(double x1, double x2, double x3, double x4) {
    counter++;
    cout << "Iteration " << counter << "\n";
    cout << setw(14) << fixed << setprecision(5) << x1;
    cout << setw(14) << fixed << setprecision(5) << x2;
    cout << setw(14) << fixed << setprecision(5) << x3;
    cout << setw(14) << fixed << setprecision(5) << x4;
    cout << setw(14) << fixed << setprecision(5) << f(x1, x2, x3, x4) << "\n";
}

double lambdaUp( double lambda, double x1, double x2, double x3, double x4, double gradX1Cur, double gradX2Cur, double gradX3Cur, double gradX4Cur)
{
    while (f(x1 - lambda * gradX1Cur, x2 - lambda * gradX2Cur, x3 - lambda * gradX3Cur, x4 - lambda * gradX4Cur) < f(x1, x2, x3, x4)) {
    lambda = lambda * 2;
    }
        return lambda / 2;
    }

double lambdaDown(double lambda, double x1, double x2, double x3, double x4, double gradX1Cur, double gradX2Cur, double gradX3Cur, double gradX4Cur) {
    while (f(x1 - lambda * gradX1Cur, x2 - lambda * gradX2Cur, x3 - lambda * gradX3Cur, x4 - lambda * gradX4Cur) > f(x1, x2, x3, x4)) {
    lambda = lambda / 2;
    }
        return lambda;
    }

int main() {
    double a(0),b(100);
    printf("%.5f\n", meth1(a, b));
    printf("%.5f\n", meth2(a, b));
    printf("%.5f\n", meth3(a, b));

    double eps = 0.001;
    double x1 = 40;
    double x2 = 55;
    double x3 = 13;
    double x4 = 85;
    output(x1, x2, x3, x4);

    double gradX1Cur = gradX1(x1, x2, x3, x4);
    double gradX2Cur = gradX2(x1, x2, x3, x4);
    double gradX3Cur = gradX3(x1, x2, x3, x4);
    double gradX4Cur = gradX4(x1, x2, x3, x4);

    double lambda = 10;

    while (abs((f(x1 - lambda * gradX1Cur, x2 - lambda * gradX2Cur, x3 - lambda * gradX3Cur, x4 - lambda * gradX4Cur) - f(x1, x2,x3,x4))) > eps) {
        //while(sqrt(pow(gradX1Cur, 2) + pow(gradX2Cur, 2)) > eps) {
        lambda = lambdaDown(lambda, x1, x2, x3, x4, gradX1Cur, gradX2Cur , gradX3Cur, gradX4Cur);
        lambda = lambdaUp(lambda, x1, x2, x3, x4, gradX1Cur, gradX2Cur, gradX3Cur, gradX4Cur);

        x1 = x1 - lambda * gradX1Cur;
        x2 = x2 - lambda * gradX2Cur;
        x3 = x3 - lambda * gradX2Cur;
        x4 = x4 - lambda * gradX2Cur;

        gradX1Cur = gradX1(x1, x2, x3, x4);
        gradX2Cur = gradX2(x1, x2, x3, x4);
        gradX3Cur = gradX3(x1, x2, x3, x4);
        gradX4Cur = gradX4(x1, x2, x3, x4);

        output(x1, x2, x3, x4);
}
system("pause");
return 0;
}
