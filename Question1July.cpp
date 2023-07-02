#include<iostream>

/// Node Class is a Custom Data Type with Data and Pointer to Next Data of Same DType

    template <class Node_DType>
    class Node{
        public:
            Node_DType Data;
            Node<Node_DType> *Next = NULL;
    };


/// Singly Linked List Class and Operations

    template <class List_DType>
    class LinkedList{
        private:

            /// Private Variables

                Node <List_DType> *Root = NULL;
                int ListSize = NULL;

        public:
            /// Constructor

                LinkedList(List_DType *Array, int ArrSize){
                    ListSize = ArrSize;
                    CreateLinkedList(Array);
                }

            /// Operations Prototypes

                void CreateLinkedList(List_DType *Array, Node<List_DType> *Prev=NULL, int Index=0);
                void Insertion(List_DType Value, int Index, Node<List_DType> *Traverse=NULL);
                void Deletion(int Index, Node<List_DType> *Traverse=NULL);
                void IsPresent(List_DType Value, bool ifFound=false, Node<List_DType> *Traverse=NULL, bool SwitchOnLocation=false, int SwitchIndex=0);
                void Location(List_DType Value);
                void Display(Node<List_DType> *Head=NULL, bool Tab=true);
    };

/// Operations Logic Implementation


    /// CreateLinkedList Function Would Create a Linked List Based on Values Provided !!
    /// This is a Recursive Function

        template <class List_DType>
        void LinkedList<List_DType>::CreateLinkedList(List_DType *Array, Node<List_DType> *Prev, int Index){
            Node<List_DType> *NewNode = new Node<List_DType>;

            if(Prev != NULL){Prev->Next = NewNode;}
            else{Root = NewNode;}

            NewNode->Data = *(Array+Index);
            if(Index+1 != ListSize){
                CreateLinkedList(Array, NewNode, Index+1);
            }
        }

    /// Insertion Function to Insert Values at Discrete Indexes. This is a Recursive Function

        template <class List_DType>
        void LinkedList<List_DType>::Insertion(List_DType Value, int Index, Node<List_DType> *Traverse){
            if(Traverse == NULL){
                Insertion(Value, Index, Root);
                ListSize++;
                if(Index >= 0 && Index <= ListSize){
                    std::cout<<"\t Node With Value :- "<<Value<<" Has Been Inserted At Index "<<Index<<" Successfully :)) \n\t\t The Updated ";
                    Display(NULL, false);
                }
            }

            else{
                if(Index-1 >= 1 && Index <= ListSize){
                    Insertion(Value, Index-1, Traverse->Next);
                }

                else{
                    if(Index >= 0 && Index <= ListSize){
                        Node<List_DType> *NewNode = new Node<List_DType>;
                        NewNode->Data = Value;

                        if(Index == 0){
                            NewNode->Next = Root;
                            Root = NewNode;
                        }

                        else{
                            Node<List_DType> *Temp = Traverse->Next;
                            Traverse->Next = NewNode;
                            NewNode->Next = Temp;
                        }
                    }

                    else{
                        std::cout<<"\t Value Insertion Not Possible :(( \n"<<std::endl;
                        ListSize--;
                    }
                }
            }
        }

    /// Deletion Function to Delete Nodes at Discrete Indexes. This is a Recursive Function

        template <class List_DType>
        void LinkedList<List_DType>::Deletion(int Index, Node<List_DType> *Traverse){
            if(Traverse == NULL){
                Deletion(Index, Root);
                ListSize--;
                if(Index >= 0 && Index <= ListSize){
                    std::cout<<"\t Node At Index "<<Index<<" Has Been Deleted Successfully :)) \n\t\t The Updated ";
                    Display(NULL, false);
                }
            }

            else{
                if(Index-1 >= 1 && Index < ListSize){
                    Deletion(Index-1, Traverse->Next);
                }
                else{
                    if(Index >= 0 && Index < ListSize){
                        if(Index == 0)
                        {
                            if(ListSize != 1)
                            {
                                Node<List_DType> *temp = Root;
                                Root = Root->Next;
                                delete temp;

                            } else{Root = NULL;}
                        }

                        else{
                            Node<List_DType> *Temp = Traverse->Next;
                            Traverse->Next = Traverse->Next->Next;
                            delete Temp;
                        }
                    }

                    else{
                        std::cout<<"\t Node Deletion Not Possible as Node Doesn't Even Exist :(( \n"<<std::endl;
                        ListSize++;
                    }
                }
            }
        }

    /// IsPresent Function Would Check Whether the Value is Present in the Linked-List Or Not. This Function Follows Recursion.

        template <class List_DType>
        void LinkedList<List_DType>::IsPresent(List_DType Value, bool ifFound, Node<List_DType> *Traverse, bool SwitchOnLocation, int SwitchIndex){
            if(Traverse == NULL){
                IsPresent(Value, ifFound, Root, SwitchOnLocation, SwitchIndex);
            }

            else{
                if(ifFound != true){
                    if(Traverse->Data == Value){IsPresent(Value, true, Traverse, SwitchOnLocation, SwitchIndex);}
                    else{
                        if(Traverse->Next != NULL){IsPresent(Value, ifFound, Traverse->Next, SwitchOnLocation, SwitchIndex+1);}
                        else{std::cout<<"\t Unfortunately, Node with Value "<<Value<<" Not Found :(( \n"<<std::endl;}
                    }

                }
                else{
                    if(SwitchOnLocation == true){std::cout<<"\t Node of "<<Value<<" is Present at Index :- "<<SwitchIndex<<std::endl<<std::endl;}
                    else{std::cout<<"\t Congrats, The Node with Value "<<Value<<" is Available in the Linked List :)) \n"<<std::endl;}

                }
            }
        }

    /// The Location Function Would Tell You the Index Location of the Node If Present, With Value Provided.

        template <class List_DType>
        void LinkedList<List_DType>::Location(List_DType Value){
            IsPresent(Value, false, NULL, true);
        }

    /// Display Function will Display All the Values of the Linked-List Provided. This Function Follows Recursion.

        template <class List_DType>
        void LinkedList<List_DType>::Display(Node<List_DType> *Traverse, bool Tab){
            if(Root != NULL){
                if(Traverse == NULL){
                    if(Tab == true){std::cout<<"\t The ";}
                    std::cout<<"Linked-List Looks Like :-- \n\t\t";
                    Display(Root);
                    std::cout<<std::endl<<std::endl;
                }
                else{
                    std::cout<<Traverse->Data<<" ";
                    if(Traverse->Next != NULL){
                        Display(Traverse->Next);
                    }
                }
            }
        }

