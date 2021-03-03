#include <stdio.h>
#include<stdlib.h>

#ifndef BANK_H
#define BANK_H

 typedef long double long_double;

 typedef struct{
       char *id;
       char *name;
       long_double  amount;
  }bank_account;

     extern void b_account_login(const char* uname,const char* passwd);
     extern void b_account_create();
     extern bank_account* b_account_find(const char* _uname);
     extern void b_account_main();
	 extern void b_account_selection_command( bank_account *account);
	 extern long_double b_account_get_amount();
     extern int b_account_check_amount(long_double current_amount,long_double given_amount);
     extern void b_account_prompt_success(bank_account *account);
     extern void  b_account_deposite(bank_account *account,long_double deposite_amount);
	 extern void b_account_withdraw(bank_account *account,long_double withdraw_amount);


#endif