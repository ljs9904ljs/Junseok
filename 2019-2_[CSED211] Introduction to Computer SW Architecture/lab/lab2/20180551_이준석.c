/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
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

/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~((~x)&(~y));
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int mask;
	mask = x >> 31;
	mask = mask << 31;
	mask = mask >> n;
	mask = mask << 1;
  return mask^(x>>n);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int mask = 0x1;
	int val;
	mask |= mask<<8;
	mask |= mask<<16;
	val = mask&x;
	val += mask&(x>>1);
	val += mask&(x>>2);
	val += mask&(x>>3);
	val += mask&(x>>4);
	val += mask&(x>>5);
	val += mask&(x>>6);
	val += mask&(x>>7);
	val += val>>16;
	val += val>>8;
	val &= 0xff;
	return val;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ((~x)+1);
}



/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
	int sum=x+y;
  int a=x>>31;
  int b=y>>31;
  int carry=sum>>31;
  return (!!(a^b))|(!(a^carry)&!(b^carry));
}


/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: OrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int _x = x>>31;
	int _y = y>>31;
	return !( ((!_x) & _y) | ( !(_x ^ _y) & (y+~x+1)>>31 ) );

}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	unsigned msb = uf >> 31;
	unsigned res;
	unsigned t;
	unsigned exp;
	t = (0xff << 23);
	exp = t & uf;
	if(exp == t && ((uf<<9) > 0x00000000) ){
		return uf;
	}
	res = uf ^ ( 0x80000000 );
	return res;
	
	
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	// 정수형을 실수형으로 바꿔야한다.
	// (-1)^s * M * 2^E
	// E = exp - bias
	int bk = x; // back up
	unsigned result = 0; //= x & (1<<31);
	//msb will be the sign bit with 31 times left shifted.
	int msb = x & (0x80000000);
	int exp = 0x7f;
	int qtx;
	int lastbit;
	int mask;
	int f,f1,f2,g,h,i,rr,q,lbx;
	if(x==0) return 0; 
	if(x == 0x80000000) {
		return 0xcf000000;
	}
	result = result | msb; // sign 비트 부분을 채운다. 이제 exp와 frac만 채우면 된다.
	if(msb) {
		bk = -x; // 절댓값으로 고려하자. 즉, 음수를 양수로 바꿔서 계산을 한다..
	}
	qtx = bk;
	while(qtx/=2) { // 1.xxxx * 2^E 형태로 나타내어 E의 값을 얻기 위함이다. 
		exp=exp+1;
	} // while문이 돌면서 exp의 값에 더해진 만큼이 바로 E이고 
	  // exp는 E+bias(0x7f)이므로 이렇게 바로 계산할 수 있다. 
	
	lastbit = exp-0x7f; // E의 값이자 1.XXXXXXX... * 2^E 에서 XXXX가 몇개인지 알려준다. 
	mask = (1<<lastbit) - 1;
	q = (mask & bk); // lastbit 아래의 bit들만을 본다.
	lbx = 23-lastbit;
	if(lastbit<=23) {
		//mantissa에 관한 내용이다.
		//24비트 보다 적게 남아있으면, 즉 23비트 안에 다 잘 들어가게 있으면 rounding없이 바로 더한다.
		result = result + (q<<lbx);
	} else {
		f = -lbx; 
		f1 = f-1;
		f2 = 1<<f1;
		g = q & (f2-1);
		h = q & (1<<(f));
		i = q & (f2);
		rr = q >> (f);
		//위는 rounding을 하기위한 3가지를 계산한 것들이다.
		//g : 처음으로 제거되는 비트의 하위 비트들의 OR값이다.
		//h : round to even을 위해서 1인지 0인지 확인한다. 
		//i : 처음으로 제거되는 비트이다. 
		rr = rr + (i && (g || h));	
		result |= rr; // rounding을 한 것을 frac 비트 부분을 더해준다.
	}
	
	// 마지막으로 exp를 더해준다.
	result += (exp<<23);
	return result;
	/*
	int sign;
	int exp;
	int frac;
	int bias;
	int e;
	int m;
	int cnt = 0;
	unsigned bk = x;
	int mask;
	int msb;
	int res;
	
	int a,b,c; // rounding을 하기 위함.
	int ru; // rounding up에 대한 flag
	m = x;
	
	
	if (x == 0){
		return 0;
	}
	
	
	sign = (x >> 31) & (1 << 31);
	msb = sign;
	bias = 127;
	
	//E의 값을 찾는다.
	while(1){
		bk /= 2;
		if(bk < 1){
			break;
		}
		cnt++;
	}
	
	// 이거 다시 생각해봐야한다. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	m = m << (32-cnt); // 이거 다시 생각해봐야한다. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	// 이거 다시 생각해봐야한다. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
	e = cnt;
	
	exp = e + bias;
	exp = exp << 23;
	
	// mantissa의 값을 찾는다.
	// 반올림을 고려해야 한다.
	
	a = m << 22;
	a = a & (1<<31);
	
	b = m << 23;
	b = b & (1<<31);
	
	c = m << 24;
	if(c>0){
		c = 1;
	}
	else{
		c = 0;
	}
	
	// 반올림 조건 검사
	if(b == 0){
		ru = 0;
	}
	else if((a == 0)&&(c == 0)){
		ru = 0;
	}
	else{
		ru = 1;
	}
	
	
	
	if(ru == 0){
		m = m >> 9;
		mask = msb >> 9;
		m = m^mask; // 0000 0000 0 그리고 23칸의 숫자들
	}
	else if(ru == 1){
		m = m >> 9;
		mask = msb >> 9;
		m = m^mask;	
		m += 1;
		mask = (1 << 31);
		mask = mask >> 8;
		mask = ~mask;
		m = m & mask;
	}
	
	//아래가 목표
	res = sign | exp | m;
	return res;
	*/
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  int exp = (uf >> 23) & 0xFF;
  // +- zero와 denormalized value, frac 비트 부분을 왼쪽으로 한 칸 이동시키면 된다. 
  if(exp == 0)
  {
    return (uf & 0x80000000) | (uf << 1);
  }
  // NaN, 그대로 반환한다.
  if(exp == 0xFF)
  {
    return uf;
  }
  // normalized value는 exp 비트 부분에 1을 더해주면 된다.
  uf = uf + (1 << 23);
  return uf;
}
