#include "CUnit/Headers/Basic.h"
#include "test.h"

int init_suite1(void)
{
	return 0;
}

int clean_suite1(void)
{
	return 0;
}

void testCase1(void)
{
	CU_ASSERT(0 == 0);
}

void testCase2(void)
{
	static int xxx = 6;

	if (xxx == 6) {
		CU_ASSERT(0 == 1);
	} else {
		CU_ASSERT(0 == 0);
	}
}

void testCase3(void)
{
	CU_ASSERT(5 == 5);
}

struct el_ut test1 = {
	.u_name = "test1",
	.u_init = init_suite1,
	.u_fini = clean_suite1,
	.u_case = {
		{ "case1", testCase1 },
		{ "case2", testCase2 },
		{ "case3", testCase3 },
		{ NULL, NULL }
	}
};

struct el_ut test2 = {
	.u_name = "test2",
	.u_init = init_suite1,
	.u_fini = clean_suite1,
	.u_case = {
		{ "case1", testCase1 },
		{ "case3", testCase2 },
		{ NULL, NULL }
	}
};
