#include <iostream>
#include <cstdlib>
#include <fstream>

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

void print_array(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    ifstream fin;
    fin.open("data.txt");
    int num_elements1 = 0;
    int num_elements2 = 0;
    int num_elements3 = 0;
    int num_elements4 = 0;
    int num_elements5 = 0;
    int num_elements6 = 0;
    int num_elements7 = 0;

    fin >> num_elements1;
    int * arr1 = new int[num_elements1];
    for (int i = 0; i < num_elements1; i++)
    {
        fin >> arr1[i];
    }
    insertSort(arr1, num_elements1);

    fin >> num_elements2;
    int * arr2 = new int[num_elements2];
    for (int i = 0; i < num_elements2; i++)
    {
        fin >> arr2[i];
    }
    insertSort(arr2, num_elements2);

    fin >> num_elements3;
    int * arr3 = new int[num_elements3];
    for (int i = 0; i < num_elements3; i++)
    {
        fin >> arr3[i];
    }
    insertSort(arr3, num_elements3);

    fin >> num_elements4;
    int * arr4 = new int[num_elements4];
    for (int i = 0; i < num_elements4; i++)
    {
        fin >> arr4[i];
    }
    insertSort(arr4, num_elements4);

    fin >> num_elements5;
    int * arr5 = new int[num_elements5];
    for (int i = 0; i < num_elements5; i++)
    {
        fin >> arr5[i];
    }
    insertSort(arr5, num_elements5);

    fin >> num_elements6;
    int * arr6 = new int[num_elements6];
    for (int i = 0; i < num_elements6; i++)
    {
        fin >> arr6[i];
    }
    insertSort(arr6, num_elements6);

    fin >> num_elements7;
    int * arr7 = new int[num_elements7];
    for (int i = 0; i < num_elements7; i++)
    {
        fin >> arr7[i];
    }
    insertSort(arr7, num_elements7);

    print_array(arr1, num_elements1);
    print_array(arr2, num_elements2);
    print_array(arr3, num_elements3);
    print_array(arr4, num_elements4);
    print_array(arr5, num_elements5);
    print_array(arr6, num_elements6);
    print_array(arr7, num_elements7);

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    delete [] arr6;
    delete [] arr7;
}