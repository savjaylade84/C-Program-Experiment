
#include<stdio.h>
#include<stdlib.h>

#ifndef TEST_H
#define TEST_H

 extern void prompt_error_tool(const char* message,int line);
 #define prompt_error_tools(message) prompt_error_tool(message,__LINE__)

//============ log match tool ========+++++++==========

 extern inline void log_match(const char* message,int trueFalse,int line){

 FILE *file = fopen("test_file.txt","a+");

         if(file == NULL) prompt_error_tools("corrupted or missing input file");

         if(ferror(file)) prompt_error_tools("file failed at runtime");

		fprintf(file,"===========================================================");

        if(trueFalse > 0)
                 fprintf(file,"[ Evaluation ] @ [line : %d] : Not Match",line);
  		else
                 fprintf(file,"[ Evaluation ] @ [ line : %d ] : Match",line);
                 
		fprintf(file,"[ Message ] : %s",message);
         
  fflush(file);
  fflush(stdout);
  fclose(file);
 
  }

 #define log_matches(message,trueFalse) log_match(message,trueFalse,__LINE__)

//=========== log input tools =============================

 extern void log_input(const char* input,int line);
 #define log_inputs(input) log_input(input,__LINE__)

 extern void log_input_int(int input,int line);
 #define log_inputs_int(input) log_input_int(input,__LINE__)

 extern void log_input_short(short input,int line);
 #define log_inputs_short(input) log_input_short(input,__LINE__)

 extern void log_input_long(long input,int line);
 #define log_inputs_long(input) log_input_long(input,__LINE__)

 extern void log_input_float(float input,int line);
 #define log_inputs_float(input) log_input_float(input,__LINE__)

 extern void log_input_double(double input,int line);
 #define log_inputs_double(input) log_input_double(input,__LINE__)

 extern void log_input_long_double(long double input,int line);
 #define log_inputs_long_double(input) log_input_long_double(input,__LINE__)


//====== evaluation tools ===========================

 extern void eval_long_double_input(long double expected,long double output);
 extern void eval_string_input(char *expected,char *input);
 extern void eval_float_input(float expected,float output);
 extern void eval_show_file(char* filename,size_t*  file_size);

//======= assert & error logging tools ==============

 extern void log_error(const char* message,int line);
 #define log_errors(message) log_error(message,__LINE__)

 extern void log_assert(int assertion,const char* message,int line);
 #define log_s_assert(assertion,message) log_assert(assertion,message,__LINE__)

 //============ other tools =========================

 extern inline void check_error_file(FILE** file){

      if(*file == NULL) prompt_error_tools("corrupted or missing input file");

      if(ferror(*file)) prompt_error_tools("file failed at runtime");
 	
 }

#endif