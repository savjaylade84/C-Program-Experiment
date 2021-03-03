#include<stdbool.h>
//try and catch
#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw() __HadError=true;goto ExitJmp;