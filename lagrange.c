#include <stdio.h>

double lagrange(double sample_x[], double sample_y[], double x, int size) {
    double tmp;
    double ans = 0;
    
    for (int i=0; i<size; i++) {
        tmp = sample_y[i];
        for (int j=0; j<size; j++) {
            if (i != j) {
                tmp *= (x - sample_x[j]) / (sample_x[i] - sample_x[j]);
            }
        }
        ans += tmp;
    }

    return ans;
}

int main(void) {
    int size = 3;
    double sample_x[] = {0.5, 1.0, 2.0};
    double sample_y[] = {1.65, 2.72, 7.39};
    
    double x;
    printf("x = ");
    scanf("%lf", &x);

    printf("f(x) = %f\n", lagrange(sample_x, sample_y, x, size));

    return 0;
}