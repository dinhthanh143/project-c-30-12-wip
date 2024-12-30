#include<stdbool.h>
struct Date{
	int day,month,year;
};
struct User{
	char userId[15];//10
	char name[25];//20
	char phone[15];//10
	char email[25];//20
	char status[15];//10
	char password[15];//10
};
struct User users[100];
struct User usersFromFile[100];
struct Transaction;
