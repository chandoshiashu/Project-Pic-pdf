#include<iostream>
#define Size 10

using namespace std;

class Node{
    public:
        int Data;
        Node *Next = NULL;
};


// Singly Linked List
class LinkedList{
    private:
        Node *Root = NULL;
        int ListSize = Size;

    public:
        void CreateLinkedList(int Array[Size], Node *Prev=NULL, int Index=0);
        void Insertion(int Value, int Index, Node *Traverse=NULL);
        void Deletion(int Index, Node *Traverse=NULL);
        void IsPresent(int Value, bool ifFound=false, Node *Traverse=NULL, bool SwitchOnLocation=false, int SwitchIndex=0);
        void Location(int Value, Node *Traverse=NULL);
        void Display(Node *Head=NULL);
};

void LinkedList::CreateLinkedList(int Array[Size], Node *Prev, int Index){
    Node *NewNode = new Node;

    if(Prev != NULL){Prev->Next = NewNode;}
    else{Root = NewNode;}

    NewNode->Data = Array[Index];
    if(Index+1 != 10){
        CreateLinkedList(Array, NewNode, Index+1);
    }
}

void LinkedList::Insertion(int Value, int Index, Node *Traverse){
    if(Traverse == NULL){Insertion(Value, Index, Root); ListSize++;}
    else{
        if(Index-1 >= 1 && Index <= ListSize){
            Insertion(Value, Index-1, Traverse->Next);
        }
        else{
            if(Index >= 0 && Index <= ListSize){
                Node *NewNode = new Node;
                NewNode->Data = Value;

                if(Index == 0){NewNode->Next = Root; Root = NewNode;}
                else{
                    Node *Temp = Traverse->Next;
                    Traverse->Next = NewNode;
                    NewNode->Next = Temp;
                }
            }

            else{
                cout<<"Value Insertion Not Possible !!!"<<endl;
            }
        }
    }
}

void LinkedList::Deletion(int Index, Node *Traverse){
    if(Traverse == NULL){Deletion(Index, Root); ListSize--;}
    else{
        if(Index-1 >= 1 && Index < ListSize){
            Deletion(Index-1, Traverse->Next);
        }
        else{
            if(Index >= 0 && Index < ListSize){
                if(Index == 0){if(ListSize != 1){Root = Root->Next;} else{Root = NULL;}}
                else{
                    Node *Temp = Traverse->Next;
                    Traverse->Next = Traverse->Next->Next;
                    Temp->Next = NULL;
                }
            }

            else{
                cout<<"Value Deletion Not Possible !!!"<<endl;
            }
        }
    }
}

void LinkedList::IsPresent(int Value, bool ifFound, Node *Traverse, bool SwitchOnLocation, int SwitchIndex){
    if(Traverse == NULL){IsPresent(Value, ifFound, Root, SwitchOnLocation, SwitchIndex);}
    else{
        if(ifFound != true){
            if(Traverse->Data == Value){IsPresent(Value, true, Traverse, SwitchOnLocation, SwitchIndex);}
            else{
                if(Traverse->Next != NULL){IsPresent(Value, ifFound, Traverse->Next, SwitchOnLocation, SwitchIndex+1);}
                else{cout<<"Unfortunately !!!  Node with Value "<<Value<<" Not Found !!!"<<endl;}
            }

        }
        else{
            if(SwitchOnLocation == true){cout<<"Node of "<<Value<<" is Present at Index :- "<<SwitchIndex<<endl;}
            else{cout<<"Congrats !! The Node with Value "<<Value<<" is Available in the Linked List !!!"<<endl;}

        }
    }
}

void LinkedList::Location(int Value, Node *Traverse){
    IsPresent(Value, false, NULL, true);
}

void LinkedList::Display(Node *Traverse){
    if(Root != NULL){
        if(Traverse == NULL){Display(Root); cout<<endl;}
        else{
            cout<<Traverse->Data<<" ";
            if(Traverse->Next != NULL){Display(Traverse->Next);}
        }
    }
}

int main(){

    int Array[Size] = {11, 22, 33, 44, 55 ,66 ,77 ,88 ,99 ,110};
    LinkedList LL1;
    LL1.CreateLinkedList(Array);

    LL1.Insertion(3000, 1);
    LL1.Insertion(472, 6);
    LL1.Insertion(128, 3);
    LL1.Insertion(900, 11);
    LL1.Display();

    LL1.Deletion(3);
    LL1.Deletion(3);
    LL1.Deletion(0);
    LL1.Display();

    LL1.IsPresent(3000);
    LL1.IsPresent(22);
    LL1.IsPresent(266);
    LL1.IsPresent(11);

    LL1.Location(3000);
    LL1.Location(223);
    LL1.Location(110);

    return 0;
}


/// 3000 22 44 55 472 66 77 88 900 99 110










