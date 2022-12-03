// problema.c - Implementacion solucion medianas de arrays ordenados

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Estruc que contiene los arrays
typedef struct 
{
  int length;
  int *a;
  int *b;
} Element;

int mediana(int l, int *a, int *b)
{
  int out = 0;

  // La mediana para arrays de largo 2 seria el promedio de los datos centrales
  // juntando y ordenandolos corresponderian al mayor de la parte izquierda y el
  // menor de la parte derecha
  int med = (int)floor((l+1)/2);

  int m1 = a[med-1];
  int m2 = b[med-1];

  // Si las medias son iguales ese es el resultado
  if (m1 == m2)
    return m1;
  else
  {
    // m1<mediana..mediana>m2
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
    // mediana>m1...m2<mediana
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

  // Este while guarda los datos en all_array
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
