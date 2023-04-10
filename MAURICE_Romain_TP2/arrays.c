#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int palindrome_rec(char str[], int lo, int hi) {

  if (lo > hi) {
    return 1;
  } 

  if (str[lo] != str[hi]) {
    return 0;
  } 
  else {
    return palindrome_rec(str, lo+1, hi-1);
  }
}

int palindrome(char str[]){
  return (palindrome_rec(str, 0, strlen(str)-1));
}


void increasing_sequence_rec(int n){
  if (n==0){
    return;
  }
  increasing_sequence_rec(n-1);
  printf("%d ", n);
}

void decreasing_sequence_rec(int n){
  if (n==0){
    return;
  }
  printf("%d ", n);
  decreasing_sequence_rec(n-1);
}


int count(int t[], int lo, int hi, int elt){
  if (lo > hi){
    return 0;
  }
  else if (t[lo] == elt){
    return 1 + count(t,lo+1,hi,elt);
  }
  else{
    return count(t,lo+1,hi,elt);
  }
}

int max_count(int t[], int lo, int hi){
  /*si le 1 est en plus grand nombre que les autres*/
  /*si le 2 est en plus grand nombre que les autres*/
  if (lo > hi){
    return 0;
  }

  if (lo != 0){
    if (count(t,lo,hi,t[lo]) > count(t,lo,hi,t[lo-1])){
      return count(t,lo,hi,t[lo]);
    }
  }
  else{
    return count(t,lo,hi,t[lo-1]);
  }

  return max_count(t,lo+1,hi);
}


int sum_digits_iter(int n){
  int resultat = 0;
  while (n > 0) {
    resultat = resultat + n % 10;
      n /= 10;
  }
  return resultat;
  /*modulo 10 permet de récupérer le chiffre a droite de notre nombre (sans les virgules) et
  n/10 permet de réduire d'une puissance de 10 notre nombre, avec les itérations
  le modulo nous sortira chaque chiffre de notre nombre de base*/
}

int sum_digits_rec(int n){
  if (n == 0) {
    return 0;
  }
  return (n % 10) + sum_digits_rec(n / 10); 
}


int digit_sum_digits_iter(int n){
  while(n>10){
    n = sum_digits_iter(n);
  }
  return n;
}

int digit_sum_digits_rec(int n){
  int resultat = sum_digits_rec(n);
  if(resultat<10){
    return resultat;
  }
  else{
    return digit_sum_digits_rec(resultat);
  }
}


int longest_incr_iter(int t[], int lo, int hi) {
  int taille_max = 1;
  int taille = 1;
  int i;
  for (i = lo+1; i < hi; i++) {
    if (t[i] > t[i-1]) {
      taille++;
    } else {
      taille_max = taille;
      taille = 1;
    }
  }
  return taille_max;
}