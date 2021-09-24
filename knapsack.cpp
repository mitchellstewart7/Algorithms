#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <time.h>
#include <chrono> //deals with clocking runtimes

using namespace std;
using namespace std::chrono;

//function to compute the max of two input integers
int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

//recursive function that gives the maximum value
//of an 0-1 knapsack with maximum weight w_capacity
int recursive_knapsack(int n, int w_capacity, int * val, int * weight)
{
    if (n == 0 || w_capacity == 0)
    {
        return 0;
    }
    
    if (weight[n - 1] <= w_capacity)
    {
        return max(val[n - 1] + recursive_knapsack(n - 1, w_capacity - weight[n - 1], val, weight),
        recursive_knapsack(n - 1, w_capacity, val, weight));
    }
    else
    {
        return recursive_knapsack(n - 1, w_capacity, val, weight);
    }
}

//dynamic programming function that calculates the same maximum value obtained
//in recursive_knapsack
int dp_knapsack(int n, int w_capacity, int * val, int * weight)
{

    int table[n + 1][w_capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w_capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (weight[i - 1] <= j)
            {
                table[i][j] = max(val[i - 1] + table[i - 1][j - weight[i - 1]], table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[n][w_capacity]; //maximum value is in bottom right of 2-D array
}


int main()
{
    srand(time(NULL)); //seed random number generator

    clock_t time;

    int w = 100; //constant w value

    for (int i = 10; i <= 50; i += 5) //N values vary from 10 to 50
    {
        int * val_array = new int[i];
        int * weight_array = new int[i];
        for (int j = 0; j < i; j++)
        {
            val_array[j] = rand() % 100; //create random values from 0 to 99
            weight_array[j] = (rand() % 35) + 5; //create random weight from 5 to 39
        }
        cout << "N = " << i << "  " << "W = 100" << "  ";
        auto start = high_resolution_clock::now(); //start the clock
        int recur_max = recursive_knapsack(i, w, val_array, weight_array);
        auto stop = high_resolution_clock::now(); //stop the clock
        auto recur_time = duration_cast<nanoseconds>(stop - start);
        cout << "Recursive Time = " << (float)recur_time.count() / 1000000 << " milliseconds  ";

        start = high_resolution_clock::now(); //start the clock
        int dp_max = dp_knapsack(i, w, val_array, weight_array);
        stop = high_resolution_clock::now(); //stop the clock
        auto dp_time = duration_cast<nanoseconds>(stop - start);
        cout << "Dynamic Programming Time = " << (float)dp_time.count() / 1000000 << " milliseconds  ";

        cout << "Recursive Max = " << recur_max << "  Dynamic Programming = " << dp_max << endl;

        delete [] val_array; //free memory
        delete [] weight_array;
    }

    cout << endl;
    cout << endl;

    int n_const = 25; //constant N value

    for (int j = 30; j <= 240; j += 30) //W values vary from 30 to 240
    {
        int * val_array = new int[n_const];
        int * weight_array = new int[n_const];
        for (int k = 0; k < n_const; k++)
        {
            val_array[k] = rand() % 100;
            weight_array[k] = (rand() % 35) + 5;
        }
        cout << "N = 25" << "  " << "W = " << j << "  ";
        auto start = high_resolution_clock::now();
        int recur_max = recursive_knapsack(n_const, j, val_array, weight_array);
        auto stop = high_resolution_clock::now();
        auto recur_time = duration_cast<nanoseconds>(stop - start);
        cout << "Recursive Time = " << (float)recur_time.count() / 1000000 << " milliseconds  ";

        start = high_resolution_clock::now();
        int dp_max = dp_knapsack(n_const, j, val_array, weight_array);
        stop = high_resolution_clock::now();
        auto dp_time = duration_cast<nanoseconds>(stop - start);
        cout << "Dynamic Programming Time = " << (float)dp_time.count() / 1000000 << " milliseconds  ";

        cout << "Recursive Max = " << recur_max << "  Dynamic Programming = " << dp_max << endl;

        delete [] val_array; //free memory
        delete [] weight_array;
    }
}

