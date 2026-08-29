/* Copyright 2003, 20026 - Dirk-Willem van Gulik, All Rights Reserved

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdlib.h>
#include <ctype.h>

int alphanumsort(const void * A, const void * B) {
	char * a = *(char **)A; 
	char * b = *(char **)B; 

	while(1) {
		while(*a && *b && *a == *b && (!isdigit(*a))) {
			a++; b++;
		};

		// end of the string reached; tie
		if (*a == *b && *a == 0)
			return 0;

		// either of the two is at the end of the string
		// So the shorter one wins.
		if (!*a || !*b)
			return *b ? -1 : 1;

		// The letters differ (as opposed to looking at
		// a number); so compare these.
		//
		if (!isdigit(*a) && !isdigit(*b))
			return *a - *b;

		// Digits are lexially ordered before letters.
		//
		if (isdigit(*a))
			return -1;
		if (isdigit(*b))
			return 1;

		// We are at the start of a number; parse -all- of it
		// and then compare.
		//
		long long ia = strtoll(a, &a, 10);
		long long ib = strtoll(b, &b, 10);
		if (ia != ib)
			return ia - ib;

		// number is the same - so continue the comparison
	};
	return 0; // no reached.
}

