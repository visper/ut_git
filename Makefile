CUNIT_LIB=./CUnit-2.1-2/CUnit/Sources/.libs/
CUNIT_INC=CUnit-2.1-2
CUNIT_SRCS = 	test1.c \
		test2.c


test: $(CUNIT_SRCS) main.c
	gcc  -Wall -std=c99 -I $(CUNIT_INC) -g \
	-o test $(CUNIT_SRCS) main.c $(CUNIT_LIB)/libcunit.a

cov: $(CUNIT_SRCS) main.c
	gcc  -Wall -std=c99 -I $(CUNIT_INC) -g -fprofile-arcs -ftest-coverage \
	-o test_cov $(CUNIT_SRCS) main.c $(CUNIT_LIB)/libcunit.a

clean:
	rm -rf *.gcda  *.gcno  *.gcov  test_cov  test

run:
	./test

run_cov:
	./test_cov
