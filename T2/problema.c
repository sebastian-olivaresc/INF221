// problema.c - Implementacion solucion ciudades hermanas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
  return a > b? a : b;
}

int lcs(int *X, int *Y, int m, int n ) 
{ 
  if (m == 0 || n == 0) 
    return 0; 
  if (X[m-1] == Y[n-1]) 
    return 1 + lcs(X, Y, m-1, n-1); 
  else
    return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 

int lcs_matrix(int **c, int a[], int b[], int n, int i, int j, int *puentes, int counter, int *max_puentes)
{

  if (i == 0 || j == 0)
    return 0;
  if (a[i] == b[j])
  {

    c[i][j] = lcs_matrix(c, a, b, n, i-1, j-1, puentes, counter+1, max_puentes) + 1;
    if (c[i][j] > *max_puentes)
    {
      puentes[counter] = a[i];
      *max_puentes = c[i][j];
    }
  }
  else
    c[i][j] = max(lcs_matrix(c, a, b, n, i-1, j, puentes, counter, max_puentes), lcs_matrix(c, a, b, n, i, j-1, puentes, counter, max_puentes));
  return c[i][j];

}

int *distance(int n, int a[], int b[])
{
  int counter = 0;
  int *out = malloc(n*sizeof(int));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      if (a[i] == b[j])
      {
        out[counter++] = j - i;
      }
  }
  return out;
}

void bridges(int start, int n, int a[], int b[])
{
  int counter = 0;
  int array[n];
  memset(array, 0, n*sizeof(int));
  int j = 0;

  for (int i = start; j < n;)
  {
    if (a[i] == b[j++])
    {
      array[i] = 1;
      i++;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d,", array[i]);
  printf("\n");
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

  int *a_to_b = distance(n, a, b);

  printf("%d\n", lcs(a, b, n, n )); 

  int **matrix = malloc((n+1)*sizeof(int *));
  for (int i = 0; i < n+1; i++)
  {
    matrix[i] = malloc((n+1)*sizeof(int));
  }


  int puentes[n];
  int max_puentes = 0;
  lcs_matrix(matrix, a, b, n, n, n, puentes, 0, &max_puentes);

    for (int j = 0; j < n - 1; j++)
    {
      printf("%d,", puentes[j]);
    }
    printf("\n");
  /*&
  for (int i = 0; i < n+1; i++)
  {
    for (int j = 0; j < n+1; j++)
    {
      matrix[i][j] = lcs_matrix(matrix, a, b, i, j);
    }
  }
  */
  for (int i = 0; i < n+1; i++)
  {
    for (int j = 0; j < n+1; j++)
    {
      printf("%d,", matrix[i][j]);
    }
    printf("\n");
  }

  /* Execute algorithm here
   *
   *
   *
   *
   */


  free(a_to_b);
  free(a);
  free(b);
  return 0;
}
