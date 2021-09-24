#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct activity
{
    int start_time;
    int finish_time;
    int number;
};

void merge(struct activity * arr, int left, int middle, int right)
{
    activity * arrLeft = new activity[middle - left + 1];
    activity * arrRight = new activity[right - middle];

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
        if (arrLeft[i].start_time <= arrRight[j].start_time)
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

void merge_sort(activity * arr, int left, int right)
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

void find_activites(int num_activities, ifstream & fin)
{
    int max_activitites = 0;
    int * chosen_activities = new int[10];
    int index = 0;
    struct activity * activities = new activity[num_activities];
    for (int i = 0; i < num_activities; i++)
    {
        fin >> activities[i].number;
        fin >> activities[i].start_time;
        fin >> activities[i].finish_time;
    }
    merge_sort(activities, 0, num_activities - 1);
    chosen_activities[index] = activities[num_activities - 1].number;
    max_activitites++;
    index++;
    int j = num_activities - 1;
    for (int i = num_activities - 2; i >= 0; i--)
    {
        if (activities[i].finish_time <= activities[j].start_time)
        {
            chosen_activities[index] = activities[i].number;
            index++;
            j = i;
            max_activitites++;
        } 
    }
    cout << "Maximum number of activities = " << max_activitites << endl;
    for (int k = max_activitites - 1; k >= 0; k--)
    {
        cout << " " << chosen_activities[k];
    }
    cout << endl;
}

int main()
{
    ifstream fin;
    fin.open("act.txt");

    cout << "Set 1" << endl;
    int num_act1 = 0;
    fin >> num_act1;
    find_activites(num_act1, fin);
    cout << endl;

    cout << "Set 2" << endl;
    int num_act2 = 0;
    fin >> num_act2;
    find_activites(num_act2, fin);
    cout << endl;

    cout << "Set 3" << endl;
    int num_act3 = 0;
    fin >> num_act3;
    find_activites(num_act3, fin);
    cout << endl;
}