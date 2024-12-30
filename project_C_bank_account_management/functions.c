#include"functions.h"
#include <stdio.h>
#include<string.h>
#include <stdbool.h>
//logic ham
void showMenu(){
	printf("  ***Bank Management System Using C***\n\n");
	printf("\t   CHOOSE YOUR ROLE\n");
	printf("\t========================\n");
	printf("\t[1] Admin.\n");
	printf("\t[2] User.\n");
	printf("\t[0] Exit The Program.\n");
	printf("\t========================\n");
}
void adminMenu(){
	printf("\n  ***Bank Management System Using C***\n\n");
	printf("\t   ADMIN MENU\n");
	printf("\t========================\n");
	printf("\t[1] Add A New User.\n");
	printf("\t[2] Show All users.\n");
	printf("\t[3] Search User By Name.\n");
	printf("\t[4] Check User Datas By ID.\n");
	printf("\t[5] Lock/Unlock User By ID.\n");
	printf("\t[6] Arrange Users List.\n");	
	printf("\t[0] Return To Menu.\n");
	printf("\t========================\n");
}
void inputUsersData(struct User users[], int *length){
	int check=0;
	int subCheck;
	int i;
	printf("\n");
	getchar();
	while(check==0){
		printf("*Enter User's ID(Below 10 characters): ");
		fgets(users[*length].userId,sizeof(users[*length].userId),stdin);
		users[*length].userId[strcspn(users[*length].userId,"\n")]='\0';
		fflush(stdin);
		if(strlen(users[*length].userId)>9 || strlen(users[*length].userId)==0 ){
			printf(" \n*Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].userId,users[i].userId)==0){
					printf(" \n*User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			if(subCheck!=0){
				break;
			}
		}
	}
	while(check==0){
    	printf("*Enter User's Name(Below 20 characters): ");
    	fgets(users[*length].name,sizeof(users[*length].name),stdin);
    	users[*length].name[strcspn(users[*length].name,"\n")]='\0';
		fflush(stdin);
    	if(strlen(users[*length].name)>19 || strlen(users[*length].name)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].name,users[i].name)==0){
					printf(" \n *User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			for(i=1;users[*length].name[i] != '\0';i++){
				if(users[*length].name[i-1]==' ' && users[*length].name[i]>='a' && users[*length].name[i]<='z'){
					subCheck=0;
					printf(" \n *Each Word Of User's Name Must Start In Uppercase!*\n\n");
					break;
				}			
			}
				if(users[*length].name[0]>='a' && users[*length].name[0]<='z'){
					subCheck=0;
					printf(" \n *User Name's First Letter Must Be Written In Uppercase!*\n\n");
				}
			
			if(subCheck!=0){
				break;
			}
		}
	}
	while(check==0){
    	printf("*Enter User's Phone Number(Below 10 characters): ");
   		fgets(users[*length].phone,sizeof(users[*length].phone),stdin);
   		users[*length].phone[strcspn(users[*length].phone,"\n")]='\0';
   	 	fflush(stdin);
    	if(strlen(users[*length].phone)>9 || strlen(users[*length].phone)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].phone,users[i].phone)==0){
					printf(" \n *User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			if(subCheck!=0){
				break;
			}
		}
	}
	while(check==0){
   		 printf("*Enter User's Email(Below 20 characters): ");
   		 fgets(users[*length].email,sizeof(users[*length].email),stdin);
   		 users[*length].email[strcspn(users[*length].email,"\n")]='\0';
   		 fflush(stdin);
    	if(strlen(users[*length].email)>19 || strlen(users[*length].email)==0){
			printf(" \n *Invalid Input.Try again!*\n\n");
			fflush(stdin);
		}else{
			subCheck=1;
			fflush(stdin);
			for(i=0;i<*length;i++){
				if(strcmp(users[*length].email,users[i].email)==0){
					printf(" \n *User's Information Must Not Overlap!*\n\n");	
					subCheck=0;
					break;
				}
			}
			if(subCheck!=0){
				break;
			}
		}
	}
	strcpy(users[*length].password, users[*length].phone);
	strcpy(users[*length].status, "Open");
	(*length)+=1;
	printf("\n **Successfully Added User Datas.**\n");
	printf(" =====================================\n");
}
void showUsersData(struct User users[],int length){
	int i;
	printf("\n\t\t\t**LIST OF USERS**\n");
	printf("|===========================================================================|\n");
    printf("|    ID    |       Name         |       Email        |   Phone   |  Status  |\n");
    printf("|==========|====================|====================|===========|==========|\n");
	for(i=0;i<length;i++){
		printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].status);
		printf("|----------|--------------------|--------------------|-----------|----------|\n");
	}
}
void searchUserByName(struct User users[],int length){
	int i;
	int check=0;
	int categoryCheck=0;
	printf("\n");
	getchar();
	char temp[25];
	while(1){
		printf("*Enter User's Name To Search(Below 20 characters): ");
		fgets(temp,25,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>19 || strlen(temp)==0){
   			printf("\n *Invalid Input.Try again!*\n\n");
		}else{
			break;
		}
	}
	for(i=0;i<length;i++){
		if (strstr(users[i].name, temp) != NULL){
			if(categoryCheck==0){
				printf("|===========================================================================|\n");
    			printf("|  ID      | Name               | Email              | Phone     | Status   |\n");
    			printf("|==========|====================|====================|===========|==========|\n");
    			categoryCheck++;
			}
			printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].status);
			printf("|----------|--------------------|--------------------|-----------|----------|\n");
			check++;
		}	
	}
	if(check==0){
		printf("\n **User Name Does Not Exist.**\n\n");
	}
}
void checkUserDataById(struct User users[],int length){
	int i;
	int check=0;
	char temp[15];
	getchar();
	while(1){
		printf("*Enter User's ID To Check(Below 10 characters): ");
		fgets(temp,15,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>9 || strlen(temp)==0){
   			printf("\n *Invalid ID.Try again!*\n\n");
		}else{
			break;
		}
	}
	for(i=0;i<length;i++){
		if(strcmp(temp,users[i].userId)==0){
				printf("\t\t\t**User Found!**\n");
				check++;
				printf("|===========================================================================|\n");
    			printf("|  ID      | Name               | Email              | Phone     | Status   |\n");
    			printf("|==========|====================|====================|===========|==========|\n");
    			printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].status);
				printf("|----------|--------------------|--------------------|-----------|----------|\n");
				break;
		}
	}
	if(check==0){
		printf("\n **ID Does Not Exist.**\n\n");
	}
}
void lockAndUnlockId(struct User users[],int length){
	printf("\n");
	int i;
	int check=0;
	char temp[15];
	int confirm=99;
	getchar();
	while(1){
		printf("*Enter User ID(Below 10 characters): ");
		fgets(temp,15,stdin);
   		temp[strcspn(temp,"\n")]='\0';	
   		fflush(stdin);
   		if(strlen(temp)>9 || strlen(temp)==0){
   			printf("\n *Invalid ID.Try again!*\n\n");
		}else{
			break;
		}
	}
		for(i=0;i<length;i++){
			if(strcmp(temp,users[i].userId)==0){
				printf("\t\t\t**User Found!**\n");
				check++;
				break;
			}
		}//POTENTIAL ERROR
		if(check==0){
			printf(" **ID Does Not Exist.**\n");
		}else if(strcmp(users[i].status, "Open")==0){
			while(1){
				printf("*This User's Account Is Currently Open, Do You Wish To Lock?(Press [1] To Confirm, [0] To Cancel): ");
				scanf("%d", &confirm);	
				if(confirm==1){
					strcpy(users[i].status, "Locked");
					printf(" **Successfully Locked.**\n");
					break;
				}else if(confirm==0){
					printf(" **Cancelled.**\n");
					break;
				}else{
					printf(" **Invalid Choice!**\n");
				}
			}
		}else{
			while(1){
				printf("*This User's Account Is Currently Locked, Do You Wish To Open?(Press [1] To Confirm, [0] To Cancel): ");
				scanf("%d", &confirm);	
			if(confirm==1){
					strcpy(users[i].status, "Open");
					printf(" **Successfully Opened.**\n");
					break;
			}else if(confirm==0){
					printf(" **Cancelled.**\n");
					break;
			}else{
					printf(" **Invalid Choice!**\n");
				}
			}
		}
}
void arrangeUsers(struct User users[],int length){
	printf("\n");
	int i,j;
	char min;
	char temp[30];
	int choice;
	while(1){
			printf(" **Select Arrange Options:**\n");
		printf("*[1]From A-Z*\n");
		printf("*[2]From Z-A*\n");
		printf("\n*Your Choice: ");
		scanf("%d", &choice);
		if(choice==2){
			for(i=0;i<length;i++){
				for(j=i+1;j<length;j++){
					if(users[j].name[0]>users[i].name[0]){
						//id
						strcpy(temp,users[j].userId);
						strcpy(users[j].userId, users[i].userId);
						strcpy(users[i].userId, temp);
						//name
						strcpy(temp,users[j].name);
						strcpy(users[j].name, users[i].name);
						strcpy(users[i].name, temp);
						//phone
						strcpy(temp, users[j].phone);
						strcpy(users[j].phone, users[i].phone);
						strcpy(users[i].phone, temp);
						//email
						strcpy(temp, users[j].email);
						strcpy(users[j].email, users[i].email);
						strcpy(users[i].email, temp);
						//status
						strcpy(temp, users[j].status);
						strcpy(users[j].status, users[i].status);
						strcpy(users[i].status, temp);
					}
				}	 
			}
			break;
		}else if(choice==1){
			for(i=0;i<length;i++){
				for(j=i+1;j<length;j++){
					if(users[j].name[0]<users[i].name[0]){
						//id
						strcpy(temp,users[j].userId);
						strcpy(users[j].userId, users[i].userId);
						strcpy(users[i].userId, temp);
						//name
						strcpy(temp,users[j].name);
						strcpy(users[j].name, users[i].name);
						strcpy(users[i].name, temp);
						//phone
						strcpy(temp, users[j].phone);
						strcpy(users[j].phone, users[i].phone);
						strcpy(users[i].phone, temp);
						//email
						strcpy(temp, users[j].email);
						strcpy(users[j].email, users[i].email);
						strcpy(users[i].email, temp);
						//status
						strcpy(temp, users[j].status);
						strcpy(users[j].status, users[i].status);
						strcpy(users[i].status, temp);
					}
				}
			}
			break;
		}else{
			printf(" **Invalid choice!.**\n");
		}
	}
	printf("|===========================================================================|\n");
    printf("|    ID    |       Name         |       Email        |   Phone   |  Status  |\n");
    printf("|==========|====================|====================|===========|==========|\n");
	for(i=0;i<length;i++){
		printf("|%-9s |%-19s |%-19s |%-9s  |%-9s |\n",users[i].userId,users[i].name,users[i].email,users[i].phone,users[i].status);
		printf("|----------|--------------------|--------------------|-----------|----------|\n");
	}
}



