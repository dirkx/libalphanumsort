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
#include <stdio.h>

#include "../alphanumsort.h"

char *arr[] = { "aaa", "a", "aa", "foo3bar91p", "foo3bar91arse", "foo", "foo9", "foo32", "foo3", "foo12891", "baz", "foo12bar", "0010", "1", "109","11", "23", "9", "bar", "zz9", "foo1bar", "foo3bar91", "foo3bar9", "foo3bar2", "foo13","" };

int main(int a, char **b) {
	size_t elems = sizeof(arr)/sizeof(*arr);

	qsort(arr,elems,sizeof(*arr),&alphanumsort);

	for(int i = 0; i < elems; i++)
		printf("%3d: >%s<\n",i+1,arr[i]);
	return 0;
}
