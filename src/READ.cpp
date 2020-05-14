//
//  READ.cpp
//  OOPAssignment2
//
//  Created by Malak Sadek on 11/13/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#include "READ.hpp"
#include <regex>

READ::READ(DataAddressOperand* input1, std::string instr):instruction(instr),read(input1){}

void READ::runInstr() {
    std::string temp = "";
    int x = 0;
    std::cout << "Please enter a number: "<<std::endl;
    std::cin >> temp;
    
    //Validation that the input is a number and not a character, if it is a character, ask the user to enter the input again
    std::regex r ("^-?\\d+");

    while (!std::regex_match (temp,r)) {
        std::cout << "Only numbers are allowed, please try again: "<<std::endl;
        std::cin >> temp;
    }
    
    x = std::stoi(temp);
    read->setValue(x);
}

std::string READ::printInstr() {
    return instruction;
}
