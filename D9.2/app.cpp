//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 04.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(vector<string> &list, int left, int mid, int right) {
    vector<string> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            temp.push_back(list[i]);
            ++i;
        } else {
            temp.push_back(list[j]);
            ++j;
        }
    }

    while (i <= mid) {
        temp.push_back(list[i]);
        ++i;
    }

    while (j <= right) {
        temp.push_back(list[j]);
        ++j;
    }

    for (int i = left; i <= right; ++i)
        list[i] = temp[i - left];
}

void mergeSort(vector<string> &list, int left, int right) {
   if(left < right) {
      int mid = left + ((right - left) / 2);
      mergeSort(list, left, mid);
      mergeSort(list, mid + 1, right);
      merge(list, left, mid, right);
   }
}

int main() {
    vector<string> input {
        "Орлов",
        "Картошин",
        "Семенов",
        "Главный",
        "Гордый",
        "Смелый",
        "Комаров",
        "Антонов",
    };

    mergeSort(input, 0, input.size() - 1);

    for (auto i : input) {
        printf("%s\n", i.c_str());
    }

    return 0;
}

