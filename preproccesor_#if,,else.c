#include <stdio.h>
#include <conio.h>
#define PI 1
	
int main()
{
#ifdef PI								// if define
	#if PI==3	// if
		printf("PI value is 3");
	#elif PI==4	// else if
		printf("PI value is 4");
	#elif PI==5	// else if
		printf("PI value is 5");
	#else		// else
		printf("PI value is 3.14");
	#endif 		// end if 
#endif									// end if 

#ifndef PI								// if not define
	printf("PI not define ");
#endif									// end if 
}
