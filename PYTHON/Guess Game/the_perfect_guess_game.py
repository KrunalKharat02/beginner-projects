import random

r = random.randint(1,50)
n = int(1)
guess = input("To start the game hit enter \n")
while (r!=guess) :
    guess = int(input("Guess number\n"))
    n += 1
    if (guess > r):
        print("Enter smaller number please")
    elif(guess < r):
        print("Enter larger number please")
    else:
        print("You guessed it correct")
        with open("hiscore.txt","r") as f:                                                                      
            hiscore = int(f.read())
        if(n<hiscore):
            with open("hiscore.txt","w") as f:
                f.write(str(n-1))
                print(f"Congrats on your new hiscore:{n-1} \nyour older hiscore was: {hiscore}\n")
        print(f"And you guessed it in {n-1} guesses")