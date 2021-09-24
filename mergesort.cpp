#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

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
    merge_sort(arr1, 0, num_elements1 - 1);

    fin >> num_elements2;
    int * arr2 = new int[num_elements2];
    for (int i = 0; i < num_elements2; i++)
    {
        fin >> arr2[i];
    }
    merge_sort(arr2, 0, num_elements2 - 1);

    fin >> num_elements3;
    int * arr3 = new int[num_elements3];
    for (int i = 0; i < num_elements3; i++)
    {
        fin >> arr3[i];
    }
    merge_sort(arr3, 0, num_elements3 - 1);

    fin >> num_elements4;
    int * arr4 = new int[num_elements4];
    for (int i = 0; i < num_elements4; i++)
    {
        fin >> arr4[i];
    }
    merge_sort(arr4, 0, num_elements4 - 1);

    fin >> num_elements5;
    int * arr5 = new int[num_elements5];
    for (int i = 0; i < num_elements5; i++)
    {
        fin >> arr5[i];
    }
    merge_sort(arr5, 0, num_elements5 - 1);

    fin >> num_elements6;
    int * arr6 = new int[num_elements6];
    for (int i = 0; i < num_elements6; i++)
    {
        fin >> arr6[i];
    }
    merge_sort(arr6, 0, num_elements6 - 1);

    fin >> num_elements7;
    int * arr7 = new int[num_elements7];
    for (int i = 0; i < num_elements7; i++)
    {
        fin >> arr7[i];
    }
    merge_sort(arr7, 0, num_elements7 - 1);

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
