#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include <stdbool.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
int main(int argc, char *argv[]) {
	FILE *file;
 	file =fopen("data.bin", "wb");
	if(file==NULL){
		printf("Error!\n");
	}
	fclose(file);
	int choiceMenu,choiceAdmin,choiceUser;
	int run=0;
	int length=0;
	int listSize=sizeof(users)/sizeof(users[0]);
	char temp[20];
	while(run==0){
		showMenu();
		printf("\tEnter The Choice: ");
		scanf("%d", &choiceMenu);
		switch(choiceMenu){
			case 1:
				while(choiceMenu==1){
					adminMenu();
					printf("\tEnter The Choice: ");
					scanf("%d", &choiceAdmin);				
					switch(choiceAdmin){
						case 1:
							inputUsersData(users,&length);
							break;
						case 2:
							showUsersData(users,length);
							break;
						case 3:
							searchUserByName(users,length);
							break;	
						case 4:
							checkUserDataById(users,length);
							break;
						case 5:
							lockAndUnlockId(users,length);
							break;
						case 6:
							arrangeUsers(users,length);
							break;
						case 0:
							break;	
						default: 
							printf("\n\t***Invalid Choice!***\n");
					}
					if (choiceAdmin==0){
						break;
					}
				}
				break;
		
			case 0:
				printf("\n  ==========Exited Program!===========\n");
				printf("   ========Thanks for using!=========\n");
				return 1;	
			default:
				printf("\n\t\t**Error!**\n\n");			
		}
	}
	return 0;
}
