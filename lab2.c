/*

				Вариант 3
		Расположить строки в алфавитном порядке 
		Входные параметры:
		1. Массив 
		2. Размерность массива 
		Выходные параметры:
		1. Количество перестановок 
		2. Первая буква первой строки 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>
#define BUFF_SIZE 1024

    char** readMas(int count){
	char buffer[BUFF_SIZE];
	char **mas = (char **)malloc(sizeof(char *)*count);
    for (int i = 0; i < count ; i++)
	{
		fgets(buffer, BUFF_SIZE, stdin);
		mas[i] = (char*)malloc(strlen(buffer) * sizeof(char));
		strcpy(mas[i], buffer);
	}
	return mas;
	}
	void printMas(char **mas, int count){
	for (int i = 0; i < count; i++) {
		printf("%s", mas[i]);
		}
}
void freeMas(char **mas, int count){
	for (int i = 0; i < count; i++){
        free(mas[i]); 
    }
    free(mas);
}
int sort(char **mass, int n)
    {
        char *tmp;
        int kol=0;
        for(int j=0; j < n; j++)
        {
            for(int i=0; i < n-1; i++)
            {
                if((strcmp(mass[i], mass[i+1]))>0)
                {
                    tmp = mass[i];
                    mass[i] = mass[i+1];
                    mass[i+1] = tmp;
                    kol++;
                }
            }
       }
       return kol;
}
int main(int argc, char **argv){
	char **mas = NULL; 
	int n;
	printf("Введите кол-во строк: ");
	scanf("%d\n", &n);
	int count = n;
	mas = readMas(count);
	int kol = sort(mas, count);
		printf("\nСортировка алфавитном порядке: \n\n");
	sort(mas, n);
	printMas(mas, count);
		printf("\nКолличество перестановок:  ");
		printf("%d\n", kol); 
		printf("Первая буква первой строки: ");   
		printf("%c\n", mas[0][0]); 
    freeMas(mas, count);
}
