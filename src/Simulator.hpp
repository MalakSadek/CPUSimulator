//
//  Simulator.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//


#ifndef Simulator_h
#define Simulator_h

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "InstructionFactory.hpp"
#include "DataMemory.hpp"
#include "Processor.hpp"

class Simulator
{
private:
    std::ifstream instructionFile;
    Instruction** instructionMemory;
    int memIndex, PC;
public:
    Simulator(std::string filePath);
    void  startSimulator();
    void  displayMemory();
    void  displayCode();
    
};
#endif


