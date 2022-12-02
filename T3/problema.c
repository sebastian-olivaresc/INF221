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

int mediana(int l, int *a, int *b)
{
  /*
  for (int i = 0; i < l; i++)
  {
    printf("%d,", a[i]);
  }
  printf("\t");
  for (int i = 0; i < l; i++)
  {
    printf("%d,", b[i]);
  }
  printf("\n");
  */
  int out = 0;

  if (l == 2)
  {
    float max = (a[0] > b[0])? a[0] : b[0];
    float min = (a[1] < b[1])? a[1] : b[1];

    return floor((max+min)/2);
  }
  int med = (int)floor((l+1)/2);

  float m1;
  float m2;

  if (l % 2 == 0)
  {
    m1 = ((float)a[med-1] + (float)a[med]) / 2;
    m2 = ((float)b[med-1] + (float)b[med]) / 2;
  }
  else
  {
    m1 = a[med-1];
    m2 = b[med-1];
  }

  if (m1 == m2)
    return m1;
  else
  {
    // a[m1<mediana] b[mediana>m2]
    if (m1 < m2)
    {
      if (l % 2 == 0)
      {
        l = med;
        out = mediana(l, a+med, b);
      }
      else
      {
        l = med;
        out = mediana(l, a+med-1, b);
      }
    }
    // a[mediana>m1] b[m2<mediana]
    else 
    {
      if (l % 2 == 0)
      {
        l = med;
        out =mediana(l, a, b+med);
      }
      else
      {
        l = med;
        out = mediana(l, a, b+med-1);
      }
    }
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
    printf("%d\n", mediana(h, array_a, array_b));
    free(array_a);
    free(array_b);
  }
  free(all_array);

  return 0;
}
