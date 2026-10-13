#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void print_array(const int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("Елемент %3d: значення = %d | адреса = %p\n",
               i, *(arr + i), (const void *)(arr + i));
    }
}

/* Завдання 4: пошук мінімуму та максимуму через вказівники і обмін їх місцями */
int main(void)
{
    /* Для виведення українських літер */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    printf("Введіть розмір масиву N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректний розмір масиву!\n");
        return 1;
    }

    int arr[n];
    srand((unsigned)time(NULL));

    int *ptr = arr;
    for (int i = 0; i < n; i++)
        *(ptr++) = rand() % 100;

    printf("\n=== 1. Початковий масив ===\n");
    print_array(arr, n);

    int *min_ptr = arr;
    int *max_ptr = arr;
    for (ptr = arr + 1; ptr < arr + n; ptr++) {
        if (*ptr < *min_ptr) min_ptr = ptr;
        if (*ptr > *max_ptr) max_ptr = ptr;
    }

    printf("\n=== 2. Результати пошуку ===\n");
    printf("Мінімальний елемент: значення = %d | адреса = %p\n",
           *min_ptr, (void *)min_ptr);
    printf("Максимальний елемент: значення = %d | адреса = %p\n",
           *max_ptr, (void *)max_ptr);

    int tmp  = *min_ptr;
    *min_ptr = *max_ptr;
    *max_ptr = tmp;

    printf("\n=== 3. Результуючий масив після обміну ===\n");
    print_array(arr, n);
    return 0;
}