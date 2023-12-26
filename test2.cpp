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

enum SortingCriteria
{
  SORT_BY_PRICE_ASC,
  SORT_BY_PRICE_DESC,
  SORT_BY_LOCATION_ASC,
  SORT_BY_LOCATION_DESC,
  SORT_BY_CITY
};

int compare(void *context, const void *elem1, const void *elem2)
{
  const House *house1 = (const House *)elem1;
  const House *house2 = (const House *)elem2;

  enum SortingCriteria criterion = *(enum SortingCriteria *)context;

  switch (criterion)
  {
  case SORT_BY_PRICE_ASC:
    if (house1->price < house2->price)
      return -1;
    if (house1->price > house2->price)
      return 1;
    return 0;

  case SORT_BY_PRICE_DESC:
    if (house1->price > house2->price)
      return -1;
    if (house1->price < house2->price)
      return 1;
    return 0;

  case SORT_BY_LOCATION_ASC:
    return strcmp(house1->location, house2->location);

  case SORT_BY_LOCATION_DESC:
    // Sort in descending order based on location
    return -strcmp(house1->location, house2->location);

  case SORT_BY_CITY:
    return strcmp(house1->city, house2->city);

  default:
    // Invalid sorting criterion
    fprintf(stderr, "Invalid sorting criterion\n");
    exit(EXIT_FAILURE);
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

  House house[max];
  readData(house, max);

  int isExist = 0;

  for (int i = 0; i < max; i++)
  {
    if ((strcasecmp(col, "location") == 0 && strcmp(house[i].location, query) == 0) ||
        (strcasecmp(col, "city") == 0 && strcmp(house[i].city, query) == 0) ||
        (strcasecmp(col, "price") == 0 && house[i].price == atoll(query)) ||
        (strcasecmp(col, "rooms") == 0 && house[i].rooms == atoi(query)) ||
        (strcasecmp(col, "bathroom") == 0 && house[i].bathroom == atoi(query)) ||
        (strcasecmp(col, "carpark") == 0 && house[i].carpark == atoi(query)) ||
        (strcasecmp(col, "type") == 0 && strcmp(house[i].type, query) == 0) ||
        (strcasecmp(col, "furnish") == 0 && strcmp(house[i].furnish, query) == 0))
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
  char col[101];
  char direct[101];
  printf("Choose column: ");
  scanf("%s", col);
  printf("Sort ascending or descending? ");
  scanf("%s", direct);

  printf("%s", "Data found. Detail of data: \n");
  House house[max];
  readData(house, max);

  if (strcasecmp(direct, "ascending") == 0)
  {
    if (strcasecmp(col, "price") == 0)
    {
      enum SortingCriteria sortBy = SORT_BY_PRICE_ASC;
      qsort_s(house, max, sizeof(struct House), compare, &sortBy);
    }
    else if (strcasecmp(col, "location") == 0)
    {
      enum SortingCriteria sortBy = SORT_BY_LOCATION_ASC;
      qsort_s(house, max, sizeof(struct House), compare, &sortBy);
    }
    else if (strcasecmp(col, "city") == 0)
    {
      enum SortingCriteria sortBy = SORT_BY_CITY;
      qsort_s(house, max, sizeof(struct House), compare, &sortBy);
    }
  }
  else if (strcasecmp(direct, "descending") == 0)
  {
    if (strcasecmp(col, "price") == 0)
    {
      enum SortingCriteria sortBy = SORT_BY_PRICE_DESC;
      qsort_s(house, max, sizeof(struct House), compare, &sortBy);
    }
    else if (strcasecmp(col, "location") == 0)
    {
      enum SortingCriteria sortBy = SORT_BY_LOCATION_DESC;
      qsort_s(house, max, sizeof(struct House), compare, &sortBy);
    }
    else if (strcasecmp(col, "city") == 0)
    {
      enum SortingCriteria sortBy = SORT_BY_CITY;
      qsort_s(house, max, sizeof(struct House), compare, &sortBy);
    }
  }

  // enum SortingCriteria sortBy = SORT_BY_PRICE_DESC;

  // qsort_s(house, max, sizeof(struct House), compare, &sortBy);

  for (int i = 0; i < 10; ++i)
  {
    printf("%-28s%-15s%-15lld%-10d%-10d%-15d%-15s%-15s\n", house[i].location, house[i].city, house[i].price, house[i].rooms, house[i].bathroom, house[i].carpark, house[i].type, house[i].furnish);
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
