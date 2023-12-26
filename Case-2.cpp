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

void swap(House *a, House *b)
{
  House temp = *a;
  *a = *b;
  *b = temp;
}

int partition(House arr[], int low, int high, int type, char col[50], int order)
{
  if (type == 0)
  {
    char pivot[50];
    if (strcasecmp(col, "location") == 0)
    {
      strcpy(pivot, arr[high].location);

      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 0)
        {
          if (strcasecmp(arr[j].location, pivot) > 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (strcasecmp(arr[j].location, pivot) < 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
    else if (strcasecmp(col, "city") == 0)
    {
      strcpy(pivot, arr[high].city);
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 0)
        {
          if (strcasecmp(arr[j].city, pivot) > 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (strcasecmp(arr[j].city, pivot) < 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
    else if (strcasecmp(col, "type") == 0)
    {
      strcpy(pivot, arr[high].type);
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 0)
        {
          if (strcasecmp(arr[j].type, pivot) > 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (strcasecmp(arr[j].type, pivot) < 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
    else if (strcasecmp(col, "furnish") == 0)
    {
      strcpy(pivot, arr[high].furnish);
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 0)
        {
          if (strcasecmp(arr[j].furnish, pivot) > 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (strcasecmp(arr[j].furnish, pivot) < 0)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
  }
  else
  {
    int pivot;
    if (strcasecmp(col, "price") == 0)
    {
      int pivot = arr[high].price;
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 1)
        {
          if (arr[j].price < pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (arr[j].price > pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
    if (strcasecmp(col, "rooms") == 0)
    {
      int pivot = arr[high].rooms;
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 1)
        {
          if (arr[j].rooms < pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (arr[j].rooms > pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
    if (strcasecmp(col, "bathroom") == 0)
    {
      int pivot = arr[high].bathroom;
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 1)
        {
          if (arr[j].bathroom < pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {
          if (arr[j].bathroom > pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
    if (strcasecmp(col, "carpark") == 0)
    {
      int pivot = arr[high].carpark;
      int i = (low - 1);
      for (int j = low; j <= high - 1; j++)
      {
        if (order == 1)
        {

          if (arr[j].carpark < pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
        else
        {

          if (arr[j].carpark > pivot)
          {
            i++;
            swap(&arr[i], &arr[j]);
          }
        }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
    }
  }
  return 0;
}

void quickSort(House arr[], int low, int high, int type, char col[], int order)
{
  if (low < high)
  {
    int pi = partition(arr, low, high, type, col, order);

    quickSort(arr, low, pi - 1, type, col, order);
    quickSort(arr, pi + 1, high, type, col, order);
  }
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

int countAll()
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

void clearConsole()
{
  while (getchar() != '\n')
    ;
  getchar();
  system("cls");
}

void readData(House house[], int num)
{
  FILE *fp = fopen("file.csv", "r");
  fscanf(fp, "%*[^\n]\n");

  for (int i = 0; i < num; i++)
  {
    fscanf(fp, " %[^,],%[^,],%lld,%d,%d,%d,%[^,],%[^\n]", house[i].location, house[i].city, &house[i].price, &house[i].rooms, &house[i].bathroom, &house[i].carpark, house[i].type, house[i].furnish);
  }
  fclose(fp);
}

void displayData()
{
  int max = countAll();
  int num = 0;
  printf("Number of rows: ");
  scanf("%d", &num);
  printf("\n");

  if (num > max)
  {
    num = max;
  }

  House house[num];
  readData(house, num);
  printf("%-28s%-15s%-15s%-10s%-10s%-15s%-15s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

  for (int i = 0; i < num; i++)
  {
    printf("%-28s%-15s%-15lld%-10d%-10d%-15d%-15s%-15s\n", house[i].location, house[i].city, house[i].price, house[i].rooms, house[i].bathroom, house[i].carpark, house[i].type, house[i].furnish);
  }

  printf("\n");
  clearConsole();
}

void searchData()
{
  int max = countAll();
  char col[101];
  char query[101];
  printf("Choose column: ");
  scanf("%s", col);
  printf("What data do you want to find? ");
  scanf("%s", query);
  printf("\n");

  House house[max];
  readData(house, max);

  int isExist = 0;

  for (int i = 0; i < max; i++)
  {
    if ((strcasecmp(col, "location") == 0 && strcasecmp(house[i].location, query) == 0) ||
        (strcasecmp(col, "city") == 0 && strcasecmp(house[i].city, query) == 0) ||
        (strcasecmp(col, "price") == 0 && house[i].price == atoll(query)) ||
        (strcasecmp(col, "rooms") == 0 && house[i].rooms == atoi(query)) ||
        (strcasecmp(col, "bathroom") == 0 && house[i].bathroom == atoi(query)) ||
        (strcasecmp(col, "carpark") == 0 && house[i].carpark == atoi(query)) ||
        (strcasecmp(col, "type") == 0 && strcasecmp(house[i].type, query) == 0) ||
        (strcasecmp(col, "furnish") == 0 && strcasecmp(house[i].furnish, query) == 0))
    {
      if (!isExist)
      {
        printf("%s", "Data found. Detail of data: \n");
        printf("%-28s%-15s%-15s%-10s%-10s%-15s%-15s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
        isExist = 1;
      }

      printf("%-28s%-15s%-15lld%-10d%-10d%-15d%-15s%-15s\n", house[i].location, house[i].city, house[i].price, house[i].rooms, house[i].bathroom, house[i].carpark, house[i].type, house[i].furnish);
    }
  }

  if (!isExist)
  {
    printf("No matching data found.\n");
  }

  printf("\n");
  clearConsole();
}

void sortBy()
{
  int max = countAll();
  int isError = 0;
  char col[101];
  char direct[101];
  House house[max];
  readData(house, max);

  printf("Choose column: ");
  scanf("%s", col);
  printf("Sort ascending or descending? ");
  scanf("%s", direct);

  printf("\n");

  int type = 1;
  if (strcasecmp(col, "location") == 0 || strcasecmp(col, "city") == 0 || strcasecmp(col, "type") == 0 || strcasecmp(col, "furnish") == 0)
  {
    type = 0;
  }
  else if (strcasecmp(col, "price") == 0 || strcasecmp(col, "rooms") == 0 || strcasecmp(col, "bathroom") == 0 || strcasecmp(col, "carpark") == 0)
  {
    type = 1;
  }
  else
  {
    isError = 1;
  }

  int order = 0;
  if (strcasecmp(direct, "asc") == 0)
  {
    order = 1;
  }
  else if (strcasecmp(direct, "desc") == 0)
  {
    order = 0;
  }
  else
  {
    isError = 1;
  }

  if (isError == 0)
  {
    printf("%s", "Data found. Detail of data: \n");
    printf("%-28s%-15s%-15s%-10s%-10s%-15s%-15s%-15s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");

    quickSort(house, 0, max - 1, type, col, order);

    for (int i = 0; i < 10; ++i)
    {
      printf("%-28s%-15s%-15lld%-10d%-10d%-15d%-15s%-15s\n", house[i].location, house[i].city, house[i].price, house[i].rooms, house[i].bathroom, house[i].carpark, house[i].type, house[i].furnish);
    }
  }
  else
  {
    printf("No matching data found.\n");
  }

  printf("\n");
  clearConsole();
}

int main()
{
  int choice;

  do
  {
    showMenu();
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      displayData();
      break;
    }
    case 2:
    {
      searchData();
      break;
    }
    case 3:
    {
      sortBy();
      break;
    }
    case 4:
    {
      break;
    }
    case 5:
    {
      break;
    }

    default:
      printf("Invalid choice\n");
      break;
    }
  } while (choice != 5);

  return 0;
}
