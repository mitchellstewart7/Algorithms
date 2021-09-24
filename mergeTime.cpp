#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void merge(int * arr, int left, int middle, int right)
{
    int * arrLeft = new int[middle - left + 1];
    int * arrRight = new int[right - middle];

    for (int i = 0; i < (middle - left + 1); i++)
    {
        arrLeft[i] = arr[left + i];
    }
    for (int j = 0; j < (right - middle); j++)
    {
        arrRight[j] = arr[middle + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < (middle - left + 1) && j < (right - middle))
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrLeft[i];
            i++;
        }
        else
        {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    while (i < (middle - left + 1))
    {
        arr[k] = arrLeft[i];
        i++;
        k++;
    }
    while (j < (right - middle))
    {
        arr[k] = arrRight[j];
        j++;
        k++;
    }

    delete [] arrLeft;
    delete [] arrRight;
}

void merge_sort(int * arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    else
    {
        int middle = left + ((right - left) / 2);
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    srand(time(NULL));

    clock_t time;

    for (int i = 1; i <= 10; i++)
    {
        int * arr = new int[100000 * i];
        for (int j = 0; j < (100000 * i); j++)
        {
            arr[j] = rand() % 10001;
        }
        time = clock();
        merge_sort(arr, 0, 100000 * i);
        time = clock() - time;
        cout << "n = " << (100000 * i) << "       " << (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    }
}