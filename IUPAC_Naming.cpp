#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class Link_Node{
    string Prefix = "NULL";
    Link_Node *Next_Node = NULL;
    friend class Naming;
};

class Naming{
    private:
        Link_Node *Node_Traverser = NULL;
        Link_Node *Root_Node = NULL;
        Link_Node *New_Node = NULL;

        string Name = "";

        void Create_Linked_List(){
            string Dict[] = {"nil", "un", "bi", "tri", "quad", "pent", "hex", "sept", "oct", "enn"};
            int Dict_Size = sizeof(Dict)/32;

            for(int i = 0; i < Dict_Size; i++){
                New_Node = new Link_Node;
                New_Node->Prefix = Dict[i];

                if(Node_Traverser != NULL){
                    Node_Traverser->Next_Node = New_Node;
                    Node_Traverser = New_Node;
                }
                else{
                    Node_Traverser = New_Node; Root_Node = New_Node;
                }

            }
        }

        void Access_Node(int Index=0, Link_Node *Accessor=NULL){
            if(Accessor == NULL){Access_Node(Index, Root_Node); return;}
            if(Index != 0){
                Access_Node(Index-1, Accessor->Next_Node);
            } else{Name += Accessor->Prefix;}
        }

        int DigitCount(unsigned int Value){
            int Count = 1;
            while((Value/(unsigned int)(pow(10, Count))) != 0){
                //cout<<(Value/(unsigned int)(pow(10, Count)))<<endl;
                Count++;
            }
            return Count;
        }

        void Display_Private_List(){
            Node_Traverser = Root_Node;
            while(Node_Traverser->Next_Node != NULL){
                cout<<Node_Traverser->Prefix<<endl;
                Node_Traverser = Node_Traverser->Next_Node;
            }
        }

    public:
        string IUPAC(unsigned int Value){
            DigitCount(Value);
            Name = "";
            Create_Linked_List();
            unsigned int Temp = Value;

            for(int i=DigitCount(Value); i>0; i--){
                Access_Node(int(Temp%(unsigned int)(pow(10, i))/(unsigned int)(pow(10, i-1))));
                //cout<<Name<<endl;
                Temp = Temp%((unsigned int)(pow(10, i-1)));
            }

            if(Value%10 == 2 || Value%10 == 3){
                Name += "um";
            }
//            else if(Value%10 == 0){
//                Name += "lium";
//            }
            else{Name += "ium";}

            return Name;

        }
};

int main(){


    Naming N1;
    unsigned int User_Inp = 1;

    while(User_Inp != 2){
        if(User_Inp == 1){
            cout<<"\n\t\t Enter the Numeric Value :-- ";
            cin>>User_Inp;

            cout<<"\t\t\t The IUPAC is :-- "<<N1.IUPAC(User_Inp)<<endl;
        }
        else if(User_Inp != 1 && User_Inp != 2){cout<<"\n\t\t Invalid Input :(( \n\t\t Please Re-Enter Either 1 or 2\n";}
        cout<<"\n\t\t\t\t To reuse the program, Press 1 \n\t\t\t\t To Exit, Press 2\n\t\t\t\t\t:--- ";
        cin>>User_Inp;
    }

    return 0;
}

