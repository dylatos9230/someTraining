//
//  bubble.cpp
//  algorithms
//
//  Created by 黄煦 on 4/25/20.
//  Copyright © 2020 黄煦. All rights reserved.
//

#include <stdio.h>

void swap(int & before,int & after){
    int tmp;
    tmp = after;
    after = before;
    before = tmp;
}

void bubble(int * array, int n){
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i<n-1; i++) {
            if (array[i]>array[i+1]) {
                swap(array[i], array[i+1]);
                isSorted = false;
            }
        }
    }
};
