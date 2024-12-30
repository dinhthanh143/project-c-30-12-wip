//khai bao ham
#include"datatypes.h"
void showMenu();
void userMenu();
void adminMenu();
void login();
void showUsersData(struct User users[],int length);
void inputUsersData(struct User users[],int *length);
void searchUserByName(struct User users[],int length);
void checkUserDataById(struct User users[],int length);
void lockAndUnlockId(struct User users[],int length);
void arrangeUsers(struct User users[],int length);

