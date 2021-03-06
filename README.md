# Linear-System-Solver
- This problem finds a solution for linear system (only if it exists)\
  by performing Gauss-Jordan elimination using elementary matrix operations

## Input:
- A matrix of coefficients and a vector of constants
- Example)\
  Vector<3> constants({0, 9, -4});\
  SquareMatrix<3> coefficients({{\
      {1,  1,  3},\
      {2,  3, -1},\
      {3, -2,  3}\
  }});

* This input represents these equations:\
   x +  y + 3z =  0\
  2x + 3y -  z =  9\
  3x - 2y + 3z = -4

## Output:
- Solution of this system in sequence (for instance, 1 2 -1 for the example given above)

## Limits:
- This program assumes that given linear system has exactly one solution
  In cases where number of solution is infinite or zero is not handled properly

## Compiler
- I used gcc version 8.1.0 x86_64 posix to build and run this program.
- Build command: g++ -std=c++17 ./source/*.cpp -Iinclude -o ./linear_system.exe
- Run command: ./Linear-System-Solver.exe
