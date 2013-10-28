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
  //  CU_ASSERT_EQUAL(1,1);
  //assert for int overflow int 2 147 483 647
  char str[10] = {'0','0','0','0','0','0','0','0','0','0'};
  printf("enter int\n");
  scanf("%s",str);

  int len = strlen(str);
  if(len > 10) CU_FAIL(input overflow!!);

  //check if input nothing or "0"
  int num_count = 0;//I can use "i",and not use "num_count" but work is wrong
  for(int i = 0; i < 11; i++){
    if(str[i] == '0') ++num_count;
    if(num_count == 10){
      CU_FAIL(nothing wasn`t input);
    }
  }

  char str_expected[10] = {'2','1','4','7','4','8','3','6','4','7'};
  CU_ASSERT_STRING_NOT_EQUAL(str,str_expected);
  /*it`s boundary value. at this moment we must understand our value more or less this value but user can input not int value or not number value*/

  //input must be a number
  bool done = 0;
  int counts = 0;
  char nums[11] = {'0','1','2','3','4','5','6','7','8','9',','};
  for(int i = 0; i < 10; i++){
    if(done) break;
    counts = 0;
    for (int j = 0; j < 11; j++){
      if(str[i] != nums[j]){
	++counts;
	if(counts == 10){
	  CU_FAIL(ERROR_INPUT input is not a number!!!!);
	  //out from loop because ^^
	  done = true;
	  break;//must return 1
	}
      }
      else{
	done = true;
	CU_PASS(input is a number);
	break;
      }
    }
  }
  
  //if double
  //  int iStr[11] = {0,0,0,0,0,0,0,0,0,0,0};
  bool ddouble = 0;
  int elmass_coma = 0;
  
  for(int i = 0; i < 11; i++){
    if(str[i] == ',' || str[i] == '.'){
      //CU_PASS(input is double it will be converted);
      elmass_coma = i;
      ddouble = 1;
      break;
    }
  }
  
  if(elmass_coma == 10) CU_FAIL(input double number more then integer);

  int input_num = 0;
  if(ddouble){
    //    for(int i = 0; i < elmass_coma; i++){
    //iStr[i] = str[i];
    //}
    input_num = atoi(str);
    printf("input double converted in int = %i\n", input_num);
    //if(elmass_coma < 11){
    //iStr[11] = 0;
    //CU_PASS(enter number less then length of integer);
    //break; must out
    //}
  }
  else{    //if integer
    //    CU_ASSERT_EQUAL(str[10], '0');
    int count_nums_nZ = 0;
    for(int i = 0; i < 10; i++){
      if(str[i] != 0) count_nums_nZ++;
    }
    
    CU_ASSERT_NOT_EQUAL(count_nums_nZ,11);
    if(count_nums_nZ == 10){
      int condition = 0;//2 147 483 647
      if(str[0] > '2') condition++;
      if(str[1] > '1') condition++;
      if(str[2] > '4') condition++;
      if(str[3] > '7') condition++;
      if(str[4] > '4') condition++;
      if(str[5] > '8') condition++;
      if(str[6] > '3') condition++;
      if(str[7] > '6') condition++;
      if(str[8] > '4') condition++;
      if(str[9] > '7') condition++;
      
      if(condition == 10) CU_FAIL(integer overflow!!);
    }
    else{
      CU_PASS(input integer less then 2147483647);
      //for(int i = 0; i < 11; i++){
      input_num = atoi(str);
      printf("input int = %i\n", input_num);
    }
    //}
  }
  //___________________________________________________________
  //**************************************************
  //___________________________________________________________

  /*  //number must be input
  for(int i = 0; i < 11; i++){
    CU_ASSERT_NOT_EQUAL(str[i],0);
    CU_FAIL(no number);
    CU_ASSERT_NOT_EQUAL(i,13);
    }*/

  /*  //number must be input
  for(int i = 0; i < 11; i++){
    CU_ASSERT_NOT_EQUAL(str[i],0);
    CU_FAIL(no number);
    CU_ASSERT_NOT_EQUAL(i,13);
  }

  static int count = 0;
  for(int i = 0; i < 11; i++){
    ++count;
    CU_ASSERT_NOT_EQUAL(i,13);
  }*/


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
