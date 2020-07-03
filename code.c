//Очередь
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 200
#define K 200
struct queue //очередь
{
	char que[N];
	int quefirst, quelast;
};
void inque(struct queue* q) //инициализация очереди
{
	q->quefirst = 1;
	q->quelast = 0;
	return;
}
void insert(struct queue* q, char x) //добавление в очередь.
{
	if (q->quelast <= N )
	{
		q->quelast++;
		q->que[q->quelast] = x;
	}
	else
		printf("queue is empty\n");
	return;
}
int isempty(struct queue* q) //проверка пуста ли очередь
{
	if (q->quelast < q->quefirst)
		return 1;
	else  return 0;
}
void print(struct queue* q) //вывод элементов
{
	int h;
	if (isempty(q) == 1)
	{
		printf("queue is empty\n");
		return;
	}
	for (h = q->quefirst; h <= q->quelast; h++)
		printf("%c ", q->que[h]);
	return;
}
int removex(struct queue* q)
{
	char x;
	if (isempty(q) == 1) {
		printf("queue is empty\n");
		return(0);
	}
	x = q->que[q->quefirst];
	q->quefirst++;
	return x;
}
void main()
{
	char sym[K];
	int i = 0;
	int flag1=0, flag2=0;
	struct queue* q;
	char a;
	q = malloc(sizeof(struct queue));
	inque(q);
	printf("enetry element's\n");
	while (i < N)
	{
		scanf("%c", &a);
		if (a == ' ')
		{
			flag1 = 1;
		}
		if (a == '\n')
		{
			flag2 = 1;
		}
		if (flag1 == 0)
		{
			if (flag2 == 0)
			{
				sym[i] = a;
				i++;
			}
		}
		if (sym[i] == '\n')
		{
			i--;
		}
		flag1 = 0;
		flag2 = 0;
	}
	for (i = 0; i < N; i++)
	{
		insert(q, sym[i]);
	}
	print(q);
	while (q->quefirst != N+1)
	{
		a = removex(q);
		printf("delet element %d\n", a);
		print(q);
	}
	system("pause");
}

