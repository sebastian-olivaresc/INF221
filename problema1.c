/* problema1.c - Problema de dar cambio
 *
 * Author: Sebastian Olivares Carrasco
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Dado un n, el dinero total, y las denominaciones D[], retorna
// la minima cantidad de monedas que dan n.
int b_force_monedas(int dinero, int D[], int n_denom)
{
  // Se disminuye para recorrer el array
  n_denom -= 1;

  int total_dinero = dinero;
  // Para checkear todas las opciones 
  int n_denom_check = n_denom;
  int minima = 0;
  int j = 0;
  //int buffer[100];
  
  while (n_denom_check >= 0)
  {
    // dinero y n_denom se usan para revisar una iteracion 
    // siendo una iteracion las permutaciones de n_denom para abajo
    n_denom = n_denom_check;
    while (dinero > 0)
    {
      if (D[n_denom] > dinero)
      {
        n_denom--;
      }
      else
      {
        dinero -= D[n_denom];
        //buffer[j++] = D[n_denom];
        j++;
      }
    }
    if (minima > j || minima == 0)
      minima = j;

    /* Para printear las distintas permutaciones
    for (int i = 0; i < j; i++)
      printf("%d,", buffer[i]);
    printf("\n");
    memset(buffer, 0, 100*sizeof(int));
    */

    // Se reinician los valores para siguientes iteraciones 
    j = 0;
    dinero = total_dinero;
    n_denom_check--;
  }

  return minima;
}

int main (int argc, char *argv[])
{
  char c;
  char buffer[1024] = {0};
  int i = 0;
  int counter = 0;

  int dinero = 0;
  int n_denom = 0;
  int *denominaciones;

  // Convierte en int  y guarda en array numbers
  while ((c = getc(stdin)) != EOF)
  {
      if (c == '\n')
      {
        buffer[i++] = '\0';
        if (counter == 0)
          dinero = atoi(buffer);
        if (counter == 1)
        {
          n_denom = atoi(buffer);
          denominaciones = malloc(n_denom*sizeof(int));
        }
        if (counter > 1)
          denominaciones[counter - 2] = atoi(buffer);

        counter++;
        buffer[0] = 0;
        i = 0;
      }
      else
        buffer[i++] = c;
  }
  
  free(denominaciones);
  printf("%d\n", b_force_monedas(dinero, denominaciones, n_denom));
  return 0;
}
