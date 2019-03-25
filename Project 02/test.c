#include "test.h"

int main()
{
    const short N = 20;
    int **mas;
    t_square *answer;
    mas = (int**)malloc(sizeof(int*) * N);
    for(size_t i = 0; i < N; i++)
    	mas[i] = (int*)malloc(sizeof(int) * N);
    for(size_t i = 0; i < N; i++)
    {
        for(size_t j = 0; j < N; j++)
        {
            mas[i][j] = rand() % 2;
        }
    }
       for(size_t p = 0; p < N; p++)
    {
        for(size_t pp = 0; pp < N; pp++)
        {
            printf("%d\t", mas[p][pp]);
        }
       printf("\n");
    }
	answer = ft_create_answer();
	ft_search(mas,answer, N, N);
	 printf("\n");
	  printf("\n");
  for(size_t p = 0; p < N; p++)
    {
        for(size_t pp = 0; pp < N; pp++)
        {
            printf("%d\t", mas[p][pp]);
        }
       printf("\n");
    }
printf("\n");
printf("%d\n", answer->j);
printf("%d\n", answer->i);
printf("%d\n", answer->size);
printf("\n");printf("\n");

char o = 'o';
char p = '.';
char x = 'x';


ft_print_answer(mas, answer, N, N, o, p, x);
    return 0;
}