#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

//This function will print out the final filtered array onto stdout

void printloop(int finalarraysize, char finalcontainer[][20]){

int i;
	for(i=0; i<finalarraysize;i++){
		
		//this if statement is used for the purpose of preventing trailing white spaces and newlines as they are considered as string it would prevent the program from adding additional spaces
		//when the "\n" is encountered or when " " is encountered within the final filtered array
		if(strcmp(finalcontainer[i]," ")==0 || strcmp(finalcontainer[i+1]," ")==0 || strcmp(finalcontainer[i],"\n")==0 || strcmp(finalcontainer[i+1],"\n")==0){
		printf("%s",finalcontainer[i]);

		}
		else{
		printf("%s ",finalcontainer[i]);
		}
	
	}


}




int main(int argc, char **argv){

//original string container which will hold the texts from stdin
char string[10000];

//final filtered string array that doesn't include upper-cases and punctuations
char final[10000][20];

//word separator
char separator[]=" ";

//keeps track of current position of word
int counter=0;

//this while loop would be used to read each line of the file
while (fgets(string,sizeof(string),stdin) != NULL){

	
	
	//a single word (token) of the entire sentence
	char *portion = strtok(string,separator);

	

	//loop used to filter thru all the tokens of the sentence and excluding punctuations and uppercase characters
	while(portion != NULL){

		
		//created an additional variable to keep track of the position of the letter in the current token for easier manipulation rather than tampering with the for loop's variable
		int j=0;
		int k;

		for(k=0; k< strlen(portion); k++){
		
		char c=portion[k];

			if (isalpha(c) || isdigit(c)){

				final[counter][j++]=tolower(c);


			}

			

		}
		//increment the word position in the array
		counter++;
	
	//tells the portion to move on to the next word of the current sentence
	portion = strtok(NULL,separator);

	}

	
	//since the while loop would exclude punctuations, therefore we manually implement the escape character to start the next line
	strncpy(final[counter],"\n",20);
	//move onto the next word position
	counter++;
	
	

}




printloop(counter, final);




return 0;
}
