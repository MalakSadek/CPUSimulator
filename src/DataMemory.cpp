//
//  DataMemory.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "DataMemory.hpp"

DataMemory::DataMemory() {
    Dmemory = new int[1024];
    
    for (int i = 0; i < 1024; i++)
        Dmemory[i] = 0;
}

 DataMemory*  DataMemory::getmemPointer() {
    return memPointer;
}

 void DataMemory::createMemory() {
    memPointer = new DataMemory();
}

int& DataMemory::operator[](int index) {    //To return a certain data memory cell
    return Dmemory[index];
}

void DataMemory::print() {
        for (int i = 0; i < 1024; i++)
                if (Dmemory[i] != 0)
                    std::cout << "[Location " << i << ": Data: " << Dmemory[i] << "]"<<std::endl;
}
DataMemory* DataMemory::memPointer = NULL;
