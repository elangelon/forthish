# forthish
experimental forth like interpreters
experimenting with some tiny versions of interpreters that behave like forth.  currently looking at s2 by chris curl and ss by sandor schneider.  i mostly make changes to their code to get them to work on a mac using gcc.

Many thanks to Sandor Schneider who gave STABLE to public domain.

Stable (STAck Bytecode Language & Engine) is an extreme minimal but useful stack oriented virtual machine, currently written in C (200 lines of extensively commented C code. The original comes with 47 lines of C code). The machine language consists only of printable letters which make it simple hackable with an editor. The goal of this engine is to be human hackable, simple and fast. So there are no complicated address calculations (for branch and jump addresses) and an easy to use instruction set. (43 instructions, 26 registers, 26 user defineable functions)

To avoid addresses to variables (registers) and functions, names are predefined. So instead of given the address for a function there is an ASCII opcode for that. Functions are upper case letters from A to Z which leads to 26 user defineable functions, registers are named from a to z (lower letter) which leads to 26 registers.

Simple down counter

with an editor write a;[#." "1-#] into counter.txt, then
$ ./stable counter.txt 10
=> 10 9 8 7 6 5 4 3 2 1 
