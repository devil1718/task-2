#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size 100

typedef union 
{
  int intState;
  bool boolState;
} Status;

typedef struct 
{
  char username[20];
  char password[20];
  Status status;
} User;

int main()
{

  int num;
  int userNum = 0;
  User users[size];

  while (1)
  {

  char username[30];
  char password[30];

    printf("To register enter 1\nTo login enter 2\nTo Exit enter 3\nEnter a number: ");
    scanf("%d", &num);

    if (num == 1)
    {

      if (userNum >= size)
      {
        printf("The users is full\n");
        continue;
      }

      printf("Enter your username: ");
      scanf("%s", &username);
      int flag = 0;
      for (int i = 0; i < userNum; i++)
      {
        if (strcmp(username, users[i].username) == 0)
        {
          printf("Username already exists\n");
          flag = 1;
          break;
        }
      }
      if (flag) {
        continue;
      }
      printf("Enter your password: ");
      scanf("%s", &password);

      char state[8];
      printf("Account state, enter true or 1 for active, false or 0 for inactive: ");
      scanf("%s", &state);

      Status accountState;
      while(1) {
        if (strcmp(state, "true") == 0) {
          accountState.boolState = true;
          break;
        } else if (strcmp(state, "1") == 0) {
          accountState.intState = 1;
          break;
        } else if (strcmp(state, "false") == 0) {
          accountState.boolState = false;
          break;
        } else if (strcmp(state, "0") == 0) {
          accountState.intState = 0;
          break;
        } else {
        printf("Invalid state, please enter a valid state enter true or 1 for active, false or 0 for inactive: ");
        scanf("%s", &state);
        }
      }

      User user;
      strcpy(user.username, username);
      strcpy(user.password, password);
      user.status = accountState;
      users[userNum] = user;
      userNum++;
      printf("Registered\n");
    }
    else if (num == 2)
    {

      printf("Enter your username: ");
      scanf("%s", &username);
      printf("Enter your password: ");
      scanf("%s", &password);

      int flag = 0;
      for (int i = 0; i < userNum; i++)
      {

        if ((strcmp(username, users[i].username) == 0) && (strcmp(password, users[i].password) == 0))
        {
          if (users[i].status.boolState == true || users[i].status.intState == 1) {
          printf("You are logged in\n");
          } 
          else {
            printf("You are not active\n");
          }
          flag = 1;
          continue;
        }
      }
      if (flag) {
        continue;
      }
      printf("Invalid username or password\n");
    }
    else if (num == 3)
    {
      break;
    }
    else
    {
      printf("Invalid number\n");
    }
  }
}
