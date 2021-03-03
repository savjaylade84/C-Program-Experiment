#include<stdio.h>
#include<string.h>
#include "test.h"

extern inline void log_match(const char* message,int trueFalse,int line);
extern inline void check_error_file(FILE** file);

extern void log_input(const char* input,int line){

	FILE *file = fopen("input_sheet.txt","a+");

		check_error_file(&file);

		fprintf(file,"[ Input ] @ [ Line : %d ] : %s",line,input);

	fflush(file);
	fflush(stdin);
	fclose(file);	
}

extern void log_input_int(int input,int line){

     FILE *file = fopen("input_sheet.txt","a+");

         check_error_file(&file);

         fprintf(file,"[ Input ] @ [ Line : %d ] : %d",line,input);

     fflush(file);
     fflush(stdin);
     fclose(file);
}

extern void log_input_long(long input,int line){

     FILE *file = fopen("input_sheet.txt","a+");

         check_error_file(&file);

         fprintf(file,"[ Input ] @ [ Line : %d ] : %ld",line,input);

     fflush(file);
     fflush(stdin);
     fclose(file);
}

extern void log_input_short(short input,int line){

     FILE *file = fopen("input_sheet.txt","a+");

         check_error_file(&file);

         fprintf(file,"[ Input ] @ [ Line : %d ] : %ud",line,input);

     fflush(file);
     fflush(stdin);
     fclose(file);
}

extern void log_input_float(float input,int line){

      FILE *file = fopen("input_sheet.txt","a+");

          check_error_file(&file);

          fprintf(file,"[ Input ] @ [ Line : %d ] : %f",line,input);

      fflush(file);
      fflush(stdin);
      fclose(file);
}

extern void log_input_double(double input,int line){

      FILE *file = fopen("input_sheet.txt","a+");

          check_error_file(&file);

          fprintf(file,"[ Input ] @ [ Line : %d ] : %lf",line,input);

      fflush(file);
      fflush(stdin);
      fclose(file);
}

extern void log_input_long_double(long double input,int line){

       FILE *file = fopen("input_sheet.txt","a+");

           check_error_file(&file);

           fprintf(file,"[ Input ] @ [ Line : %d ] : %Lf",line,input);

       fflush(file);
       fflush(stdin);
       fclose(file);
}

extern void prompt_error_tool(const char* message,int line){

     char* temp = malloc(sizeof(char) * 250);
     sprintf(temp,"[ Message ] @ [ Line : %d ] : %s",line,message);
     perror(temp);
     free(temp);

}

extern  void eval_string_input(char *expected,char *input){

		log_matches("matching string",strcmp(expected,input));
	
}

extern void eval_float_input(float expected,float output){

        log_matches("matching float",expected != output);
	
}

extern void eval_long_double_input(long double expected,long double output){

        log_matches("matching long double",expected != output);

  }


//implemet assert & error functioms here 

extern void log_error(const char* message,int line){

		FILE* file = fopen("error_sheet.txt","+r");
		
		check_error_file(&file);

		fprintf(file,"[ Error ] @ [ Line : %d ] : %s",line,message);

		fflush(file);
		fflush(stdin);
		fclose(file);
	
}

extern void log_assert(int assertion,const char* message,int line){

		FILE* file = fopen("assert_sheet.txt","a");

		check_error_file(&file);
		
		if(assertion > 0)
			fprintf(file,"[ Assert ] @ [ Line : %d  ] [ Result : %s  ] : %s",
		        	line,"False",message);

		fprintf(file,"[ Assert ] @ [ Line : %d  ] [ Result : %s  ] : %s",
					line,"True",message);
				
}