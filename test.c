/* problema1.c - Problema de dar cambio
 *
 * Author: Sebastian Olivares Carrasco
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
  char c;
  while ((c = getc(stdin)) != EOF)
    printf("%c", c);
  return 0;
}
