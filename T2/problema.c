// problema.c - Implementacion solucion ciudades hermanas

#include <stdio.h>
#include <stdlib.h>

int can_build(int a, int built[])
{
  if (b(a - 1) <= a-1)
    return 1
  e

  /*
    3 2 1
    1 3 2

    3 2 1 4
    1 3 4 2
    */
}

int main(int argc, char *argv[])
{

  if (argc = 0)
    return 1;

  char c;
  char *filename = argv[1];

  char buffer[1024];
  int i = 0;

  int n = 0;
  int *a;
  int *b; 
  int counter = 0;

  while ((c = getc(stdin)) != EOF)
  {
    if (c == '\n')
    {
      buffer[i++] = '\0';
      if (n == 0)
      {
        n = atoi(buffer);
        a = malloc(n*sizeof(int));
        b = malloc(n*sizeof(int));
      }
      else
      {
        if (counter < n)
        {
          a[counter++] = atoi(buffer);
        }
        else
        {
          b[counter - n] = atoi(buffer);
          counter++;
        }
      }

      buffer[0] = 0;
      i = 0;
    }
    else
      buffer[i++] = c;
  }

  // if buffer not empty
  if (buffer[0] != 0)
    b[counter] = atoi(buffer);

  /* Execute algorithm here
   *
   *
   *
   *
   */


  free(a);
  free(b);
  return 0;
}
