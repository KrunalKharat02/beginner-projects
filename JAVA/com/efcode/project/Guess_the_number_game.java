package com.efcode.project;

import java.util.*;


class game
{
    private int n;
    private int guess;
    private int numberOfGuesses;
    game()
    {
        numberOfGuesses=0;
      Random r=new Random();
      n=r.nextInt(101);

    }
    void guess()
    {
        System.out.println("Guess a number between 0 and 100 : ");
        Scanner sc=new Scanner(System.in);
         guess=sc.nextInt();


    }
    void isCompare()
    {
        while(true)
        {
            guess();
            if(guess==n)
            {
                System.out.println("Bull's eye that's a match .");
                System.out.println("Number of guesses required "+numberOfGuesses);
                break;


            }
            else if(guess>n)
            {
                System.out.println("Number is larger ");
                numberOfGuesses++;

            }
            else
            {
                System.out.println("Number is smaller ");
                numberOfGuesses++;
            }
        }
    }


}
public class Guess_the_number_game{

    public static void main(String[] args) {
game player=new game();
player.isCompare();


    }
}
