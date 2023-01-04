#include <stdio.h>
#include <stdlib.h>

//declaring board and functions needed
char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
int checkWin();
void drawBoard();

int main(void) {
  
  //declaring needed variables
  int player = 1;
  int check = -1;
  int choice;
  char symbol; //X or O
  
  do{
    //draws board
    drawBoard();

    //player changes based on if player number is divisible by 2
    player = (player % 2) ? 1 : 2;

    //takes player choice
    printf("Player %d, enter choice: ", player);
    scanf("%d", &choice);

    //symbol changes based on player number
    symbol = (player == 1) ? 'X' : 'O';

    //changes board according to player choice
    if (choice == 1 && board[1] == '1'){
      board[1] = symbol;
    }
    else if (choice == 2 && board[2] == '2'){
      board[2] = symbol;
    }
    else if (choice == 3 && board[3] == '3'){
      board[3] = symbol;
    }
    else if (choice == 4 && board[4] == '4'){
      board[4] = symbol;
    }
    else if (choice == 5 && board[5] == '5'){
      board[5] = symbol;
    }
    else if (choice == 6 && board[6] == '6'){
      board[6] = symbol;
    }
    else if (choice == 7 && board[7] == '7'){
      board[7] = symbol;
    }
    else if (choice == 8 && board[8] == '8'){
      board[8] = symbol;
    }
    else if (choice == 9 && board[9] == '9'){
      board[9] = symbol;
    }
    else{
      printf("\nInvalid Option!");
      player--;
    }

    //checks if player has won
    check = checkWin();
    player++;

    //repeats loop until someone wins or tie occurs
  } while(check == -1);

  //draws board
  drawBoard();

  //checks if player won
  if(check == 1){
    printf("==>Player %d Won", --player);
  }

  //otherwise it is a tie
  else{
    printf("==>Tie Game");
  }

  return 0;
}

//checks if player has won
int checkWin(){
  
  //checks rows
  if(board[1] == board[2] && board[2] == board[3]){
    return 1;
  }
  else if(board[4] == board[5] && board[5] == board[6]){
    return 1;
  }
  else if(board[7] == board[8] && board[8] == board[9]){
    return 1;
  }

  //checks columns
  else if(board[1] == board[4] && board[4] == board[7]){
    return 1;
  }
  else if(board[2] == board[5] && board[5] == board[8]){
    return 1;
  }
  else if(board[3] == board[6] && board[6] == board[9]){
    return 1;
  }

  //checks diagonals
  else if(board[1] == board[5] && board[5] == board[9]){
    return 1;
  }
  else if(board[3] == board[5] && board[5] == board[7]){
    return 1;
  }

  //checks if all spots are filled
  else if(board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9'){
    return 0;
  }
  else{
    return -1;
  }
}

//draws game board
void drawBoard(){
  printf("\n\n\t Tic Tac Toe \n\n");
  printf("Player1 (X) - Player2 (O) \n\n\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
  printf("     |     |     \n\n");
}