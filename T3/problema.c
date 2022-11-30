// problema.c - Implementacion solucion ciudades hermanas

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
  int length;
  int *a;
  int *b;
} Element;

int *slice(int low, int high, int *a)
{
  int *new = malloc((high-low)*sizeof(int));
  for (int i = low; i < high; i++)
  {
    new[i-low] = a[i];
  }
  return new;
}

int mediana(int la, int lb, int *a, int *b)
{
  /*
  for (int i = 0; i < la; i++)
  {
    printf("%d,", a[i]);
  }
  printf("\t");
  for (int i = 0; i < lb; i++)
  {
    printf("%d,", b[i]);
  }
  printf("\n");
  */

  int out = 0;
  if (la == 1)
    return a[0];
  else if (lb == 1)
    return b[0];
  int med1 = (int)floor((la+1)/2) - 1;
  int med2 = (int)floor((lb+1)/2) - 1;
  int m1 = a[med1];
  int m2 = b[med2];
  int *a_slice;
  int *b_slice;

  if (m1 == m2)
    return m1;
  else
  {
    if (m1 < m2)
    {
      // La media esta en la mitad de arriba
      a_slice = slice(med1+1, la, a);
      la = la - med1 -1;

      // La media esta en la mitad de abajo
      b_slice = slice(0, med2, b);
      lb = med2;
    }
    else if (m1 > m2)
    {
      // La media esta en la mitad de abajo 
      a_slice = slice(0, med1, a);
      la = med1;

      // La media esta en la mitad de arriba 
      b_slice = slice(med2+1, lb, b);
      lb = lb - med2 - 1;
    }
    out = mediana(la, lb, a_slice, b_slice);

    free(a_slice);
    free(b_slice);
  }
  return out;
}


int main(int argc, char *argv[])
{

  char c;

  char buffer[1024];
  int i = 0;

  int n = 0;
  int l = 0;
  int *a;
  int *b; 
  int counter = 0;
  int array_select = 0;

  Element *all_array;
  int counter_all_array = 0;

  while ((c = getc(stdin)) != EOF)
  {
    if (c == '\n')
    {
      buffer[i++] = '\0';
      if (n == 0)
      {
        n = atoi(buffer);
        all_array = malloc(n*sizeof(Element));
      }
      else if (l == 0)
      {
        l = atoi(buffer);
        all_array[counter_all_array].length = l;
        a = malloc(l*sizeof(int));
        b = malloc(l*sizeof(int));
      }
      else if (n != 0 && l != 0)
      {
        if (array_select == 0)
        {
          a[counter++] = atoi(buffer);
          all_array[counter_all_array].a = a;
          array_select = 1;
        }
        else
        {
          b[counter++] = atoi(buffer);
          all_array[counter_all_array++].b = b;
          array_select = 0;
          l = 0;
        }

        counter = 0;
      }
      buffer[0] = 0;
      i = 0;
    }
    if (c == ' ')
    {
      buffer[i++] = '\0';
      if (array_select == 0)
        a[counter++] = atoi(buffer);
      else
        b[counter++] = atoi(buffer);
      buffer[0] = 0;
      i = 0;
    }
    else
      buffer[i++] = c;
  }

  // if buffer not empty
  if (buffer[0] != 0)
    b[counter] = atoi(buffer);

  // Estan listos los arrays en el array all_array
  //
  printf("%d\n", n);
  for (int i = 0; i < n; i++)
  {
    int h = all_array[i].length;
    int *array_a = all_array[i].a;
    int *array_b = all_array[i].b;
    printf("%d\n", mediana(h, h, array_a, array_b));
  }
  return 0;
}
