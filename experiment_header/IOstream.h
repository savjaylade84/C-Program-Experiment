#include<stdio.h>
#include "tryCatch.h"
#include "test.h"
#include "strings.h"
//prints style
#define print(message)puts(message);
#define read(string,placeholder)gets(placeholder)puts(string);
#define read_int(strings,placeholder)scanf("%i",&placeholder);printf("%s",strings);
#define read_double(strings,placeholder)scanf("%lf",&placeholder);printf("%s",strings);
#define read_float(strings,placeholder) scanf("%f",&placeholder);printf("%s",strings);

//convert 
#define parseInt(x) (int)x
#define parseChar(x) (char)x
#define parseFloat(x) (float)x
#define parseDouble(x) (double)

#define def {
#define en }
#define and &&
#define or ||
#define not !
#define as  =
#define equal ==
#define not_equal !=
#define greater >
#define lesser <
#define ref(x) (&x)
#define refer(x) &(x)
#define newln printf("\n");
#define Void_as void
#define Integer_as int
#define Float_as int
#define Double_as double
#define Character_as char
typedef char* string;
#define String as string
#define return(x) return x;

string upper(string message)
def
string tmp;

	for(unsigned int i = 0;i lesser strlen(message); i++)
	  def  
	    int temp = parseInt(ref(message + i)) + 32;
	    tmp = tmp + parseChar(temp);
	  en

return(tmp)
	
en