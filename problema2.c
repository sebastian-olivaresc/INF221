/* problema2.c - Problema backtracking recursivo de sumas 
 *
 * Author: Sebastian Olivares Carrasco
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int backtracking_suma(int t, int n, int numbers[])
{
  int result = 0;
  if (t == 0)
    return 0;
  if (t - numbers[0] >= 0)
  {
    t = numbers[0] + backtracking_suma(t - numbers[0], n-1, numbers);
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

        if (c == '\n')
        {
          /*
          for (int i = 0; i < n; i++)
            printf("%d,", numbers[i]);
          printf("\n");
          */
          for (int i = 0; i < n; i++)
            printf("%d",  
          free(numbers);
          counter = 0;
        }
      }

      else
        buffer[i++] = c;
  }

  return 0;
}
