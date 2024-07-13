#include<iostream>
using namespace std;

//this function is used to display the star 
//--after every move call this function to display the star

//--globle variable to save the available slot's index

int availablePlace = 0;
void Display_Star(string arr[])
{
	cout<<"\n\t\t     "<<arr[0];
	cout<<"\n\n\t"<<arr[1];
	cout<<"\t"<<arr[2];
	cout<<"\t  "<<arr[3];
	cout<<"\t"<<arr[4]<<endl<<endl;
	cout<<"\t      "<<arr[5];
	cout<<"\t    "<<arr[6]<<endl<<endl;
	cout<<"\t    "<<arr[7];
	cout<<"\t\t      "<<arr[8];
}

bool moveIsValid(string arr[], int index)
{

	//rules:
//		From 0 you can move to 2, 3 (not possible in intial state)
//		From 1 you can move to: 2 and 5
//		From 2 you can move to: 0, 3, 5
//		From 3 you can move to 0, 2, 4, 6
//		From 4 you can move to 3,6
//		From 5 you can move to 1, 2, 7, 8
//		From 6 you can move to 2, 4, 7, 8
//		From 7 you can move to 5, 6
//		From 8 you can move to 5, 6
	
	if(index == 0)
	{
		if(arr[2] == "f ")
		{
			availablePlace = 2;
			return true;
		} else if (arr[3] == "f ")
		{
			availablePlace = 3;
			return true;
		}
		
	} else if(index == 1)
	{
			if(arr[2] == "f ")
		{
			availablePlace = 2;
			return true;
		} else if (arr[5] == "f ")
		{
			availablePlace = 5;
			return true;
		}
		
	} else 	if(index == 2)
	{
			if(arr[0] == "f ")
		{
			availablePlace = 0;
			return true;
		} else	if(arr[1] == "f ")
		{
			availablePlace = 1;
			return true;
		} 
		
		else if (arr[3] == "f ")
		{
			availablePlace = 3;
			return true;
		}
		else if (arr[5] == "f ")
		{
			availablePlace = 5;
			return true;
		}
		
	} else if(index == 3)
	{
		
			if(arr[0] == "f ")
		{
			availablePlace = 0;
			return true;
		} else if (arr[2] == "f ")
		{
			availablePlace = 2;
			return true;
		}
		else if(arr[4] == "f ")
		{
			availablePlace = 4;
			return true;
		} else if (arr[6] == "f ")
		{
			availablePlace = 6;
			return true;
		}
		
	} else 	if(index == 4)
	{
			if(arr[6] == "f ")
		{
			availablePlace = 6;
			return true;
		} else if (arr[3] == "f ")
		{
			availablePlace = 3;
			return true;
		}
		
	} else if(index == 5)
	{
			if(arr[2] == "f ")
		{
			availablePlace = 2;
			return true;
		} else if (arr[1] == "f ")
		{
			availablePlace = 1;
			return true;
		} else 
			if(arr[7] == "f ")
		{
			availablePlace = 7;
			return true;
		} else if (arr[8] == "f ")
		{
			availablePlace = 8;
			return true;
		}
		
	} else 	if(index == 6)
	{
		if(arr[2] == "f ")
		{
			availablePlace = 2;
			return true;
		} else if (arr[4] == "f ")
		{
			availablePlace = 4;
			return true;
		} else 
			if(arr[7] == "f ")
		{
			availablePlace = 7;
			return true;
		} else if (arr[8] == "f ")
		{
			availablePlace = 8;
			return true;
		}
		
	} else if(index == 7 || index == 8)
	{
			if(arr[5] == "f ")
		{
			availablePlace = 5;
			return true;
		} else if (arr[6] == "f ")
		{
			availablePlace = 6;
			return true;
		}
		
		return false;
	} 
}

void checkWin(string arr[])
{
	if( (arr[1] == "y1" || arr[1]== "y2" || arr[1] == "y3" || arr[1] =="y4") && (arr[2] == "y1" || arr[2]== "y2" || arr[2] == "y3" || arr[2] =="y4") && (arr[5] == "y1" || arr[5]== "y2" || arr[5] == "y3" || arr[5] =="y4") && (arr[7] == "y1" || arr[7]== "y2" || arr[7] == "y3" || arr[7] =="y4") && (arr[3] == "r1" || arr[3]== "r2" || arr[3] == "r3" || arr[3] =="r4") && (arr[4] == "r1" || arr[4]== "r2" || arr[4] == "r3" || arr[4] =="r4")  && (arr[6] == "r1" || arr[6]== "r2" || arr[6] == "r3" || arr[6] =="r4") && (arr[8] == "r1" || arr[8]== "r2" || arr[8] == "r3" || arr[8] =="r4") )

	   {
	   	char play;
	   	cout<<"\nYou Won the Game!";
	   	exit(0);
	   } 
	   
} 
void playGame(string star[])
{
	int moves; // variable to record user move
	string select_color; //variable to move a number on star
	Display_Star(star);
	select_move:
	cout<<"\nEnter number to move ";
	cin>>select_color;
	cout<<select_color;
	
	int index;//--variable to store the selected index
	//--loop to find out the index of selected color
	for(int i = 0; i<9; i++)
	{
		if(select_color == star[i])
		{
			index = i;
			break;
		}
		else continue;
	} 
	
	if(moveIsValid(star, index))
	{
	  swap(star[index], star[availablePlace]);
	  system("cls");
	  cout<<"\from Index: "<< index <<" it moved to: "<<availablePlace;
	  Display_Star(star);
	  checkWin(star);
	  goto select_move;
	} else {
		cout<<"\nPlease Select a Valid Color!";
		goto select_move;
	}
	
	
}


void menu() 
{
	cout<<"\tPu Wiang";
	cout<<"\n[1] Play\n[2] What to do?\n[3] Exit";
}


void howToPlay()
{
	cout<<"\nAll you need to do is to exchange  r's  with  y's position in minimum moves";
}
int main()
{
	//Variables & Array
	int choice;
	
	string star[9] =  {"f ", "r1", "r2", "y1", "y2", "r3" , "y3", "r4", "y4"};
	//here 0 represents free,
	// 1 represents red
	//2 represents yellow
	
	menu();
	cout<<"\nEnter Your choice: ";
	cin>>choice;
	if(choice == 1) 
	{
		playGame(star);
		
	} else if( choice == 2){
		
		howToPlay();
	}
	else if (choice == 3)
	{
		exit(0);
	}

	
		
	return 0;
}
