/* problema2.c - Problema backtracking recursivo de sumas 
 *
 * Author: Sebastian Olivares Carrasco
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int backtracking_suma(int t, int n, int a, int numbers_i, int numbers[], int answer[], int answer_i)
{
  int result = -1;
  if (t == 0) 
    return 0;
  if (t - a == 0)
  {
    answer[0] = a;
    answer[answer_i] = -1;
    return 0;
  }
  else if (numbers_i < n)
  {
    if (t - (a+numbers[numbers_i]) >= 0)
    {
      answer[answer_i] = numbers[numbers_i];
      result = backtracking_suma(t - numbers[numbers_i], n, a, numbers_i+1, numbers, answer,answer_i+1);
    }
    else
      result = backtracking_suma(t, n, a, numbers_i+1, numbers, answer,answer_i);
  }
  else
    result = 1;

  return result; 
}

//int numbers[] = {53,51,49,46,45,45,44,41,39,38,37,35,27,10,8,7,6,4,2};

// Checkea si la respuesta ya se dio
int is_repeated(int answer[], int *total_answers[], int n)
{
  int result = 0;
  int j;
  for (int i = 0; i < n; i++)
  {
    if (total_answers[i] != 0)
    {
      j = 0;
      while(total_answers[i][j] != -1)
      {
        if (answer[j] == total_answers[i][j])
          result = 1;
        else
        {
          result = 0;
          break;
        }
        j++;
      }
    }
    else
      break;
  }
  return result;
}
int main (int argc, char *argv[])
{
  // Array de los numeros que suman "t"

  char c;
  char buffer[1024] = {0};
  int i = 0;
  int counter = 0;

  int t = 0;
  int n = 0;
  int *numbers;

  // Array de los numeros que suman "t"
  int *answer;
  // Para saltar respuestas ya dadas
  int **total_answers;

  // Consigue datos de una linea 
  while ((c = getc(stdin)) != EOF)
  {
      if (c == ' ' || c == '\n')
      {
        buffer[i++] = '\0';
        if (counter == 0)
          t = atoi(buffer);
        if (counter == 1)
        {
          n = atoi(buffer);
          numbers = malloc(n*sizeof(int));
          if (n == 0)
            break;
        }
        if (counter > 1)
          numbers[counter - 2] = atoi(buffer);

        counter++;
        buffer[0] = 0;
        i = 0;

        // Se pasa el array formado inmediamente por el algoritmo
        if (c == '\n')
        {
          if (n == 0)
            break;
          printf("Suma de %d:\n", t);
          total_answers = malloc(n*sizeof(int *));

          int answers_counter = 0;

          int result = -1;
          memset(total_answers, 0, n*sizeof(int *));
          for (int i = 0; i < n;i++)
          {
            for (int j = i; j < n;j++)
            {
              answer = malloc(n*sizeof(int));
              result = backtracking_suma(t, n, numbers[i], j+1, numbers, answer, 1);
              if (result == 0)
              {
                if (!is_repeated(answer, total_answers, n))
                {

                  for (int l = 0; l < n; l++)
                  {
                    if (answer[l] != -1)
                    {
                      if (l > 0 && l < n-1)
                        printf("+");
                      printf("%d", answer[l]);
                    }
                    else
                      break;
                  }
                  printf("\n");
                  total_answers[answers_counter++] = answer;
                }
              }
            }

          }
          // Como el array inicia seteado en 0, si no se guardo ninguna respusta
          // el primer valor es 0
          int not_empty = 0;
          for (int r = 0; r < n; r++)
          {
            if (total_answers[r] != 0)
              not_empty = 1;
          }
          if (!not_empty)
            printf("NADA\n");
          else 
          {
            for (int l = 0; l < n; l++)
              free(total_answers[l]);
          }
          free(numbers);
          free(total_answers);
          counter = 0;


        }
      }
      else
        buffer[i++] = c;
  }
  return 0;
}
