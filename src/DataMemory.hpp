//
//  DataMemory.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//



#ifndef DataMemory_h
#define DataMemory_h

#include <stdio.h>
#include <iostream>
class DataMemory
{
private:
    static DataMemory* memPointer;  //To navigate across the memory
    int* Dmemory;
    DataMemory();
    
public:
    static DataMemory*  getmemPointer();
    static void createMemory();
    int& operator[](int index);
    void print();
    
};


#endif

