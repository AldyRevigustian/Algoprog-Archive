#include <stdio.h>
#include <string.h>

int main()
{
  char kata[101];

  scanf("%[^\n]", kata);
  for (int i = strlen(kata) - 1; i >= 0; i--)
  {
    if (kata[i] >= 'a' && kata[i] <= 'z')
    {
      kata[i] -= 32;
    }
    else if (kata[i] >= 'A' && kata[i] <= 'Z')
    {
      kata[i] += 32;
    }

    printf("%c", kata[i]);
  }
  printf("\n");
  return 0;
}