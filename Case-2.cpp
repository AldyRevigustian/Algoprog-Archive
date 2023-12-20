#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int allRow()
{
  FILE *fp = fopen("file.csv", "r");
  int totalRows = 0;
  int dummy;
  while (fscanf(fp, "%*[^\n]%*c", &dummy) != EOF)
  {
    totalRows++;
  }

  fclose(fp);
  return totalRows - 1;
}

void showMenu()
{
  printf("What do you want to do?\n");
  printf("1. Display data\n");
  printf("2. Search Data\n");
  printf("3. Sort Data\n");
  printf("4. Export Data\n");
  printf("5. Exit\n");
  printf("Your choice: ");
}

void printArray(House arr[], int num)
{
  printf("%-28s%-15s%-15s%-10s%-10s%-15s%-15s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

  for (int i = 0; i < num; i++)
  {
    if (i == 0)
    {
      printf("%-28s%-15s%-15lld%-10d%-10d%-15d%-15s%-15s", arr[i].location, arr[i].city, arr[i].price, arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
    }
    else
    {
      printf("%-28s %-15s%-15lld%-10d%-10d%-15d%-15s%-15s", arr[i].location, arr[i].city, arr[i].price, arr[i].rooms, arr[i].bathroom, arr[i].carpark, arr[i].type, arr[i].furnish);
    }
  }
  printf("\n");
  printf("\n");
}

void swap(House *a, House *b)
{
  House t;
  memcpy(&t, a, sizeof(House));
  memcpy(a, b, sizeof(House));
  memcpy(b, &t, sizeof(House));
}

int partition(House array[], int low, int high)
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

void quickSort(House array[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void sortData(House array[], char direct[101], char column[101], int max)
{
  quickSort(array, 0, max - 1);
  printArray(array, 10);
}

void displayData(int num, int max)
{
  FILE *fp = fopen("file.csv", "r");
  int totalRows = 0;
  House house[num];

  fscanf(fp, "%*[^\n]\n");

  if (num > max)
  {
    num = max;
  }

  for (int i = 0; i < num; i++)
  {
    fscanf(fp, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%[^\n]", house[i].location, house[i].city, &house[i].price, &house[i].rooms, &house[i].bathroom, &house[i].carpark, house[i].type, house[i].furnish);
  }

  printArray(house, num);
  fclose(fp);
}

void clearConsole()
{
  while (getchar() != '\n')
    ;
  getchar();
  system("cls");
}

int main()
{
  int maxRow = allRow();
  int choice;

  do
  {
    showMenu();
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      int num = 0;
      printf("Number of rows: ");
      scanf("%d", &num);
      printf("\n");
      displayData(num, maxRow);

      clearConsole();
      break;
    }
    case 2:
    {
      int num = 0;
      break;
    }
    case 3:
    {
      // sortData(a);
      break;
    }
    case 4:
    {
      int num = 0;
      break;
    }
    case 5:
    {
      int num = 0;
      break;
    }

    default:
      printf("Invalid choice\n");
      break;
    }
  } while (choice != 5);

  return 0;
}
