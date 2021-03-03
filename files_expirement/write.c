
//
// author: john jayson b. de leon
// email : savjaylade84@gmail.com
//

//libraries or package 
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<string.h>
#include<ctype.h>
#include<errno.h>

#define console_dash printf("\n===========================================================\n");

#define write_file(text,file) fputs(text,file)
#define read_file(file,type,holder) fscanf(file,type,holder)
#define close_file(file) fclose(file)
#define open_file(filename,filemode) fopen(filename,filemode)

//console color
#define start_cyan printf("\e[5;36m");
#define start_green printf("\e[5;32m");
#define start_magenta printf("\e[5;35m");
#define start_yellow printf("\e[5;33m");
#define start_blue printf("\e[5;34m");
#define start_red printf("\e[5;31m");
#define color_end printf("\e[0m");

//create data type string
typedef char* string;

//create file mode for accessing file
typedef enum {WRITE = 1,READ = 2,APPEND = 3,ACCESSIBLE = 4}file_mode;

//function prototype
string FileMode(int mode);
void Read(FILE **file);
void Write(string *text,FILE **file);
void string_checkup(string *text);
void file_checkup(FILE **file);
void get_filename(string *filename);
void get_mode(int *mode);
void startup(string dates,string date);

//size of memory need for storing string
static int mem_size = 1000;

int main(void){

	string message = malloc(mem_size);
	string filename = malloc(mem_size);

	startup(__DATE__,__TIME__);
	
	//give a flexible to the user to use
	//any file he wants 
	get_filename(&filename);

	int Mode;

	while(1){
	
	get_mode(&Mode);

	//request to open the file do a specific job to it
	FILE *file = open_file(filename,FileMode((int)Mode));		

	getchar();

    //write the message from user to the file
	if(Mode == 1 || Mode == 3)
    	Write(&message,&(file));
	
    //print the text from file
    if(Mode == 2)
    	Read(&(file));

	getchar();
	console_dash
	
	//give the control loop to the user
	start_yellow
		printf("Do you want try again [Y/N] : ");
	color_end
	char ans = (char)tolower(getchar());
	
	if( ans == 'n')
		break;

	//close the file for clean exit
	//jobs done
	close_file(file);
	
	}
	
    //clean up the memory that have been use
    //to prevent memory leak in the program
	free(message);

	return EXIT_SUCCESS;
}

//use for determine the mode of the file
string  FileMode(int  mode){

      switch(mode){

         case 1:
                return "w";
         case 2:
                return "r";
         case 3:
                return  "a";
         case 4:
         		return "+a";

      }


      return "r";
 }


void Read(FILE **file){

	file_checkup(file);

		//get the text from files
		string temp = malloc(mem_size);
		read_file(*file,"%[^\n]s",temp);
			
	string_checkup(&temp);	

	console_dash

		//print text from files
		start_magenta
			printf("[text from file] : %s\n",temp);
		color_end

	free(temp);
	
}

void Write(string *text,FILE **file){

	 file_checkup(file);

	console_dash
	 	//get text from use
	 	start_magenta
    	 printf("[Enter Text] : ");
    	color_end
     	scanf("%[^\n]s",*text);
     	
	 string_checkup(text);

	 	//write text to the file
     	write_file(*text,*file);
	
}

void string_checkup(string *text){

     //check if message is empty
     if(*text == NULL){

	console_dash
	
     	start_red
          printf("[error] : %s" , strerror(errno));
        color_end
         exit(EXIT_FAILURE);
      }

     //check if message from user is too big to store
     //in the message storage if it is then double the size
     //of memory by requesting reallocate more memory
     if((int)strlen(*text) >= mem_size)
         text = realloc(text,mem_size += 1000 );
	
}


void file_checkup(FILE **file ){

	if(ferror(*file)){

	console_dash

		start_red
			printf("[error] : %s",strerror(errno));
		color_end
		exit(EXIT_FAILURE);
	}
	
}

void get_filename(string *filename){

	     //give a flexible to the user to use
	     //any file he wants
	     start_cyan
	      	printf("[Enter file] : ");
	     color_end
	      scanf("%s",*filename);
	      string_checkup(filename);
	
}

void get_mode(int *mode){

	console_dash

	start_cyan
		printf("%s%s%s%s%s",
             "File Mode:",
             "\n[1] : Write",
             "\n[2] : Read",
             "\n[3] : Append",
             "\n[Enter] : ");
    color_end
     scanf("%d",mode);

     if(*mode > 4 && *mode < 0){

	console_dash
     
     	start_red
         printf("[error] : Not A Mode");
        color_end
         exit(EXIT_FAILURE);
	}
}

void startup(string dates,string time){

	console_dash

	start_green
		printf("[[ :: Terminal File Editor :: ]]");
	color_end

	console_dash

	start_green
		printf("Date : %s : %s",dates,time);
	color_end

	console_dash
	
}