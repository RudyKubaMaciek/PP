#define _CRT_SECURE_NO_WARNINGS / * Wyłącza ostrzeżenia Visual Studio dotyczące "przestarzałych" funkcji * /
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 128

int main() {
    FILE *inputFile = fopen("dane.txt", "r");
    if (inputFile == NULL) {
        printf("Blad: Nie mozna otworzyc pliku dane.txt!\n");
        printf("Upewnij sie, ze plik znajduje sie w tym samym folderze co plik z kodem źródlowym.\n");
        return 1;
    }

    FILE *outputFile = fopen("dane_trzy_kolumny.txt", "w");
    if (outputFile == NULL) {
        printf("Blad: Nie mozna utworzyc pliku wyjsciowego!\n");
        fclose(inputFile);
        return 1;
    }

    fprintf(outputFile, "x\ty\tz\n");

    char liniaX[MAX_LINE_LENGTH];
    char liniaY[MAX_LINE_LENGTH];
    char liniaZ[MAX_LINE_LENGTH];


    while (fgets(liniaX, sizeof(liniaX), inputFile) != NULL) {
        

        liniaX[strcspn(liniaX, "\n")] = 0;


        if (fgets(liniaY, sizeof(liniaY), inputFile) != NULL) {
            liniaY[strcspn(liniaY, "\n")] = 0;
        } else {
            liniaY[0] = '\0'; 
        }

        
        if (fgets(liniaZ, sizeof(liniaZ), inputFile) != NULL) {
            liniaZ[strcspn(liniaZ, "\n")] = 0;
        } else {
            liniaZ[0] = '\0';
        }

        fprintf(outputFile, "%s\t%s\t%s\n", liniaX, liniaY, liniaZ);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Wygenerowano plik 'dane_trzy_kolumny.txt'.\n");
    return 0;
}