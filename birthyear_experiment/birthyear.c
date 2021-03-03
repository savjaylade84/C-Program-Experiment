#include<stdio.h>

#define input(x,y)printf(x);scanf("%i",&y);

int main(){

 int age = input("Enter Age:",age);
 int current_year = input("Enter Current Year:",current_year);

 int birth_year = current_year - age;
 printf("Your Birth Year Is :%i",birth_year - 1);
 
}