#include<iostream>
using namespace std;


class PuzzleClass{
	 public: void startGame() {  
     

    int i,j,n=1,t,p,m,x,y;
    int ara[3][3]={8,2,6,5,3,4,1,7,0};
    for(i=0;i<3;i++){
            cout<<"\t";
        for(j=0;j<3;j++){
                cout<<ara[i][j]<<"  ";
                if(ara[i][j]==0){
                    x=i;
                    y=j;
                }
        }
        cout<<endl;
    }
    cout<<endl;

    while(true){

        //cout<<x<<' '<<y;
        cout<<"\tInsert number for replace : ";
        cin>>p;
        
        if(!cin){
            cout<<"\n\n\tYou can insert only one digit!!!\n\n";
            cin.clear();
            break;
            
   }else {
	  
        	 m=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(p==ara[i][j]){
                        if(ara[i][j+1]==0 || ara[i][j-1]==0 || ara[i+1][j]==0 || ara[i-1][j]==0){
                            ara[x][y]=p;
                            ara[i][j]=0;
                            x=i;
                            y=j;
                            m=1;
                            break;
                        }
                        else{
                            m=1;
                            cout<<"\n\n\tInvalid Move!!!\n\n";
                            break;
                        }
                }
            }
            if(m==1) break;
        }
         for(i=0;i<3;i++){
                cout<<"\t";
            for(j=0;j<3;j++){
                 cout<<ara[i][j]<<"  ";
                    }
                cout<<endl;
            }
		}
	}
        
}

    
};

class Instruction{
	public:
		void showInstruction(){
			cout<<"\t\t *****Instructions*****\n"<<endl;
			cout<<"1)Zero '0' indicates the free Space"<<endl;
			cout<<"2)Select any number where you place free space "<<endl;
			cout<<"3)It gives error if you select any invalid choice "<<endl;
		}
};

class WelcomeClass{
	public : void showMenu(){
			int choice = -1;
	
	
	cout<<"\n\n\n\t\t  ##### Welcome to Puzzle Game #####\n\n";
	cout << "Select any Option\n\n";
	cout << "Press 1. for Start Game\n";
	cout << "Press 2. for Instructions\n";
	cout << "Press 3. for Exit Game\n";
	cin >> choice;
	  
	  
	  switch(choice){
	  	case 1:
	  		PuzzleClass puzzleClassObj;   
            puzzleClassObj.startGame();  
          
            break;
            
        case 2:
        	Instruction readme;
        	readme.showInstruction();
        
        break;
        
        case 3:
        	break;
	  }
	}
};

int main()
{

    	WelcomeClass welcomeClassObj;   
        welcomeClassObj.showMenu(); 
}
