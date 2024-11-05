#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortRecursive(int arr[], int n)
{

  if (n <= 1)
  {
    return;
  }

  insertionSortRecursive(arr, n - 1);

  int last = arr[n - 1];
  int j = n - 2;

  while (j >= 0 && arr[j] > last)
  {
    arr[j + 1] = arr[j];
    j--;
  }
  arr[j + 1] = last;
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  clock_t start = clock();

  insertionSortRecursive(arr, n);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  printArray(arr, n);
  printf("Time taken for recursive insertion sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}