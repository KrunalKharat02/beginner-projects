#Project tic tac toe
import copy

#BACKEND
xlist={}

newlist={'1':'  ','2':'  ','3':'  ','4':'  ','5':'  ','6':'  ','7':'  ','8':'  ','9':'  '}
def board(board):
    print(board['7'] + ' |' + board['8'] + ' |' + board['9'])
    print(' - + - + -')
    print(board['4'] + ' |' + board['5'] + ' |' + board['6'])
    print(' - + - + -')
    print(board['1'] + ' |' + board['2'] + ' |' + board['3'])


        


def game():
    turn=1
    board(xlist)

    while turn<=9:
        if turn%2==0:
            coin=' O'
        else:
            coin=' X'
        print('Where do you want to place',coin)
        inp=input('Enter position')
        if xlist[inp]== '  ':
            xlist[inp]=coin
            turn+=1
        else:
            print('position filled')
            
            continue


        if turn >= 6:
            if xlist['7'] == xlist['8'] == xlist['9'] != '  ': # across the top
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " + coin + " won. ****")                
                break
            elif xlist['4'] == xlist['5'] == xlist['6'] != '  ': # across the middle
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break
            elif xlist['1'] == xlist['2'] == xlist['3'] != '  ': # across the bottom
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break
            elif xlist['1'] == xlist['4'] == xlist['7'] != '  ': # down the left side
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break
            elif xlist['2'] == xlist['5'] == xlist['8'] != '  ': # down the middle
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break
            elif xlist['3'] == xlist['6'] == xlist['9'] != '  ': # down the right side
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break 
            elif xlist['7'] == xlist['5'] == xlist['3'] != '  ': # diagonal
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break
            elif xlist['1'] == xlist['5'] == xlist['9'] != '  ': # diagonal
                board(xlist)
                print("\nGame Over.\n")                
                print(" **** " +coin + " won. ****")
                break 
        board(xlist)
    
#TIE
        if turn>=10:
            board(xlist)
            #print('TIE! YOU BOTH SUCK LOL!!!')
            print('TIE!!')
            print('GAME OVER!')
            
            break

while True:
    a=input("Do you want to play? yes/no ")
    if a=='yes':
        xlist=copy.deepcopy(newlist)
        game()
    else:
        print('bye')
        break
    
