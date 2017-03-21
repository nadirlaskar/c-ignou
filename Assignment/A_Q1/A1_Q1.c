#include<stdio.h>
#define SUBSTRACT 1
#define COMPARE 2
#define ISODD 3
#define QUIT 4


void showMenu();
int choose_item();
void do_(int);
int getNumber();
void substractor(int,int);
void sorter(int,int,int*);
void compare(int,int);
void numberType(int);
int isOdd(int);
int clear_keys();

void main(){
	showMenu();
	do_(choose_item());
}

void showMenu(){

	printf("\n\n\t:: MENU ::\n\n\n\n");
	printf(" 1. SUBSTRACT TWO INTEGERS.\n\n");
	printf(" 2. COMPARE TWO INTEGERS TO FIND SMALLEST.\n\n");
	printf(" 3. TEST AN INTEGER FOR ODD AND EVEN.\n\n");
	printf(" 4. QUIT\n\n");
}

int choose_item(){
	int choice=0;
	printf("\n\n PLEASE CHOOSE AN OPERATION : (1,2,3,4) >> ");
	scanf("%d",&choice);

	int _k = clear_keys();
	if(_k) choice = -1;

	if(choice>0&&choice<5){
           return choice;
	}else{
            printf("\n\n ERROR:: INVALID SELECTION, CHOOSE FROM VALID OPTIONS (1,2,3,4)");
	    return choose_item();
	}
}

int getNumber(){
	int num = 0;
	printf("\n\n PLEASE ENTER A NUMBER : ");
	scanf("%d",&num);
	int _k = clear_keys();
	if(_k) {
		printf("\n\n ERROR:: PLEASE ENTER VALID NUMBER.");
		num = getNumber();
	}
	return num;
}

int clear_keys(){
    char c;
    int keys=0;
    while ((c = getchar()) != '\n' && c != EOF) { keys++;};
    return keys;
}

void do_(int item){
	
	switch(item){
		case SUBSTRACT:
			substractor(getNumber(),getNumber());
		break;
		case COMPARE:
			compare(getNumber(),getNumber());
		break;
		case ISODD:
			numberType(getNumber());
		break;

		case QUIT: return;

		default:
		   printf("\n\n ERROR:: APPLICATION ERROR : %d",item);
		   clear_keys();
	}
	
	getchar();
	showMenu();
	do_(choose_item());
}

void substractor(int op1,int op2){
	int number[2];
	sorter(op1,op2,number);
	
	printf("\n\n DIFFERENCE BETWEEN %d AND %d IS %d",number[0],number[1],number[0]-number[1]); 
}

void sorter(int op1,int op2,int* sort){
   if(op1>op2) {
	sort[0]=op1;
        sort[1]=op2;
   }
   else {
	sort[0]=op2;
	sort[1]=op1;
   }
}

void compare(int op1,int op2){
	int number[2];
	sorter(op1,op2,number);
	
	printf("\n\n SMALLEST NUMBER BETWEEN %d AND %d IS %d",op1,op2,*(number+1)); 
}

void numberType(int op1){
	char* type = "EVEN";
	if(isOdd(op1)) type ="ODD";

	printf("\n\n %d IS AN  %s NUMBER",op1,type);
}

int isOdd(int op1){
	return op1%2;
}