int main(){

    /// Creating a Linked-List of Integer Data-Type

        std::cout<<"\n\n Running Operations on Linked-List of Integer Data-Type :)) \n"<<std::endl;

        int Array[] = {11, 22, 33, 44, 55 ,66 ,77 ,88 ,99 ,110};
        int ArrSize_ = sizeof(Array)/sizeof(Array[0]);

        LinkedList<int> LL1(Array, ArrSize_);

        LL1.Display();

    /// Performing Operations

            LL1.Insertion(3000, 0);
            LL1.Insertion(900, 11);

            LL1.Deletion(100);
            LL1.Deletion(0);

            LL1.IsPresent(3000);
            LL1.IsPresent(22);

            LL1.Location(3000);
            LL1.Location(223);

            LL1.Display();





        std::cout<<"\n\n Now Running Operations on New Linked-List of String Data-Type :)) \n"<<std::endl;

    /// Creating a Linked-List of String Data-Type

        std::string StrArray[] = {"Ashish", "Rajendra", "Poonam", "Ankit", "Nitin"};
        int StrArrSize_ = sizeof(StrArray)/sizeof(StrArray[0]);

        LinkedList<std::string> LL2(StrArray, StrArrSize_);

        LL2.Display();

    /// Performing Operations

            LL2.Insertion("Nazar", 9);
            LL2.Insertion("SeaWall", 2);

            LL2.Deletion(3);
            LL2.Deletion(2);

            LL2.Display();




    return 0;
}
