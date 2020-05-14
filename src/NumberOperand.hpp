//
//  NumberOperand.h
//  OOPASS2
//
//  Created by Malak Sadek on 11/10/17.
//  Copyright © 2017 Malak Sadek. All rights reserved.
//

#ifndef NumberOperand_hpp
#define NumberOperand_hpp

#include "Operand.h"
#include <stdio.h>
class NumberOperand : public Operand
{
private:
    int value;
public:
    NumberOperand(int v);
    int getValue() const;
    
};
#endif

