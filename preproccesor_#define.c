#include <stdio.h>
#include <conio.h>
// #define # => preprocessor , define => preprocessor cammand 
// through the the #define we create macros / identifier
#define SUM(a,b) a##a+b  // ## concatinate  , SUM(a,b) => macros 

// #undef SUM(a,b)    it is use for undefined macros 
void main()
{
	printf("%d",SUM(3,5));
}
