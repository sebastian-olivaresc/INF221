/* problema2.c - Problema backtracking recursivo de sumas 
 *
 * Author: Sebastian Olivares Carrasco
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* 
 * t: numero a sumar
 * numbers_i: index de array numbers
 * numbers[]: array de numeros para conformar la suma
 * answer[]: array de numeros que forman la suma
 * answer_i: index de array answer
 */
int backtracking_suma(int t, int n, int numbers_i, int numbers[], int answer[], int answer_i)
{
  // Se puede hacer la suma
  if (t == 0)
  {
    answer[answer_i] = -1;
    return 0;
  }
  else if (t - numbers[numbers_i] >= 0)
  {
    answer[answer_i] = numbers[numbers_i];
    backtracking_suma(t-numbers[numbers_i], n, numbers_i+1, numbers, answer, answer_i+1);
  }
  else
  {
    // Se salta el caso en que la suma se pase
    if (numbers_i < n)
      backtracking_suma(t, n, numbers_i+1, numbers, answer, answer_i);
    else
      return 1;
  }
  return 1;
}

// Checkea si la respuesta ya se dio
int is_repeated(int answer[], int *total_answers[], int n)
{
  int result = 0;
  int j;
  for (int i = 0; i < n; i++)
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
  return result;
}

int main (int argc, char *argv[])
{
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
          if (t == 0 && n == 0)
            break;
          printf("Suma de %d:\n", t);
          total_answers= malloc(n*sizeof(int *));
          int answers_counter = 0;

          int result = 0;
          for (int i = 0; i < n; i++)
          {
            answer = malloc(n*sizeof(int));
            result = backtracking_suma(t, n, i, numbers, answer, 0);

            // Se checkea que el resultado no este repetido y se imprime
            if (!is_repeated(answer, total_answers, answers_counter))
            {
              if (result == 0)
              {
                for (int j = 0; j < n-1; j++)
                {
                  if (answer[j] == -1)
                    break;
                  if (j > 0) 
                    printf("+");
                  printf("%d", answer[j]);
                }
                total_answers[answers_counter++] = answer;
                printf("\n");
              }
              else
              {
                answer[0] = -2;
                total_answers[answers_counter++] = answer;
              }
            }
          }
          if (total_answers[i][0] == -2)
            printf("NADA\n");
          free(numbers);
          for (int l = 0; l < n; l++)
            free(total_answers[l]);
          free(total_answers);
          counter = 0;
      }
    }
      else
        buffer[i++] = c;
  }

  return 0;
}
