#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define WAY "/Users/temka/Documents/nu lp/AP_2s/AP7/AP7/File.txt"            //шлях до файла
#define WAY_OUTPUT "/Users/temka/Documents/nu lp/AP_2s/AP7/AP7/longword.txt"            //шлях до файла для виведення

int InputFromFile(char buf[][500]);
void Output(char buf[][500], int kst);
void ChekBuf(char buf[][500], int kst, FILE* f);
void PrintInFile(char* str, FILE* f);

int main()
{
    char buf[20][500];
    int kst = InputFromFile(buf);
    FILE* fot = fopen(WAY_OUTPUT, "w");

    puts("Ваші дані");

    Output(buf, kst);

    ChekBuf(buf, kst, fot);

    fclose(fot);
    getchar();
    getchar();
    return 0;
}

int InputFromFile(char buf[][500])
{
    FILE* f = fopen(WAY, "r");
    if (f == NULL) {
        puts("Не вдалося знайти файл");
        exit(-3);
    }
    int i = 0;
    while (fgets(buf[i++], 500, f) != NULL);
    fclose(f);
    return i-1;
}

void Output(char buf[][500], int kst)
{
    for (int i = 0; i < kst; i++)
        printf("%s", buf[i]);
}

void ChekBuf(char buf[][500], int kst, FILE* f)
{
    for (int i = 0; i < kst; i++)
    {
        char* pch = strtok(buf[i], " ,.-\t:;\n?!");

        while (pch != NULL)
        {
            if (strlen(pch) >= 7) {
                PrintInFile(pch, f);
            }
            pch = strtok(NULL, " ,.-\t:;\n?!");
        }

    }
}

void PrintInFile(char *str, FILE*f)
{
    char* p = str;

    char low[] = "abcdefghijklmnopqrstuvwxyz";
    char up[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (*p!='\0')
    {
        for (int i = 0; i < strlen(low); i++)
            if (*p == low[i])
                *p = up[i];
        p++;
    }
    fputs(str, f);
    fputc(' ', f);
}
