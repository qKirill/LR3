#include <stdio.h>
#include <windows.h>

/* Завдання 2: рекурсивна функція обчислення суми цифр числа без циклів */
int sum_of_digits(int n)
{
    if (n == 0)
        return 0;

    int d = n % 10;
    if (d < 0)
        d = -d;

    return d + sum_of_digits(n / 10);
}

int main(void)
{   
    /* Для виведення українських літер */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    printf("Введіть ціле число: ");
    if (scanf("%d", &n) != 1) {
        printf("Помилка введення!\n");
        return 1;
    }
    printf("Сума цифр числа %d дорівнює: %d\n", n, sum_of_digits(n));
    return 0;
}