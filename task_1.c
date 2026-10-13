#include <stdio.h>
#include <math.h>
#include <windows.h>

#define GROUP 79
#define VARIANT 3
#define COURSE 4

/* Завдання 1: функція отримує АДРЕСИ змінних і змінює їх значення */
void Calculations(int *group, int *variant, double *course)
{
    double sum = *group + *variant + *course;
    double product = (double)*group * *variant * *course;
    double trig;

    if (*variant % 2 == 0)
        trig = sin(sum);
    else
        trig = cos(product);

    *group = (int)sum;
    *variant = (int)product;
    *course = trig;
}

int main(void)
{   
    /* Для виведення українських літер */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int group = GROUP;
    int variant = VARIANT;
    double course  = COURSE;

    printf("Початкові значення: група = %d, варіант = %d, курс = %g\n",
           group, variant, course);

    Calculations(&group, &variant, &course);

    printf("Нові значення: група = %d, варіант = %d, курс = %.6f\n\n",
           group, variant, course);
}