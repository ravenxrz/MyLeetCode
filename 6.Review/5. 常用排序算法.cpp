#include <bits/stdc++.h>
#include "data_generator.h"

using namespace std;

// 快速排序
int my_partition(vector<int> &data, int start, int end)
{
    int pivot = data[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (left < right && data[right] >= pivot) right--;
        data[left] = data[right];
        while (left < right && data[left] <= pivot) left++;
        data[right] = data[left];
    }
    data[left] = pivot;
    return left;
}

void quick_sort(vector<int> &data, int start, int end)
{
    if (start >= end) return;
    // partition
    int mid = my_partition(data, start, end);
    quick_sort(data, start, mid - 1);
    quick_sort(data, mid + 1, end);
}

// 归并排序
void merge(vector<int> &data, int s1, int e1, int s2, int e2)
{
    int len1 = e1 - s1 + 1;
    int len2 = e2 - s2 + 1;
    vector<int> aux_arr(len1 + len2, 0);
    
    // merge core
    int i = s1;
    int j = s2;
    int aux_idx = 0;
    while (i <= e1 && j <= e2) {
        if (data[i] <= data[j]) {
            aux_arr[aux_idx++] = data[i++];
        } else {
            aux_arr[aux_idx++] = data[j++];
        }
    }
    
    while (i <= e1) {
        aux_arr[aux_idx++] = data[i++];
    }
    while (j <= e2) {
        aux_arr[aux_idx++] = data[j++];
    }
    
    // copy back
    aux_idx = 0;
    // 实际上 s1-e1 应该和 s2-e2是连续的。
    for (i = s1; i <= e1; i++) {
        data[i] = aux_arr[aux_idx++];
    }
    for (i = s2; i <= e2; i++) {
        data[i] = aux_arr[aux_idx++];
    }
}

void merge_sort(vector<int> &data, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end) >> 1;
    merge_sort(data, start, mid);
    merge_sort(data, mid + 1, end);
    merge(data, start, mid, mid + 1, end);
}

// 冒泡排序
void bubble_sort(vector<int> &data)
{
    for (int i = 0; i < data.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // swap
                swapped = true;
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
        if (!swapped) break;
    }
}

// 选择排序
void select_sort(vector<int> &data)
{
    for (int i = 0; i < data.size() - 1; i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (data[i] > data[j]) {
                int tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
            }
        }
    }
}


int main()
{
    {
        vector<int> data = DataGenerator::generate(10, 1, 100);
        printData(data);
        quick_sort(data, 0, data.size() - 1);
        printData(data);
        cout << endl;
    }
    
    {
        vector<int> data = DataGenerator::generate(10, 1, 100);
        printData(data);
        merge_sort(data, 0, data.size() - 1);
        printData(data);
        cout << endl;
    }
    
    {
        vector<int> data = DataGenerator::generate(100, 1, 100);
        printData(data);
        bubble_sort(data);
        printData(data);
        cout << endl;
    }
    
    
    {
        vector<int> data = DataGenerator::generate(100, 1, 100);
        printData(data);
        select_sort(data);
        printData(data);
        cout << endl;
    }
    return 0;
}
