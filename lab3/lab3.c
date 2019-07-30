/*
				Вариант 3
		Название книги 
		Год издания 
		Количество страниц Стоимость 
		Расположить записи в массиве в алфавитном порядке (по названию) 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	char b[50];
	int year;
	int kol;
	int cumma;
}book;

void readBooks(book *st)
{
	printf("Введите название книги: ");
	scanf("%s", st->b);
	printf("Введите год издания: ");
	scanf("%d", &st->year);
	printf("Введите колличество страниц: ");
	scanf("%d", &st->kol);
	printf("Ветите стоимость книги: ");
	scanf("%d", &st->cumma);
	printf("----------------------------------------\n\n");
}

static int cmp(const void *p1, const void *p2)
{
	book * st1 = *(book**)p1;
	book * st2 = *(book**)p2;
	return strcmp(st1->b, st2->b);
}
int main(int argc, char **argv)
{
	int count = 0;
	printf("Введите колличество книг: ");
	scanf("%d", &count);
	printf("----------------------------------------\n\n");
	book** st = (book**)malloc(sizeof(book*)*count);
	for(int i = 0; i < count; i++)
	{
		st[i]= malloc(sizeof(book));
		readBooks(st[i]);
	}
		printf("\tСортировка по названию\n\n");
		qsort(st, count, sizeof(book*), cmp);
	for(int i = 0; i < count; i++)
	{
		printf("\tКнига номер %d\n", i+1);
		printf("\t-------------\n\n");
		printf("Название книги: %s\n", st[i]->b);
		printf("Год издания: %d\n", st[i]->year);
		printf("Колличество страниц: %d\n", st[i]->kol);
		printf("Стоимость: %d\n", st[i]-> cumma);
		printf("\n");
	}
	for(int i = 0; i < count; i++)
	{
		free(st[i]);
	}
free(st);
return 0;
}
