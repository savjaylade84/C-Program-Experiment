#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include "test.h"
#include "bank.h"

//change float deposite_amount and withdraw amount with function 
//pointer parameter

//========  bank core functions tools ================================

void  b_account_deposite(bank_account *account,long_double deposite_amount){

	if(b_account_check_amount(account->amount,deposite_amount))
	return;

	account->amount += deposite_amount;
	b_account_prompt_success(account);
}

extern void b_account_withdraw(bank_account *account,long_double withdraw_amount){

	if(b_account_check_amount(account->amount,withdraw_amount))
	return;

	account->amount -= withdraw_amount;
	b_account_prompt_success(account);
}

extern int b_account_check_amount(long_double current_amount,long_double given_amount){

		 log_matches("give non-negative and zero number",current_amount <= given_amount);
           if(current_amount <= given_amount ){

               printf("Transanction Terminated Due To Inefficient Amount");
               return 1;

          }

          return 0;

      }

extern void b_account_prompt_success(bank_account *account){

          printf("%s%s%s%s%s%s%Lf","\n[Message] Transaction Successful!",
                             "\n[Account Name] :",account->name,
                             "\n[Account ID] :",account->id,
                             "\n[Current Amount] :",account->amount );
           return;

       }

extern long_double  b_account_get_amount(){

	long_double temp = 0.0f;

	printf("[Amount] :");
	scanf("%Lf",&temp);
	fflush(stdin);

	log_inputs_long_double(temp);

	return temp;
	
}

//==================================================

//======== account management  functions ============

extern void b_account_login(const char* uname, const char* passwd){

	FILE* file =  fopen("account_sheet.txt","r");
	char* _uname = malloc(sizeof(char) * 50);
	char* _passwd = malloc(sizeof(char) * 50);

	while(fscanf(file,"%s %s",_uname,_passwd) != EOF){

		if(strcmp(_uname,uname) && strcmp(_passwd,passwd)) return;
			// b_account_find(_uname);
		
	}

	free(_uname);
	free(_passwd);
	fflush(file);
	fclose(file);
	
}

extern bank_account* b_account_find(const char* _uname){

	bank_account* account = malloc(sizeof(bank_account));
	FILE* file = fopen(strcat((char*)_uname,".txt"),"r");

	if(file)
	  log_errors("file corrupted.");
	
	if(ferror(file))
	  log_errors("file errors");

	if(fscanf(file,"%s %s %Lf",account->id,account->name,&(account->amount))){

	//put success logging here
		
	}else
	  log_errors("failed to read");
	

 	return account;	
}

//=======================================================

extern void b_account_selection_command(bank_account *account){

            printf("%s%s%s%s%s%s%s",
                                        "\nWelcome to the Bank Inc.",
                                        "\n[Select Command]",
                                        "\n[1] Deposite:",
                                        "\n[2] Withdraw:",
                                        "\n[3] Balance:",
                                        "\n[4] Logout:",
                                        "\n[Enter] : ");
            unsigned short selection = 0;
            scanf("%hu",&selection);
            fflush(stdin);

            log_inputs_short((short)selection);

            switch(selection){

                case 1:
                       b_account_deposite(account,
                       b_account_get_amount());
                       return;
                case 2:
                       b_account_withdraw(account,
                       b_account_get_amount());
                       return;
                case 3:
                       b_account_prompt_success(account);
                       return;

                case 4:
                      exit(EXIT_SUCCESS);

            }

        }