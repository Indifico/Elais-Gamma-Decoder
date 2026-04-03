# Elias Gamma Decoder
### Programming Assignment 1 - COSC 1437
A simple project demonstrating the use of OOP structures, C++ project structure, and header including procedures.
<br></br>
### Installation

#### Unix Systems (macOS & Linux)

- Available on homebrew tap [Indifico/egdecoder](https://github.com/Indifico/homebrew-egdecoder)

- Source archive including CMake Presets & source code available in [Releases](https://github.com/Indifico/Elais-Gamma-Decoder/releases)

#### Windows

- egdecoder.exe available in [Releases](https://github.com/Indifico/Elais-Gamma-Decoder/releases)
<br></br>
### Usage

An example input file & output can be seen below. Lines are structured by symbol (character), where each following encoding represents the position at which that symbol appears in the final output message. Encodings are separated by spaces (or tabs, as discovered later). The program assumes the input is always valid, so unexpected behavior will occur if the format is not followed.

When the program is run, the terminal will wait for input. Input the file path and the result will print
<br></br>
### Examples
#### Input File Example:
*test/testCase0.txt*
```
A 1 010 00100 0001000 0001010
C 00110 00111
B 00101 0001001 
D 011 0001011 0001100  
```

#### Output Example:
```
Alphabet: 
Symbol: A, Frequency: 5
Positions: 0 1 3 7 9 
Number of bits to represent the positions: 23
Symbol: C, Frequency: 2
Positions: 5 6 
Number of bits to represent the positions: 10
Symbol: B, Frequency: 2
Positions: 4 8 
Number of bits to represent the positions: 12
Symbol: D, Frequency: 3
Positions: 2 10 11 
Number of bits to represent the positions: 17
Decoded message: AADABCCABADD
```
