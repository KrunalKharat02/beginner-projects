package com.IIITG_PRIYANSHU;
import java.util.*;

class Account
{
    Scanner input=new Scanner(System.in);

  int  accountNumber ;

String accountType;
    String serviceBranchIFSC;
float minimumBalance;
    float availableBalance;
int customerID;
String customerName;
static int totalAccountCreated;
Account()
{
    accountNumber=0;
    serviceBranchIFSC="NULL";
    minimumBalance=0;
    availableBalance=0;
    customerID=123;
    customerName="XYZ";
    totalAccountCreated=0;


}
public void setDetails(int accountNumber,String accountType,String serviceBranchIFSC, float minimumBalance,float availableBalance,int customerID,String customerName)
{
    this.accountNumber=accountNumber;
    this.accountType=accountType;
    this.serviceBranchIFSC=serviceBranchIFSC;
    this.minimumBalance=minimumBalance;
    this.availableBalance=availableBalance;
    this.customerID=customerID;
    this.customerName=customerName;


}

public void getDetails()
{
    System.out.println("Account Type : "+accountType);
    System.out.println("ServiceBranchIFSC : "+serviceBranchIFSC);
    System.out.println("MinimumBalance : "+minimumBalance);
    System.out.println("Available Balance : "+availableBalance);
    System.out.println("Customer ID : "+customerID);
    System.out.println("Customer Name : "+customerName);


}
public void updateDetails()
{
    System.out.println("Enter :\n 1->Account Type \n2->ServiceBranchIFSC \n 3->MinimumBalance\n4->Available Balance\n5->Customer ID\n6->Customer Name");
    int a= input.nextInt();
    if(a==1)
    {
        System.out.println("Type updated Account Type :");
        input.nextLine();
        String s=input.nextLine();
        accountType=s;

    }
   else if(a==2)
    {
        System.out.println("Type updated Service Branch IFSC :");
        input.nextLine();
        String s=input.nextLine();
        serviceBranchIFSC=s;

    }
   else if(a==3)
    {
        System.out.println("Type updated Minimum balance  :");
        int in=input.nextInt();
        minimumBalance=in;


    }
   else if(a==4)
    {
        System.out.println("Type updated available balance  :");
        int in=input.nextInt();
        availableBalance=in;

    }
    else if(a==5)
    {
        System.out.println("Type updated customer ID  :");
        int in=input.nextInt();
        customerID=in;

    }
    else if(a==6)
    {
        System.out.println("Type updated Customer Name  :");
        input.nextLine();
        String s=input.nextLine();
        customerName=s;
    }
    else
    {
        System.out.println("Invalid Entry");

    }
    System.out.println("Your details are updated." +
            "");


}
public void deposit(float s)
{
    availableBalance+=s;
    System.out.println("Your amount is deposited .");

}
public void withdraw(float s)
{
    if(availableBalance-s<minimumBalance)
        System.out.println("This amount cannot be withdrawn as we have to maintain the minimum balance in your account");
    else {
        availableBalance = availableBalance - s;
        System.out.println("Your amount is withdrawn");
    }

}
public int totalAccounts()
{
    return totalAccountCreated;
}






}

public class Main {

    public static void main(String[] args) {
        System.out.println("Enter Number of accounts :");
        Scanner input=new Scanner(System.in);
        int a=input.nextInt();


Account acc[]=new Account[a];
for(int i=0;i<a;i++)
{
   acc[i]=new Account();
    System.out.println("-------------------------------------------------------------");
    System.out.printf("Enter the details for the %d Account in database :\n",i+1);
    int  accountNumber ;

    String accountType;
    String serviceBranchIFSC;
    float minimumBalance;
    float availableBalance;
    int customerID;
    String customerName;

    System.out.println("Enter Account Number :");
    accountNumber = input.nextInt();
    System.out.println("Enter Account Type : ");
input.nextLine();

    accountType= input.nextLine();
    System.out.println("Enter service branch ifsc : ");

    serviceBranchIFSC= input.nextLine();

    System.out.println("Enter minimum balance : ");
    minimumBalance= input.nextFloat();
    System.out.println("Enter available balance : ");
    availableBalance= input.nextFloat();

    System.out.println("Enter Customer ID :");
    customerID = input.nextInt();
    System.out.println("Enter customer name : ");
  input.nextLine();

    customerName= input.nextLine();
    acc[i].setDetails(accountNumber,accountType,serviceBranchIFSC,minimumBalance,availableBalance,customerID,customerName);







}

while(true)
{
    System.out.println("------------------------------------------------------------------------");
    System.out.println("Enter your account number for performing various actions on your account : ");
    int yx=input.nextInt();

    int id=-1;
    for(int i=0;i<a;i++)
    {
        if(acc[i].accountNumber==yx)
            id=i;
    }
    if(id==-1)
        System.out.println("Invalid account number .");
    else {
        System.out.println("\nSelect the following options to perform the desired  operation :\n");

        System.out.println("Choose the below option :\n1. Update Details\n2. Get Details\n3. Deposit\n4. Withdraw\n5. Compare\n6.Total Accounts\n7.Exit");
        int xy=input.nextInt();

       if(xy==1)
       {
           acc[id].updateDetails();
       }
       else if(xy==2)
           acc[id].getDetails();
       else if(xy==3)
       {
           System.out.println("How much amount you want to deposit :");
           float s=input.nextFloat();
           acc[id].deposit(s);

       }
       else if(xy==4)
       {
           System.out.println("Enter how much amount you want to withdraw :");
           float s=input.nextFloat();
           acc[id].withdraw(s);

       }
       else if(xy==6)
       {
           System.out.println("Total accounts in bank are "+a);
       }
       else if(xy==5)
           break;
else if(xy==7)
       {
           System.out.println("Enter the account number of the other customer with whom you want to compare");
           int tr=input.nextInt();
           int id2=-1;
           for(int i=0;i<a;i++)
           {
               if(acc[i].accountNumber==tr)
                   id2=i;
           }
           if(id2==-1)
               System.out.println("Invalid account number ");
           else
           {
               if(acc[id].availableBalance>acc[id2].availableBalance)
               {
                   acc[id].getDetails();
               }
               else
                   acc[id2].getDetails();

           }
       }
       else
           System.out.println("Invalid entry");


    }

}


    }
}

