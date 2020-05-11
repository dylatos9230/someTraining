//
//  main.cpp
//  algorithms
//
//  Created by 黄煦 on 4/25/20.
//  Copyright © 2020 黄煦. All rights reserved.
//

#include <iostream>
#include "bubble.cpp"
#include "reserve.cpp"
#include "fib.cpp"
#include "head.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    // int array[10] = {10,9,8,7,6,5,4,3,2,1};
    // reserve(array,0,9);
    // for (size_t i = 0; i < 10; i++)
    // {
    //     std::cout<< array[i]<<",";
    // }
    int fibNum;
    cout<<"please number :";
    cin>>fibNum;

    FibMap fibMap;
    cout<<"fib("<<fibNum<<"):"<<fib(fibNum)<<endl;
    cout<<"fib2("<<fibNum<<"):"<<fib2(fibNum,fibMap)<<endl;
    
    return 0;
}
