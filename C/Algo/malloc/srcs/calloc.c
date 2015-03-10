
#include <unistd.h>
#include "malloc.h"

void	*calloc(int number, int size)
{
  void	*addr;
  char	*str;
  int	i;

  i = 0;
  addr = malloc(number * size);
  if (addr == NULL)
    return (addr);
  str = addr;
  while (i < number * size)
    {
      str[i] = 0;
      i++;
    }
  return (addr);
}
