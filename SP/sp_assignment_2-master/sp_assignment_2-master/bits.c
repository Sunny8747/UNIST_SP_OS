/* 
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */



/* 
 * bitXor - XOR operation of x and y at bit level using only <~, &> 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	int Andxy = x & y;
	int Notx = ~x;
	int Noty = ~y;
	int Norxy = Notx & Noty;
	int NotAndxy = ~Andxy;
	int NotNorxy = ~Norxy;
	return (NotAndxy & NotNorxy);
	
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	int var1 = 1;
	int Shiftedvar1 = (var1 << 31);
	return ~Shiftedvar1;
}
/* 
 * isNotEqual - return 1 if x != y, and 0 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	int Xorxy = x ^ y;
	return !!Xorxy;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10 
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
	int EightTimen = n << 3;
	int SetPosition = (255 << EightTimen);
	int Emptyx = x & ~SetPosition;
	int Positionc = c << EightTimen;
	return (Emptyx + Positionc);
}

/* 
 * fitsBits - returns 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int MinusOne = ~0;
	int Shiftedx = x >> (n + MinusOne);
	int PlusOne = Shiftedx + 1;//key point if x is minus then it become 0 if x is plus then thereis no corrupt plusing one
	int ReShift = PlusOne >> 1;
	return !ReShift;
}

/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */

int rotateLeft(int x, int n) {
	int Frontx = x << n;
	int Minusn = ~n + 1;
	int MinusOne = ~0;
	int ShiftMinusOne = MinusOne << n;
	int NotShiftMinus = ~ShiftMinusOne;
	int Shiftn = 32 + Minusn;
	int BackShiftedx = x >> Shiftn;
	int Backx = NotShiftMinus & BackShiftedx;
	return Frontx + Backx;
}

/*
 * isPower2 - returns 1 if x is a power of 2, and else 0 
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	int CheckMinus = (x >> 31);//if minus then it return 1
	int MinusOne = ~0;
	int CheckZero = !x;
	int xMinusOne = x + MinusOne;
	int xAndxMinusOne = x & xMinusOne;
	int AndCheckMinus = (xAndxMinusOne | CheckMinus) | CheckZero;
	return !AndCheckMinus;
}

/* 
 * rempwr2 - Compute x%(2^n), which is remainder for x divided by (2^n) for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

int rempwr2(int x, int n) {
	int FindSign = x & 0x80000000; //return 1 when -, 0 when +
	int MinusOne = ~0;
	int Minusn = 1 + ~n;
	int Shiftn = 31 + Minusn;
	int ShiftSign = FindSign >> Shiftn;
	int ShiftMinusOne = MinusOne << n;
	int FindRemaind = (~ShiftMinusOne) & x;
	int AddingSign = ShiftSign | FindRemaind;
	int RemaindZero = !FindRemaind + MinusOne;//0 -> 0 remain exist then 11111111
	int CheckZero = AddingSign & RemaindZero;
	//int Exception = (!FindRemaind) & (!n) & (!!FindSign);//- , remain 0, n = 0
	return CheckZero; // error if remaind 0 and - sign So using Remaindzero
}

/* 
 * conditional - Returns y if x is not 0, else z same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int conditional(int x, int y, int z) {
	int MinusOne = ~0;
	int Notx = !x;
	int Checkingy = MinusOne + Notx; //X is 1 then return 111111
	int AndCheckingy = y & Checkingy;
	int Checkingz = MinusOne + (!Notx);
	int AndCheckingz = z & Checkingz;
	return AndCheckingy + AndCheckingz;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's, else 0
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

int bitParity(int x) {
	//TODO
}

/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	//TODO
}

/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

int logicalNeg(int x) {
	int Shiftx = x >> 31;
	int ShiftxPlusOne = Shiftx + 1;
	int NotxPlusOne = ~x + 1;
	int NotxShiftPlusOne = (NotxPlusOne >> 31) + 1;
	int AndShift = ShiftxPlusOne & NotxShiftPlusOne;
	return AndShift;
}

/* 
 * bitAnd - AND operation of x and y at bit level using only <~, |>
 *	Example : bitAnd(12, 25) = (0000 1100) & (0001 1001) = 0000 1000 = 8 
 *	Legal ops : ~ |
 *	Max ops : 8
 *	Rating : 1
 */
int bitAnd(int x, int y) {
	int OrNotxy = ~x | ~y;
	return ~OrNotxy;
}

/* logical_OR - implement the || operator
 *	Examples : logical_OR(1, 2) = 1, logical_OR(0, 0) = 0
 *	Legal ops : ~ & ^ | ! >> << 
 *	Max ops : 10
 *	Rating : 2
 */
int logical_OR(int x, int y) {
	int Orab = x | y;
	return !!Orab;
}

/* concatenate - bitwise concatenate two input x, y
 *  You can assume that x, y is consist of 8 bits, that is 0 <= x,y <= 255
 *	Examples : concatenate(2, 3) = (0000 0010) * (0000 0011) = (0000 0010 0000 0011) = 515
 *	Legal ops : ~ & | >> << + 
 *	Max ops : 10
 *	Rating : 2
 */
int concatenate(int x, int y) {
	int Shiftedx = x << 8;
	return (Shiftedx + y);
}

/* 
 * isMult4 - return 1 if n is multiple of 4, else 0
 *   You can assume that 1 < n
 *   Examples: isMult4(1024) = 1, isMult4(1025) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: N/A
 */
int isMult4(int x) {
	int Shiftedx = ((x << 30) >> 30);
	return !Shiftedx;
}
