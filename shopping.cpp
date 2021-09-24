#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

//function that computes maximum of two integer inputs
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

//function that gives the maximum value of an 0-1 knapsack with maximum weight w_capacity
//this function is also seen in knapsack.cpp
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
    return table[n][w_capacity];
}

//function returning an array with the given family member's item numbers in it
//items in the returned array are in increasing order by item number
int * print_chosen(int n, int w_capacity, int * val, int * weight)
{
    int * reversed_arr = new int[10];

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

    int curr_value = table[n][w_capacity];
    int w = w_capacity;
    int num_chosen = 0; //track number of items chosen so we know where to put each item in the array
    for (int i = n; i > 0 && curr_value > 0; i--)
    {
        if (curr_value != table[i - 1][w])
        {
            num_chosen++;
            curr_value = curr_value - val[i - 1];
            w = w - weight[i - 1];
        }
    }
    curr_value = table[n][w_capacity];
    w = w_capacity;
    for (int i = n; i > 0 && curr_value > 0; i--)
    {
        if (curr_value != table[i - 1][w])
        {
            reversed_arr[num_chosen - 1] = i; //put item in the array so that it will be in increasing order (larger numbers are found first so it puts them at the back)
            curr_value = curr_value - val[i - 1];
            w = w - weight[i - 1];
            num_chosen--;
        }
    }

    return reversed_arr;
}

int main()
{
    ifstream fin; //for reading in from shopping.txt
    fin.open("shopping.txt");

    int num_test_cases = 0;
    fin >> num_test_cases;

    for (int i = 0; i < num_test_cases; i++)
    {
        cout << endl;
        cout << "Test Case " << i + 1 << endl;
        int total_price = 0;
        int num_items = 0;
        fin >> num_items;
        int * prices = new int[num_items];
        int * weights = new int[num_items];
        for (int j = 0; j < num_items; j++)
        {
            fin >> prices[j];
            fin >> weights[j];
        }
        int family_size = 0;
        fin >> family_size;
        int** family_items = new int*[family_size]; //2-D array to store each family member's chosen items
        for (int k = 0; k < family_size; k++)
        {
            int weight_capacity = 0;
            fin >> weight_capacity;
            total_price += dp_knapsack(num_items, weight_capacity, prices, weights); //add price of the current family member to the total price
            family_items[k] = print_chosen(num_items, weight_capacity, prices, weights); //add array of chosen values to the family items 2-D array
        }
        cout << "Total Price " << total_price << endl;
        for (int a = 0; a < family_size; a++) //print out chosen items
        {
            cout << a + 1 << ": ";
            for (int b = 0; b < 10; b++)
            {
                if (family_items[a][b] != 0)
                {
                    cout << family_items[a][b] << " ";
                }
            }
            cout << endl;
        }
    }
    
}