
//-----------------------------------------
/*
*
*   << @Author: John Jayson B.De Leon >>
*   << @Email:savjaylade84@gmail.com >>
*   << @Twitter:@johnjaysonbdel1 >>
*   << @Facebook:jayson.deleon.393 >>
*   << @Github:savjaylade84 >>
*
*/
//------------------------------------------
#include "my_main.h"
import(IOSTREAM)

//transaction mode
const enum mode{

          DepositeMode = 1,
          WithdrawMode = 2,
          BalanceMode = 3,
          ExitMode = 4         
          
} transcMode;

//console color 
#define red "\033[0;31m"
#define green "\033[0;32m"
#define blue "\033[0;34m"
#define pink "\033[0;35m"
#define resetColor printf("\033[0m");

#define borderDash puts("\n--------------------------------------------------");
#define borderEqual puts("\n==================================================");

//fix error message
#define Account_Zero_Balance_Value_Error "<< Zero Or Negative Balance >>\n\tAccount Will Terminate Within 72 hours\n\tPls Inquire Our Nearest Local Branc\n\tFor Reopening Of Your Account"
#define Account_Inefficient_Money_Error "<< Inefficient Money >>"
#define Account_Not_Transaction_Mode_Error "<< Not A Transaction Mode >>"
#define Wrong_Input_Value_Error "<< Wrong Input Value >>"

//prototype functions 
Double_as withdraw(Double_as dmoney,Double_as *money);
Double_as deposite(Double_as dmoney,Double_as *money);
Double_as isNotZeroP2(Double_as num1,Double_as num2);
Double_as isNotZeroP1(Double_as *num);
Double_as getUserMoney();
Integer_as getEnterChar();
Void_as transaction(Double_as money,Integer_as mode);
Void_as startTransaction();
Void_as printwn(string message);
Void_as printmd(Double_as *money);
Void_as printmw(Double_as *money);
Void_as printmb(Double_as *money);


Integer_as main()
def
   //double money = 0.0;

   //console print test 
   //transaction(deposite(200,&money),DepositeMode);
   //transaction(1000,WithdrawMode);
   //transaction(money,BalanceMode);
   //transaction(money,4);
   //transaction(-23,BalanceMode);
   startTransaction();
    
   resetColor
   
   return(true)
   
en

//under construction
Void_as startTransaction()
def

    borderEqual
	print("<< Welcome To BankSystem >>") newln
	borderEqual
	newln
	print("Note:Pls Enter Mode Of Transaction")
    borderDash
    newln
	print("List Of Transaction Mode :")
	borderDash
	newln
	print("Deposite : 1") newln
	print("Withdraw : 2") newln
	print("Balance  : 3") newln
	print("Exit     : 4")
	borderDash

	try
	   def
	   
	         Integer_as enter = read_int("Enter:",enter);
    
             if(enter > 5)
              throw()
       
        en
    catch(string error)
       def
    
       printwn("Not A Mode");
       
	   en

en

Double_as getUserMoney()
def
return(0.0)
en


//print warning message
Void_as printwn(string message)
def

     print(red)
     print("\n(Warning): \n\t")
     print(message);
     resetColor
	
en

//print deposite money
Void_as printmd(double *money)
def

     print(blue)
     print("\n(Deposite): ")
     printf("< Updated Amount > | < $%9.2f >",*money);
     resetColor
	
en

//print withdraw money
Void_as printmw(double *money)
def

      print(pink)
      print("\n(Withdraw): ")
      printf("< Updated Amount > | < $%9.2f >",*money);
      resetColor
	
en

//print balance money
Void_as printmb(double *money)
def

      print(green)
      print("\n(Balance):  ")
      printf("< Current Amount > | < $%9.4f >",*money);
	
en

//check if its zero or negative number
//checks number
Double_as isNotZeroP1(double *num)
def

      test((*num) lesser 0)
      if( (*num) lesser 0)
        return(true)

    return(false)
	
en

//same function with isZeroP1
//except it has two parameters
Double_as isNotZeroP2(double num1,double num2)
def

       if(isNotZeroP1(&num1) and isNotZeroP1(&num2))
       return(true)

    return(false)
	
en

//transsction in the account
Void_as transaction(double money,int mode)
def


     test(money greater 0)
     if(isNotZeroP1(ref(money)))
       def
       switch(mode)
       def
       case 1 :
           printmd(ref(money));
           break;
       case 2 :
           printmw(ref(money));
           break;
       case 3 :
           printmb(ref(money));
           break;
       default:
           printwn(Account_Not_Transaction_Mode_Error);
        en
     en
     else
     def
     
     printwn(Account_Zero_Balance_Value_Error);    
     
	 en
	 
en

//deposite money
Double_as deposite(double dmoney,double *money)
def

      test((*money) greater 0)
      if(isNotZeroP1(ref(dmoney)))
         return(dmoney + (*money))
         
	return(0.0)
	
en

//withdraw money
Double_as withdraw(double dmoney,double *money)
def

       test((*money) greater 0)
       if(isNotZeroP1(ref(*money)) and dmoney greater (*money) )
	       return(dmoney - (*money))

	    return(0.0)
	 
en