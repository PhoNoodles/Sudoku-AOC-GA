#include "population.h"
#include "chromosome.h"

Chromosome::Chromosome(const int state[ROW][COL])
{
	copyBoard(state);
	fillBoard();
	fitness_score = fitnessEval();
}

void Chromosome::printState()
{
	for(int i = 0; i < COL; ++i)
	{
		for(int j = 0; j < ROW; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Chromosome::copyBoard(const int state[COL][ROW])
{
	for(int i = 0; i < COL; ++i)
	{
		for(int j = 0; j < ROW; ++j)
		{
			board[i][j] = state[i][j];
		}
	}
}

void Chromosome::fillBoard()
{
	for(int i = 0; i < COL ; ++i)//this is to go through each row
	{	
		//this section is to see what number is already in the row 
		int number[9] = {1,2,3,4,5,6,7,8,9};
		for(int j = 0; j < ROW; ++j)
		{
			//this is to mark what is already in the row
			if(board[i][j] != 0)
			{
				number[board[i][j]-1] = 0; 
			}
		}
		//this is where we start filling in the row
		for(int j = 0; j < ROW; ++j)
		{
			//if the board is 0 that means that it is not a fix number
			if(board[i][j] == 0)
			{
				//this is to choose a number that is not in the row
				int x = rand() % 9;
				//this is where we keep finding a number that hasnt been used
				while(number[x] == 0)
				{
					x = rand() % 9; 
				}
				//this is to add the number into the row
				board[i][j] = number[x];
				//this is showing that we used a number 
				number[x] = 0;
			}
		}
	}

	return;

}

int Chromosome::fitnessEval()
{
	int cdouble = 234;
    for (int j = 0; j < 9; j++)
    {
        int number[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 0; i < 9; ++i)
        {

            if (number[board[i][j] - 1] == board[i][j])
            {
                number[board[i][j] - 1] = 0;
            }
        }
        for (int y = 0; y < 9; ++y)
            {
                if (number[y] != 0)
                {
                    --cdouble;
                }
            }
    }

    //this is top left
    for (int i = 0; i < 3; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            int x = (i+1) % 3; 
            int y = (i+2) % 3;
         
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is top middle
    for (int i = 0; i < 3; ++i)
    {
        for (int k = 3; k < 6; ++k)
        {
            int x = (i+1) % 3; 
            int y = (i+2) % 3;
        
            for(int j = 3; j < 6; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is top right
    for (int i = 0; i < 3; ++i)
    {
        for (int k = 6; k < 9; ++k)
        {
            int x = (i+1) % 3; 
            int y = (i+2) % 3;
         
            for(int j = 6; j < 9; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is mid left
    for (int i = 3; i < 6; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            int x = ((i+1) % 3) +3; 
            int y = ((i+2) % 3)+3;
         
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is middle middle
    for (int i = 3; i < 6; ++i)
    {
        for (int k = 3; k < 6; ++k)
        {
            int x = ((i+1) % 3) +3; 
            int y = ((i+2) % 3)+3;
           
            for(int j = 3; j < 6; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is middle right
    for (int i = 3; i < 6; ++i)
    {
        for (int k = 6; k < 9; ++k)
        {
            int x = ((i+1) % 3) +3; 
            int y = ((i+2) % 3)+3;
          
            for(int j = 6; j < 9; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is bot left
    for (int i = 6; i < 9; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            int x = ((i+1) % 3) +6; 
            int y = ((i+2) % 3)+6;
           
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is bot middle
    for (int i = 6; i < 9; ++i)
    {
        for (int k = 3; k < 6; ++k)
        {
            int x = ((i+1) % 3) +6; 
            int y = ((i+2) % 3)+6;
        
            for(int j = 3; j < 6; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

    //this is bot right
    for (int i = 6; i < 9; ++i)
    {
        for (int k = 6; k < 9; ++k)
        {
            int x = ((i+1) % 3) +6; 
            int y = ((i+2) % 3)+6;
            
            for(int j = 6; j < 9; ++j)
            {
                if(board[i][k] == board[x][j])
                {
                    --cdouble;
                }
                if(board[i][k] == board[y][j])
                {
                    --cdouble;
                }
            }
        }
    }

	return cdouble;
}

int Chromosome::checkedAlready(int array [],int num)
{	
	for(int i=0;i<9;++i)
	{
		if(num==array[i])
			return 1;
		if(array[i]==0)
		{
			array[i]=num;
			return 0;
		}
	}
	return 0;

}
