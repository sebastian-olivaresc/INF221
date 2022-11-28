#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
  return a > b? a : b;
}

int lcs_matrix(int **c, int a[], int b[], int i, int j, int *puentes, int *counter, int *max_puentes)
{

  if (i == 0 || j == 0)
    return 0;
  if (a[i] == b[j])
  {
    c[i][j] = lcs_matrix(c, a, b, i-1, j-1, puentes, counter, max_puentes) + 1;
    if (c[i][j] > *max_puentes)
      *max_puentes = c[i][j];
  }
  else
    c[i][j] = max(lcs_matrix(c, a, b, i-1, j, puentes, counter, max_puentes), lcs_matrix(c, a, b, i, j-1, puentes, counter, max_puentes));
  return c[i][j];

}

int main(int argc, char *argv[])
{

  char c;

  char buffer[1024];
  int i = 0;

  int n = 0;
  int *a;
  int *b; 
  int counter = 1;

  while ((c = getc(stdin)) != EOF)
  {
    if (c == '\n')
    {
      buffer[i++] = '\0';
      if (n == 0)
      {
        n = atoi(buffer);
        a = malloc((n+1)*sizeof(int));
        b = malloc((n+1)*sizeof(int));
      }
      else
      {
        if (counter < n+1)
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


  int **matrix = malloc((n+1)*sizeof(int *));
  for (int i = 0; i < n+1; i++)
  {
    matrix[i] = malloc((n+1)*sizeof(int));
  }


  int puentes[n];
  int max_puentes = 0;
  int index_puentes= 0;

  for (int i = 0; i < n+1; i++)
  {
    for (int j = 0; j < n+1; j++)
      lcs_matrix(matrix, a, b, i, j, puentes, &index_puentes, &max_puentes);
  }

  printf("puentes:");
  for (int j = 0; j < max_puentes; j++)
  {
    printf("%d,", puentes[j]);
  }
  printf("\n");

  for (int i = 0; i < n+1; i++)

  {
    for (int j = 0; j < n+1; j++)
    {
      printf("%d,", matrix[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i <=n ; i++)
    free(matrix[i]);
  free(matrix);

  free(a);
  free(b);
  return 0;
}
