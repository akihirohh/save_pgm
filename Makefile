make: test_pgm.cpp
	g++ -o test_pgm test_pgm.cpp

c: test_pgm.c
	gcc -o test_pgm_c test_pgm.c
