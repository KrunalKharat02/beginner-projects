package com.IIITG_PRIYANSHU;
import java.util.*;
class BOOK {
    private int bookId;
    private String bookTitle;
    private int yearOfPublication;
    private String authorName;
    private String publisherName;
    private int numberOfAvailableCopies;
    private int totalCopies;

    BOOK() {
        bookId = 100;
        bookTitle = "ABC";
        yearOfPublication = 1987;
        authorName = "XYZ";
        publisherName = "POW";
        numberOfAvailableCopies = 100;
        totalCopies = 1000;
    }

    BOOK(int total) {
        bookId = 100;
        bookTitle = "ABC";
        yearOfPublication = 1987;
        authorName = "XYZ";
        publisherName = "POW";
        numberOfAvailableCopies = 100;
        totalCopies = total;
    }

    void setDetails() {
        bookId = 100;
        bookTitle = "ABC";
        yearOfPublication = 1987;
        authorName = "XYZ";
        publisherName = "POW";
        numberOfAvailableCopies = 100;
        totalCopies = 1000;
    }

    void setDetails(int id, String title, int year, String author, String publisher, int count,int total) {
        bookId = id;
        bookTitle = title;
        yearOfPublication = year;
        authorName = author;
        publisherName = publisher;
        numberOfAvailableCopies = count;
        totalCopies=total;



    }

    void getDetails() {
        System.out.println("BookId="+bookId);
        System.out.println("BookTitle="+bookTitle);
        System.out.println("Year of Publication="+yearOfPublication);
        System.out.println("Author Name="+authorName);
        System.out.println("Publisher name="+publisherName);
        System.out.println("Number Of available Copies="+numberOfAvailableCopies);
        System.out.println("Number of total Copies="+totalCopies);

    }
int bookID()
{
    return bookId;
}

    boolean issue() {
        if(numberOfAvailableCopies>0)
        {
            numberOfAvailableCopies--;
            return true;
        }
        else
            return false;



    }
void returnBook()
    {
        numberOfAvailableCopies++;

    }



}
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number of Books :");
        int n = input.nextInt();
        BOOK[] b = new BOOK[n];


        int i = 0;
        while (i < n) {
            b[i] = new BOOK();

            System.out.println("Enter the  details of the BOOK " + (i + 1));
            {
                System.out.println("Enter Book Id: ");
                int bookId = input.nextInt();
                System.out.println("Enter Book Title: ");
                input.nextLine();
                String bookTitle = input.nextLine();


                System.out.println("Enter Year of Publication: ");
                int yearOfPublication = input.nextInt();
                System.out.println("Enter Author Name: ");
                input.nextLine();
                String authorName = input.nextLine();

                System.out.println("Enter Publisher Name: ");

                String publisherName = input.nextLine();


                System.out.println("Enter Number of Available copies: ");
                int numberOfAvailableCopies = input.nextInt();
                System.out.println("Enter total copies: ");
                int totalCopies = input.nextInt();
                b[i].setDetails(bookId, bookTitle, yearOfPublication, authorName, publisherName, numberOfAvailableCopies, totalCopies);


            }
            i++;
            System.out.println("------------------------------------------");


        }
        while (true) {
            System.out.println("Enter 1 for issuing a book/ 2 for getting the details of the book/3 for returning the book /4 for exit :");
            int inp = input.nextInt();
            if(inp==4)
                break;
            else if(inp==3)
            {
                System.out.println("Enter the book Id that you want to return :");
                int id= input.nextInt();
                for(int l=0;l<n;l++)
                {
                    if(b[l].bookID()==id)
                    {
                        b[l].returnBook();
                    }
                }
            }
          else  if (inp == 1) {

                System.out.println("Enter the book ID that you want to issue:");
                int id = input.nextInt();
                for (int k = 0; k < n; k++) {
                    if (b[k].bookID() == id) {
                        if (b[k].issue())
                            System.out.println("THis book has been issued .");
                        else
                            System.out.println("This book can't be issued");


                    }
                }

            } else {
                while (true) {

                    System.out.println("Enter the Book Id whose details you want to know or else press 0 to exit");
                    int id = input.nextInt();
                    if (id == 0)
                        break;
                    else {
                        int c=0;
                        for (int j = 0; j < n; j++) {
                            if (b[j].bookID() == id) {
                                b[j].getDetails();
                                c++;

                                break;

                            }
                        }
                        if(c==0)
                        {
                            System.out.println("THis Book Id is Invalid");
                        }

                    }


                }
            }
        }
    }
}
