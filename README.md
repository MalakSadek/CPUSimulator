# CPUSimulator
An Object-Oriented CPU Simulator implemented in C++ using the Factory pattern 🏭 💻 (2016)

The tool handles the following instructions:
* Write
* Read
* Halt
* Assign
* Add
* Jump
* Multiply
* Negate

The factory pattern is used where factories are defined for numbers, instructions, data addresses, memory, processor, and operands. Each instruction is created as a class with its own header file and 9 different text files containing sample instructions are included.

An example:
`ASS -5, $1`
`ASS 100, $2`
`MUL $1, $2, $3`
`WRITE $3`
`HALT`
