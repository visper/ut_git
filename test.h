#ifndef _test_h_
#define _test_h_

struct el_ut {
	struct el_ut *u_next;
	const char   *u_name;
	int         (*u_init)(void);
	int         (*u_fini)(void);
	struct {
		const char *us_name;
		void      (*us_test)(void);
	} u_case[];
};

#endif
