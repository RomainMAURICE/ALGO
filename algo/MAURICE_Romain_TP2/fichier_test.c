#include <stdio.h>
#include "arrays.c"

int main(int argc, char constargv[])
{

    if(palindrome("superepus") == 1){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(palindrome("") == 1){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }
    if(palindrome("bonjour") == 0){
      printf("réussite du test 3 \n");
    }else{
      printf("echec du test 3 \n");
      return 0;
    }

printf("\n");
/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/

    int tab[]={1,1,2,3};

    if(count(tab, 0, 4, 1) == 2){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(count(tab, 0, 4, 4) != 1){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }

    if(max_count(tab, 0, 4) == 2){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }

printf("\n");
/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


    if(sum_digits_iter(123) == 6){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(sum_digits_iter(5410) == 10){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }
    if(sum_digits_iter(1) == 1){
      printf("réussite du test 3 \n");
    }else{
      printf("echec du test 3 \n");
      return 0;
    }

printf("\n");
/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


    if(sum_digits_rec(123) == 6){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(sum_digits_rec(5410) == 10){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }
    if(sum_digits_rec(1) == 1){
      printf("réussite du test 3 \n");
    }else{
      printf("echec du test 3 \n");
      return 0;
    }

printf("\n");
/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


    if(digit_sum_digits_iter(123) == 6){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(digit_sum_digits_iter(54102) == 3){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }
    if(digit_sum_digits_iter(1) == 1){
      printf("réussite du test 3 \n");
    }else{
      printf("echec du test 3 \n");
      return 0;
    }

printf("\n");
/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


    if(digit_sum_digits_rec(123) == 6){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(digit_sum_digits_rec(54102) == 3){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }
    if(digit_sum_digits_rec(1) == 1){
      printf("réussite du test 3 \n");
    }else{
      printf("echec du test 3 \n");
      return 0;
    }

printf("\n");
/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/

    int tab2[]={1,3,5,1,6};
    int tab3[]={1,3,5,6};
    int tab4[]={1,8,5,1,6};


    if(longest_incr_iter(tab2, 0, 5) == 3){
      printf("réussite du test 1 \n");
    }else{
      printf("echec du test 1 \n");
      return 0;
    }
    if(longest_incr_iter(tab3, 0, 5) == 4){
      printf("réussite du test 2 \n");
    }else{
      printf("echec du test 2 \n");
      return 0;
    }
    if(longest_incr_iter(tab4, 0, 5) == 1){
      printf("réussite du test 3 \n");
    }else{
      printf("echec du test 3 \n");
      return 0;
    }


  return 1;
}