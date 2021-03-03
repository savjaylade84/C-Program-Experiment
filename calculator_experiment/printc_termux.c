

//This project is for creating interactive
//terminal calculator
//@author:john jayson b. de leon
//@email:savjaylade.gmail.com

//header that needed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//----------------------------------------

//prototype functions

//BASIC ARITHMETIC OPERATION
int Addition(int num1,int num2);
int Subtraction(int num1,int num2);
int Divide(int num1,int num2);
int Multiply(int num1, int num2);

//UTILITY FUNCTION
int selection(int answer);
int getNum();
void title();

typedef char* string; 

//macros

//divide the sections 
#define console_dash print("\n-------------------------------\n")

//my printing format
#define print(string) printf(string);
#define prints(string,input) printf(string,input);

// i make it more readable 
#define read(holder) scanf("%i",holder);
#define readline(holder) scanf("%s",holder);
#define isNegative(num) (num < 0) ? 0 : 1

// this will change the foreground text
// in the terminal 
#define start_cyan print("\e[5;36m")
#define start_green print("\e[5;32m")
#define start_magenta print("\e[5;35m")
#define start_yellow print("\e[5;33m")
#define start_blue print("\e[5;34m")
#define color_end print("\e[0m")

//----------------------------------------

//----------------------------------------
int main(){

      int answer = 0;

    
     title();
     while(0){
     
      console_dash
        start_green
      	  print("Select Command:")
      	color_end

      //Selection option
      console_dash 
      	start_cyan
		  printf("%s%s%s%s%s%s",
		  "[1]: Addition\n",
		  "[2]: Subtraction\n",
		  "[3]: Divide\n",
		  "[4]: Multiply\n",
		  "[5]: Exit\n",
		  "[Enter]:");
      	  read(&answer)
      	color_end
        
        if(answer == 5) exit(EXIT_SUCCESS);
        
      console_dash
      	prints("\e[5;35m[Answer]\e[0m : %i" ,
      		  (char)selection(answer))

      //this will help the program if the user
      //want to get another computational
      //basic processing
      char ans;
      console_dash
      start_yellow
      	print("Do you want to Continue [Y/N] :")
      color_end
      readline(&ans)
      
      if(ans == 'n'|| ans == 'N') exit(EXIT_SUCCESS);
        
      }
      
     return EXIT_SUCCESS;

}


////       UTILITY FUNCTION			////

void title(){
    
      console_dash
      	start_blue
      		print("-:Welcome To Terminal Calculator:-")
      	color_end

      	const string date = __DATE__;
      	const string time = __TIME__;
      	
      console_dash
      	start_blue
      		printf("Date: %s : %s",date,time);
      	color_end
}

//give the correspond function
//and return the answer
int selection(int answer){


       int(*Math[])(int,int) = {
       	Addition,Subtraction,Divide,Multiply
       };

        //perform math
	    return answer =
	    (answer >= 1 && answer < 5)?
		  Math[answer-1](
		   
		   getNum(),
		   getNum()

		   ) : 0;
		   	        
}

//get data from user
int getNum(void){

    int pool = 0;

    start_magenta
			print("[Enter Data] : ")
		color_end
		read(&pool)
    console_dash
    
    return (isNegative(pool) || isNegative(0))? 0 : pool;
	
}


////         CASE OPERATION			////

//check left number is greater than right 
//number
int isGreaterThan(int num1,int num2){
   
     return (num1 < num2) ? 1 : 0;

}


////     BASIC  ARITHMETIC OPERATOR   ////

int Addition(int num1,int num2){

	return isNegative(num1)||isNegative(num2) ?  0 : num1 + num2;
	   
}

int Subtraction(int num1,int num2){

	return(isNegative(num1) || isNegative(num2)&&isGreaterThan(num1,num2))
    ? 0 : num1 - num2;
	  
}

int Multiply(int num1,int num2){

	return (isNegative(num1)|| isNegative(num2)) ?
	0 : num1 * num2;
	
}

int Divide(int num1,int num2){

	return (isNegative(num1) || isNegative(num2))  ?
	0 : num1 / num2;
	
}