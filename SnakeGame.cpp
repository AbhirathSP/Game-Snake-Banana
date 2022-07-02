#include<iostream>
#include<conio.h>
using namespace std;
bool gameOver;
const int w = 20;
const int h = 20;
int a,b , E, F, score;
int tA[100], tB[100];
int nT;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
 
  gameOver = false;
  dir = STOP;
  a = w/2;
  b = h/2;
  E = rand() % w;
  F = rand() % h;
  score = 0;

}
void Draw()
{
  system("cls");
  for (int i =0 ; i<w; i++)
     cout<< "#";
  cout<<endl;

  for (int i =0 ; i<h; i++)
     {
        for (int j =0 ; j<w; j++)
        {
            if (j==0)
            {
                cout<<"#";

            }
            if (i == b && j ==a)
               cout << "0";
            else if (i == E && j== F )
               cout << "B";  
            else
            {
                bool print = false;
                for (int k=0; k<nT; k++)
                {
                   
                    if (tA[k] == j && tB[k]==i)
                    {
                        cout << "o";
                        print = true;
                    }
                    
                }
                if(!print)
                    cout<<" "; 
              
            }
               

            if (j == w-1)
              cout <<"#";
             
        }
        cout<< endl;
  
     }
  

 for (int i =0 ; i<w+2; i++)
     cout<< "#";
  cout<<endl;
  cout<< "Score:"<< score<< endl;
   
   
}
void Input ()
{
      if (_kbhit())
      {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
            break;
            case 'w':
                dir = UP;
            break;
            case 'd':
                dir = RIGHT;
            break;
            case 's':
                dir = DOWN;
            break;
           case 'a':
                gameOver = true;
            break;
            
       }
      }
}
void Logic()
{
    int pX = tA[0];
    int pY = tY[0];
    int p2X, p2Y;
    tA[0] = a;
    tB[0] = b;

    for(int i =1; i < nT; i++  )
    {
        p2X = tA[i];
        p2Y = tB[i];
        tA[i] = pX;
        tB[i] = pY;
        pX = p2X;
        pY = p2Y;
    }
   switch (dir)
   {
    case LEFT:
         a--;
        break;
    case RIGHT:
         a++;
         break;
    case UP:
         b--;
        break;
    case DOWN;
         b++;
        break;
       
    default:
        break;
   

   }
  // if(a >w || a<0|| b> h || b<0)
    // gameOver = true;
   if (a >= w) a = 0; else if (a<0)a = w -1;
   if (b >= h) b = 0; else if (b<0)b = h -1;
   
   for (int i = 0; i<nT ; i++)
      if(tA[i] == a && tB[i == b])
        gameOver = true;
   if( a==E && b ==F)
   {
    score += 10;
    E = rand() % w;
    F = rand() % h;
    nT++;
   }
}
int main ()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    return 0;
}