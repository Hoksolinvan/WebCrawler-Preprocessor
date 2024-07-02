#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>





//This function will be used to print out the final filtered texts
void printloop(int finalarraysize, char finalcontainer[][20])
{


	int i;
	for(i=0; i<finalarraysize; i++){
		
	//this if statement ensures that when the loop encounters an " " or an "\n" to print it out without adding an additional redundant space

		if(strcmp(finalcontainer[i]," ")==0  || strcmp(finalcontainer[i+1]," ")==0 ||  strcmp(finalcontainer[i],"\n")==0 || strcmp(finalcontainer[i+1],"\n")==0){
		printf("%s",finalcontainer[i]);
		}
		else {
		printf("%s ",finalcontainer[i]);
		}
	}

}

//function to check if the current word is a stopword
int isstopwords(char *word, char stopwords[][10]){
	
	int i;
	for (i=0; i<9; i++){
		if(strcmp(word,stopwords[i])==0){

			return 1;
		}

	}

			return 0;

} 




//main function
int main (int argc, char **argv) 
{

//collections of stopwords
char stopwords[12][10]={"the", "a", "an", "of", "for", "to", "and", "but", "yet"};

//original input array which reads from user-input
char string[10000];

// will contain the collection of all words which does not include the stopwords
char finalcontainer[10000][20]; 

//counter to keep track of the number of words in finalcontainer
int counter=0; 

char separator[]=" \n"; 



//this while loop will be used to read line-by-line of the input until it reaches NULL
while(fgets(string,sizeof(string),stdin) != NULL){


	//A single word of the current line
	char *portion= strtok(string,separator);

		//this while loop will be used to loop through the the tokens(words) of the current line
		while(portion != NULL){

			//stores value of isstopwords function
			int isstopword = isstopwords(portion, stopwords);

			if(isstopword==0){
				
					int k;
					for (k=0; k<strlen(portion);k++){
						finalcontainer[counter][k]=portion[k];
					}

				
				
				//increments the position of the word tracker because this current word is already dealt with!
				counter++;
				
			}

	//tells the pointer to point to the next token/word of the current sentence
	portion = strtok(NULL, separator);

	}
		
		strcpy(finalcontainer[counter],"\n");
		counter++;
		
		
		
		
	
}


	//calling the printloop function
	printloop(counter, finalcontainer);


return 0;
}





