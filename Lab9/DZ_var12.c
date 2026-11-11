#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void draw_trapezia(char ch, int b, int h, int c) {
    int max_padding = (c - b) / 2;
    for (int i = 0; i < h; i++) {
        int left_spaces = max_padding - (max_padding * i) / (h > 1 ? (h - 1) : 1);
        int current_width = c - (2 * left_spaces);
        if (left_spaces > 0) {
            printf("%*s", left_spaces, "");
        }
        if (i == 0 || i == h - 1) {
            for (int j = 0; j < current_width; j++) {
                printf("%c", ch);
            }
        }
        else {
            printf("%c", ch);
            if (current_width > 2) {
                printf("%*s", current_width - 2, "");
            }
            if (current_width > 1) {
                printf("%c", ch);
            }
        }
        printf("\n");
    }
}

int main()
{
    int check = 1, b, h, c;
    char ch;
    setlocale(LC_ALL, "RUS");
    while (check != 0) {
        printf("Введите символ из которого будет строиться фигура:\n");
        scanf(" %c", &ch);
        printf("Введите меньшее основание:\n");
        scanf("%d", &b);
        printf("Введите высоту:\n");
        scanf("%d", &h);
        printf("Введите большее основание:\n");
        scanf("%d", &c);
        draw_trapezia(ch, b, h, c);
        printf("Продолжить ? (Да - введите любое число, Нет - введите 0)\n");
        scanf("%d", &check);
    }

    return 0;
}