#include <iostream>

using namespace std;
void swap(int* x, int* y);
void heapify(int arr[], int n, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[l])
        largest = r;

    if (largest != i) {

        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

int print(int arr[], int n)
{
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << endl;
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void swap(int* x, int* y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int arr[] = { 4, 10, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    print(arr, n);

    return 0;
}
