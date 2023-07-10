#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Tretris{
    private:
        // Variables/Constants
            int Initial = 1, End = 3, Y_Axis = 17, C_Board_Length = 25, C_Board_Breadth = 20;
            char Tretris_Board[25][20], Mode = 'V';
            HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

        // Private Functions Prototypes
            void C_Board();
            void C_Element();
            void Remove();
            void Fix();
            bool IsPlacable(string);
            void Controls();
            void Show_Result();

    public:
        // Public Functions Prototypes
            void Play();
};

// Private Functions Implementation

    void Tretris:: C_Board(){
        for(int i=0; i<C_Board_Length; i++){
            for(int j=0; j<C_Board_Breadth; j++){
                if(j == 1 || j == C_Board_Breadth-1 || (i == C_Board_Length-1 && j > 0)){
                    Tretris_Board[i][j] = '#';
                }
                else{Tretris_Board[i][j] = ' ';}
            }
        }
    }

    void Tretris:: C_Element(){
        FlushConsoleInputBuffer(hStdIn);
        for(int i=Initial; i<=End; i++){
            if(Mode == 'V'){Tretris_Board[i][Y_Axis] = 'A';}
            else if(Mode == 'H'){Tretris_Board[Y_Axis][i] = 'A';}
        }
        system("CLS");
        Show_Result();
        Controls();
        Sleep(10);
        C_Element();
    }

    void Tretris:: Remove(){
        for(int i=Initial; i<=End; i++){
            if(Mode == 'V'){Tretris_Board[i][Y_Axis] = ' ';}
            else if(Mode == 'H'){Tretris_Board[Y_Axis][i] = ' ';}
        }
    }

    void Tretris:: Fix(){
        Initial = 1; End = 3, Y_Axis = 17;
        Mode = 'V';
    }

    bool Tretris:: IsPlacable(string Act){
        if(Act == "Down"){
            if(Mode == 'V' && Tretris_Board[End+1][Y_Axis] == ' '){Remove(); Initial++; End++;}
            else if(Mode == 'H'){
                for(int i=Initial; i<=End; i++){
                    if(Tretris_Board[Y_Axis+1][i] != ' '){Fix(); return false;}
                }
                Remove();
                Y_Axis++;
            }
            else{Fix();}
        }

        else if(Act == "Up"){
            if(Mode == 'V' && Tretris_Board[Initial-1][Y_Axis] == ' ' && Initial-1 > 0){Remove(); Initial--; End--;}
            else if(Mode == 'H' && Y_Axis-1 > 0){
                for(int i=Initial; i<=End; i++){
                    if(Tretris_Board[Y_Axis-1][i] != ' '){Fix(); return false;}
                }
                Remove();
                Y_Axis--;
            }
            else{Fix();}
        }

        else if(Act == "Left"){
            if(Mode == 'V'){
                for(int i=Initial; i<=End; i++){
                    if(Tretris_Board[i][Y_Axis-1] != ' '){return false;}
                }
                Remove();
                Y_Axis--;
            }
            else if(Mode == 'H'){
                for(int i=Initial; i<=End; i++){
                    if(Tretris_Board[Y_Axis][Initial-1] != ' '){return false;}
                }
                Remove();
                Initial--; End--;
            }
        }

        else if(Act == "Right"){
            if(Mode == 'V'){
                for(int i=Initial; i<=End; i++){
                    if(Tretris_Board[i][Y_Axis+1] != ' '){return false;}
                }
                Remove();
                Y_Axis++;
            }
            else if(Mode == 'H'){
                for(int i=Initial; i<=End; i++){
                    if(Tretris_Board[Y_Axis][End+1] != ' '){return false;}
                }
                Remove();
                Initial++; End++;
            }
        }

        else if(Act == "Rotate"){
            Remove();
            if(Mode == 'V'){
                Mode = 'H';
                if(Y_Axis-3 > 0){
                    End = Y_Axis;
                    Y_Axis = Initial;
                    Initial = End - 2;
                }
                else{
                    Y_Axis = Initial;
                    End = Y_Axis + 2;
                }
            }
            else{ Mode = 'V';
                if(Y_Axis+2 < C_Board_Length-1){
                    for(int i=Y_Axis; i<=Y_Axis+2; i++){
                        if(Tretris_Board[i][End] != ' '){Mode = 'H'; return false;}
                    }
                    Initial = Y_Axis;
                    Y_Axis = End;
                    End = Initial+2;
                }

                else{
                    for(int i=Y_Axis-2; i<=Y_Axis; i++){
                        if(Tretris_Board[i][End] != ' '){Mode = 'H'; return false;}
                    }
                    Initial = Y_Axis-2;
                    Y_Axis = End;
                    End = Initial + 2;
                }
            }
        }
    }

    void Tretris:: Controls(){
        while(!kbhit()){}
        if(GetAsyncKeyState(VK_DOWN)){
            IsPlacable("Down");
        }

        else if(GetAsyncKeyState(VK_UP)){
            IsPlacable("Up");
        }

        else if(GetAsyncKeyState(VK_LEFT)){
            IsPlacable("Left");
        }

        else if(GetAsyncKeyState(VK_RIGHT)){
            IsPlacable("Right");
        }

        else if(GetAsyncKeyState(0x52)){
            cout<<"Yes"<<endl;
            IsPlacable("Rotate");
        }
    }

    void Tretris:: Show_Result(){
        for(int i=0; i<C_Board_Length; i++){
            for(int j=0; j<C_Board_Breadth; j++){
                cout<<Tretris_Board[i][j];
            }
            cout<<endl;
        }
    }

// Public Functions Implementation

    void Tretris:: Play(){
        C_Board();
        C_Element();
    }

int main()
{
    Tretris Ashish;
    Ashish.Play();
    return 0;
}












