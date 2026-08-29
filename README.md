# libalphanumsort
Tiny ANSI-C library to do alphanumeric sorting; e.g. sort D3, D10, D17 in that order (as opposed to pure lexical; where D10 comes before D3

Normally - when you would sort a list such as

	hal.D10.input.1
	hal.D1.input.1
	hal.D30.input.1
	hal.D30.input.11
	hal.D30.input.9

with a tool like strcmp() it would be sorted lexically - as per above; with D10 before D1 and the input.11 before input.9. This is often not quite what you want.

This replacement for strmcmp() that can be used with libc its qsort/heapsort/mergesort will sort above as:

	hal.D1.input.1
	hal.D10.input.1
	hal.D30.input.1
	hal.D30.input.9
	hal.D30.input.11

It will take numbers before alpha; and ignore leading 0. So, for example:

	foo.012
	foo.7
	foo.70
	33.foo
	03.foo
	

Is sorted as

	03.foo
	33.foo
	foo.8
	foo.012
	foo.70

