# HackAssembler
An assembler that translates Hack assembly into bytecode for the Hack Computer (nand2tetris.org).

To compile: <br>
`g++ -o assembler assembler.cpp` <br>
_Note: cpp files are directly included, not linked._

To run: <br>
`./assembler Input.asm`

Output: a file `out.hack` containing bytecode executable on the Hack computer built with nand2tetris.
