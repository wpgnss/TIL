/*
https://www.acmicpc.net/problem/1063

*/

#include <stdio.h>
#include <string.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define MAX_CHESS_TABLE 8

#define MARK_KING 'K'
#define MARK_STONE 'S'

typedef enum command
{
    COMMAND_R = 1,
    COMMAND_L,
    COMMAND_B,
    COMMAND_T,
    COMMAND_RT,
    COMMAND_LT,
    COMMAND_RB,
    COMMAND_LB,
}COMMAND;

typedef struct pieces
{
    int pos_x;
    int pos_y;
    char mark;
} PIECE;

void inputPosition(PIECE *king, PIECE *stone, int* num_of_command)
{
	char pos_king[2] = {0,};
    char pos_stone[2] = {0,};

    scanf("%s %s %d", pos_king, pos_stone, num_of_command);

    king->pos_x = pos_king[0] - 'A' + 1;
    king->pos_y = pos_king[1] - '0';
    king->mark = MARK_KING;

    stone->pos_x = pos_stone[0] - 'A' + 1;
    stone->pos_y = pos_stone[1] - '0';
    stone->mark = MARK_STONE;
}


int move_piece(PIECE *piece, COMMAND cmd)
{
    int is_movable = TRUE;

    if(cmd == COMMAND_R)
    {
        piece->pos_x++;
        if(piece->pos_x > MAX_CHESS_TABLE) 
        {
            piece->pos_x--;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_L)
    {
        piece->pos_x--;
        if(piece->pos_x == 0)
        {
            piece->pos_x++;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_B)
    {
        piece->pos_y--;
        if(piece->pos_y == 0) 
        {
            piece->pos_y++;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_T)
    {
        piece->pos_y++;
        if(piece->pos_y > MAX_CHESS_TABLE)
        {
            piece->pos_y--;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_RT)
    {
        piece->pos_x++;
        piece->pos_y++;

        if(piece->pos_x > MAX_CHESS_TABLE || piece->pos_y > MAX_CHESS_TABLE) 
        {
            piece->pos_x--;
            piece->pos_y--;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_LT)
    {
        piece->pos_x--;
        piece->pos_y++;

        if(piece->pos_x == 0 || piece->pos_y > MAX_CHESS_TABLE) 
        {
            piece->pos_x++;
            piece->pos_y--;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_RB)
    {
        piece->pos_x++;
        piece->pos_y--;
        
        if(piece->pos_x > MAX_CHESS_TABLE || piece->pos_y == 0) 
        {
            piece->pos_x--;
            piece->pos_y++;
            is_movable = FALSE;
        }
    }
    else if(cmd == COMMAND_LB)
    {
        piece->pos_x--;
        piece->pos_y--;

        if(piece->pos_x == 0 || piece->pos_y == 0) 
        {
            piece->pos_x++;
            piece->pos_y++;
            is_movable = FALSE;
        }
    }

    return is_movable;
}


int is_same_place(PIECE *king, PIECE *stone)
{
    if(king->pos_x == stone->pos_x && king->pos_y == stone->pos_y)
    {
        // printf("=== SAME KING (%d, %d) STONE (%d, %d)\n", king->pos_x, king->pos_y, stone->pos_x, stone->pos_y);
        return TRUE;
    }
    else
        return FALSE;
}

void process_command(PIECE *king, PIECE *stone, COMMAND cmd)
{
    int is_movable = FALSE;
    int is_same = FALSE;
    COMMAND backward_cmd;

    if(cmd == COMMAND_R) backward_cmd = COMMAND_L;
    else if(cmd == COMMAND_L) backward_cmd = COMMAND_R;
    else if(cmd == COMMAND_B) backward_cmd = COMMAND_T;
    else if(cmd == COMMAND_T) backward_cmd = COMMAND_B;
    else if(cmd == COMMAND_RT) backward_cmd = COMMAND_LB;
    else if(cmd == COMMAND_LB) backward_cmd = COMMAND_RT;
    else if(cmd == COMMAND_LT) backward_cmd = COMMAND_RB;
    else if(cmd == COMMAND_RB) backward_cmd = COMMAND_LT;

    move_piece(king, cmd);
    
    is_same = is_same_place(king, stone);
    if(is_same == TRUE)
    {
        is_movable = move_piece(stone, cmd);
        if(is_movable == FALSE)
        {
            // move_piece(stone, backward_cmd);
            move_piece(king, backward_cmd);
        }
    }

}

void printPosition(PIECE *piece)
{
    char pos_x;
    char pos_y;

    pos_x = piece->pos_x + 'A' - 1;
    pos_y = piece->pos_y + '0';
    
    printf("%c%c\n", pos_x, pos_y);
}

void print_table(PIECE *king, PIECE *stone)
{
    int i,j;
    char chess_array[MAX_CHESS_TABLE+1][MAX_CHESS_TABLE+1] = {0,};
    
    chess_array[king->pos_x][king->pos_y] = king->mark;
    chess_array[stone->pos_x][stone->pos_y] = stone->mark;

    printf("=== print table ==== %d, %d, %d, %d\n", king->pos_x, king->pos_y, stone->pos_x, stone->pos_y);
    for(i=MAX_CHESS_TABLE; i>0; i--)
    {
        for(j=1; j<=MAX_CHESS_TABLE; j++)
        {
            if( chess_array[j][i] == 0) printf("O ");
            
            printf("%c ", chess_array[j][i]);
        }
        printf("\n");
    }
}

COMMAND inputCommand()
{
    
	char command[2] = {0,};
    scanf("%s", command);
    // printf("!!!! %s\n", command);
    if( strncasecmp(command, "RT", strlen("RT")) == 0)
        return COMMAND_RT;
    else if( strncasecmp(command, "LT", strlen("LT")) == 0)
        return COMMAND_LT;
    else if( strncasecmp(command, "RB", strlen("RB")) == 0)
        return COMMAND_RB;
    else if( strncasecmp(command, "LB", strlen("LB")) == 0)
        return COMMAND_LB;
    else if( strncasecmp(command, "R", strlen("R")) == 0)
        return COMMAND_R;
    else if( strncasecmp(command, "L", strlen("L")) == 0)
        return COMMAND_L;
    else if( strncasecmp(command, "B", strlen("B")) == 0)
        return COMMAND_B;
    else if( strncasecmp(command, "T", strlen("T")) == 0)
        return COMMAND_T;
    else
        return 0;
}

int main(void)
{
    int count=0;
    PIECE king, stone;

    char chess_array[MAX_CHESS_TABLE+1][MAX_CHESS_TABLE+1] = {0,};
    int num_of_command = 0;
    int i;
    COMMAND command;

    inputPosition(&king, &stone, &num_of_command);
    // print_table(&king, &stone);

    for(i=0; i<num_of_command; i++)
    {
        command = inputCommand();

        process_command(&king, &stone, command);
        // print_table(&king, &stone);
    }

    printPosition(&king);
    printPosition(&stone);
    return 0;
}
