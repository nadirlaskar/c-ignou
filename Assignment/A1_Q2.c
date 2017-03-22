#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define read  "r"
#define write "w"
 

int checkIfExist(char*);
char* readContentFromFile(FILE*);
void writeContentToFile(FILE*,char*);

int readMode();
void readFileName();
void readContentFromKeyboard(char* content);

void getFile(char*,char*,FILE* file);
int clearKeys();
char* concat(const char *s1, const char *s2);

int isEndOfInput();

int checkIfExist(char* filename){
	int exist=0;
	FILE* doc;
	puts(filename);
	doc = fopen(filename,"r");
	
	if(doc != NULL) {exist=1;fclose(doc);}
	else  printf("\n\n ERROR:: File not found in the system.");


	return exist;
}

char* readContentFromFile(FILE* file){
		
	fseek(file,0,SEEK_END);
	long file_size = ftell(file);
	fseek(file,0,SEEK_SET);
	
	char* msg = malloc(file_size+1);
	
	fread(msg,file_size,1,file);
	
	fclose(file);
	
	msg[file_size] = 0;

	return msg;
	
}

void getFile(char* filename,char* mode,FILE* file){
		
	file = fopen(filename,mode);

}

void readFileName(char* filename){

	do{	
		printf("\n\n Please enter the name of the file >> ");
		clearKeys();
		char c;
		do{
			c = getchar();
			if(c!='\n') filename = concat(filename,(char*)c);
		}while(c!='\n');

	} while(checkIfExist(filename)==0);

	puts("done");
	
	return;
}


int readMode(){
	int mode = 0;
	printf("\n\nPress 1: To Read file.\n");
	printf("Press 2: To Write to file.\n");
	printf("\n\n Enter your choice: ");

	scanf("%d",&mode);
	
	if(mode<1&&mode>2) {
		printf("\n\nERROR:: INVALID MODE");
		return readMode();
	} else if(mode==2) mode==1;
	return mode;
}

int clearKeys(){
    char c;
    int keys=0;
    while ((c = getchar()) != '\n' && c != EOF) { keys++;};
    return keys;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void main(){
	
	char filename[1000];
	FILE* file;

	readFileName(filename);
	
	puts("1");
 	
	if(readMode()) {
		puts("2");
		getFile(filename,read,file);
		puts("3");	
		printf("\n\n FILE:: %s\n\n%s ",filename,readContentFromFile(file));
		puts("4");
	}
	else printf("\n\n ERROR:: WRITE NOT SUPPORTED YET ! ");

}


