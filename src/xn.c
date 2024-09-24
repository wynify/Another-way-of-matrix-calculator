#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_poly.h>


// Функция для генерации случайного полинома порядка n
void generate_polynomial(double *coefficients, int n) {
    for (int i = 0; i <= n; i++) {
        coefficients[i] = (double)(rand() % 100) / 10.0; // Случайные коэффициенты
    }
}

// Функция для печати полинома
void print_polynomial(double *coefficients, int n) {
    for (int i = 0; i < n; i++) {
        printf("+%.2fx^%d", coefficients[i], n - i);
    }
    printf("\n");
}

int XN(int n) {

    double coefficients[n + 1];

    generate_polynomial(coefficients, n);

    printf("Generated polinom: ");
    print_polynomial(coefficients, n);

    // Массив для хранения корней
    double z[2 * n];
    gsl_poly_complex_workspace *w = gsl_poly_complex_workspace_alloc(n + 1);

    // Нахождение корней
    gsl_poly_complex_solve(coefficients, n + 1, w, z);

    printf("Roots:\n");
    for (int i = 0; i < n; i++) {
        printf("z%d = %+.2f %+.2fi\n", i, z[2 * i], z[2 * i + 1]);
    }

    gsl_poly_complex_workspace_free(w);

    return 0;
}
