#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/Headers/Basic.h"
#include "test.h"

static struct el_ut *head = NULL;
static void suite_add(struct el_ut *ut);

extern struct el_ut test1;
extern struct el_ut test2;
extern struct el_ut test3;
extern struct el_ut test4;

int main()
{
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   suite_add(&test1);
   suite_add(&test2);
   suite_add(&test3);
   suite_add(&test4);

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

static void suite_add(struct el_ut *ut)
{
	CU_pSuite pSuite = NULL;
	int	  i;

	if (head != NULL)
		ut->u_next = head;

	head = ut;

	/* add a suite to the registry */
	pSuite = CU_add_suite(ut->u_name, ut->u_init, ut->u_fini);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		exit(CU_get_error());
	}

	/* add the tests to the suite */
	for (i = 0; ut->u_case[i].us_name != NULL; i++)	{
		if (CU_add_test(pSuite, ut->u_case[i].us_name,
				ut->u_case[i].us_test) == NULL) {
			CU_cleanup_registry();
			exit(CU_get_error());
		}
	}
}

