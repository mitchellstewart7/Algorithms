#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

void insertSort(int * array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > curr)
        {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = curr;
    }
}

int main()
{
    srand(time(NULL));

    clock_t time;

    for (int i = 1; i <= 10; i++)
    {
        int * arr = new int[5000 * i];
        for (int j = 0; j < (5000 * i); j++)
        {
            arr[j] = rand() % 10001;
        }
        time = clock();
        insertSort(arr, 5000 * i);
        time = clock() - time;
        cout << "n = " << (5000 * i) << "       " << (float)time/CLOCKS_PER_SEC << " seconds" << endl;
    }
}