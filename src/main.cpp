//
//  main.cpp
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//
#include <iostream>
#include "Simulator.hpp"
using namespace std;

int main()
{
    for (int i = 1; i < 10; i++) {  //Opens 9 different test files and executes them in a loop
        
        std::string s = "/Users/malaksadek/Desktop/OOPAssignment2/OOPAssignment2/InstructionSet"+to_string(i)+".txt";
        
        Simulator S (s);
        S.startSimulator();
        
        //DISPLAYING RESULTS
        cout << "Test #: " << i << endl;
        cout << "==============================" << endl;
        cout << "Instruction Set:" << endl;
        S.displayCode();
        cout << "==============================" << endl;
        cout << "Data Memory:" << endl;
        S.displayMemory();
        cout << "==============================" << endl;
    }
    return 0;
}

