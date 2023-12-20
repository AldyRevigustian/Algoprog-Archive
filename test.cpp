#include <stdio.h>
#include <string.h>

struct House
{
  char location[101];
  char city[101];
  long long price;
  int rooms;
  int bathroom;
  int carpark;
  char type[101];
  char furnish[101];
};

void swap(struct House *a, struct House *b)
{
  struct House t;
  memcpy(&t, a, sizeof(struct House));
  memcpy(a, b, sizeof(struct House));
  memcpy(b, &t, sizeof(struct House));
}

int partition(struct House array[], int low, int high)
{
  char pivot[101];
  strcpy(pivot, array[high].location);

  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (strcmp(array[j].location, pivot) <= 0)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(struct House array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main()
{
  struct House houses[] = {
      {"Location3", "CityC", 300000, 3, 2, 1, "TypeC", "FurnishC"},
      {"Location1", "CityA", 100000, 2, 1, 0, "TypeA", "FurnishA"},
      {"Location2", "CityB", 200000, 4, 3, 2, "TypeB", "FurnishB"}};

  int n = sizeof(houses) / sizeof(houses[0]);

  printf("Original array:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%s ", houses[i].location);
  }
  printf("\n");

  quickSort(houses, 0, n - 1);

  printf("Sorted array:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%s ", houses[i].location);
  }
  printf("\n");

  return 0;
}
