# Guess the Number

import random

Hidden_Number = int(random.random()*10000)

print("You Have 20 attempts to Guess the Number")
print("Guess the Number between 0 to 10000 ")

User_Ask = "YES"

while User_Ask in "YESYEsYesyesyESyEsyeSYeS":
    Count = 20
    Is_Find = False
    while Count >= 0:
        User_Ask = int(input("\t\t\t Enter the Number Here :-- "))
        print(f"\n \t \t You have {Count} Attempts Left to Guess the Number...")
        if(User_Ask > Hidden_Number+100):
            print("\t \t You have entered a larger number \n \t \t Please Enter Smaller Number  \n")

        elif(User_Ask > Hidden_Number):
            print("\t \t You have entered a little larger number \n \t \t Please Enter Little Smaller Number  \n")

        elif(User_Ask < Hidden_Number-100):
            print("\t \t You have entered a smaller number \n \t \t Please Enter Larger Number \n")

        elif(User_Ask < Hidden_Number):
            print("\t \t You have entered a little smaller number \n \t \t Please Enter Little Larger Number  \n")

        elif(User_Ask == Hidden_Number):
            print(f"--------Congrats You Have Guessed The Number. The Number is {Hidden_Number}---------")
            Is_Find = True
            Count = 0

        Count -= 1

    if(Is_Find == False):
        print(f"The Number was {Hidden_Number} ")
        print("Try Again Later :)) ")

    User_Ask = input("Do you want to try again :-- ")
    while (User_Ask not in "YESYEsYesyesyESyEsyeSYeSNONonOno"):
        print("Please Input Either Yes/No")
        User_Ask = input("Do you want to try again :-- ")


print("Thank You :)) ")
exit(0)
