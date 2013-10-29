#include "CUnit/Headers/Basic.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

//#ifndef MYBOOLEAN_H
//#define MYBOOLEAN_H

#define false 0
#define true 1
typedef int bool;

int foo(void)
{
  return 0;
}

void input_int(void)//t1
{
  //assert for int overflow int 2 147 483 647
  char str[] = {'0','0','0','0','0','0','0','0','0','0'};
  printf("enter int\n");
  scanf("%s",str);

  int len = strlen(str);
  if(len > 10) CU_FAIL("input overflow!!");

  if(str[0] == '-') CU_FAIL("signed number");

  //check if input nothing or "0"
  int num_count = 0;
  int in_zero = ((sizeof(str))/(sizeof(str[0]))) - 1;
  for(int i = 0; i < ((sizeof(str))/(sizeof(str[0]))); i++){
    if(str[i] == '0') ++num_count;
    if(num_count == in_zero){
      CU_FAIL("nothing wasn`t input");
    }
  }

  //input must be a number
  bool done = 0;
  int counts = 0;
  char nums[] = {'0','1','2','3','4','5','6','7','8','9',','};
  for(int i = 0; i < ((sizeof(str))/(sizeof(str[0]))); i++){
    if(done) break;
    counts = 0;
    for (int j = 0; j < ((sizeof(nums))/(sizeof(nums[0]))); j++){
      if(str[i] != nums[j]){
	++counts;
	if(counts == len){
	  CU_FAIL("ERROR_INPUT input is not a number!!!!");
	  //out from loop because ^^
	  done = true;
	  break;//must return 1
	}
      }
      else{
	done = true;
	CU_PASS("input is a number");
	break;
      }
    }
  }
  
  //if double
  bool ddouble = 0;
  int elmass_coma = 0;
  
  for(int i = 0; i < ((sizeof(str))/(sizeof(str[0]))); i++){
    if(str[i] == ',' || str[i] == '.'){
      //this line not printed
      CU_PASS("input is double it will be converted");
      elmass_coma = i;
      ddouble = 1;
      break;
    }
  }
  
  if(elmass_coma == 10) CU_FAIL("input double number more then integer");

  int input_num = 0;
  if(ddouble){
    input_num = atoi(str);
    printf("input double converted in int = %i\n", input_num);
  }
  else{    //if integer
    if(len == 10){
      for(int i = 0; i < len; i++){
	if(str[0] > '2'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[1] > '1'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[2] > '4'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[3] > '7'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[4] > '4'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[5] > '8'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[6] > '3'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[7] > '6'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[8] > '4'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
	if(str[9] > '7'){
	  CU_FAIL("int type is overflow!");
	  break;
	}
      }//END FOR
      //if loop not break then input boundary value
      input_num = atoi(str);
      printf("input int = %i\n", input_num);
    }
    else{
      CU_PASS("input integer less then 2147483647");
      input_num = atoi(str);
      printf("input int = %i\n", input_num);
    }
  }
}

void t2(void)
{
  float fNum = 2.0;
  CU_ASSERT(fNum = 2);
}

void t3(void)
{
  int num = 3;
  CU_ASSERT(num == 3);
  CU_ASSERT_NOT_EQUAL(num,5);

}

struct el_ut test3 = {
        .u_name = "test3",
        .u_init = foo,
        .u_fini = foo,
        .u_case = {
                { "input_int", input_int },
                { "t2", t2 },
                { "t3", t3 },
                { NULL, NULL }
        }
};

struct el_ut test4 = {
        .u_name = "test4",
        .u_init = foo,
        .u_fini = foo,
        .u_case = {
                { "input_int", input_int },
                { "t2", t3 },
                { NULL, NULL }
        }
};
