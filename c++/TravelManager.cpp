#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;

void menu();

class managemenu
{
protected:
    string username;
public:
    managemenu()
    {
        system("color E6");
        cout<<"\n\n\n\n\n\n\t\t\tEnter your name to continue as an admin\n\n\t\t\t\t\t";
        for(int i=5;i>0;i--)
        {
            cin>>username;
            system("CLS");
            if(username=="chirag")
                {
                    menu();
                    return;
                    }
            else
            cout<<"\n\n\n\n\n\n\t\t\tadmin not detected. "<<i-1<<" trials left\n\n\t\t\t\t\t";
        }
        cout<<"the system has been locked for security reasons\n";
        Sleep(2000);
        system("CLS");
    }

};

class customer
{
public:
    string name;
    long long mobile;
    static int id;

    void getdetails()
    {
        ifstream idfile("idno.txt");
       if(idfile)
       idfile>>id;
       idfile.close();
       ofstream file("idno.txt",ios_base::trunc);
        file<<id+1<<endl;
        file.close();
        cout<<"Your customer id has been generated as: "<<id<<endl;
        getchar();
        cout<<"Enter name : ";
        getline(cin,name);

        cout<<"Enter mobile: ";
        cin>>mobile;

        ofstream outfile("customers.txt",ios_base::app);
        outfile<<id<<" "<<name<<" "<<mobile<<endl;
        outfile.close();

        cout<<"\nSAVED\n";
        Sleep(2000);
        system("CLS");
    }
    void showdetails()
    {
        char all[999];
        ifstream infile("customers.txt");
        if(!infile || infile.eof())
        {
            cout<<"customers base is empty\n";
        }
        while(!infile.eof())
        {
            infile.getline(all,999);
            cout<<all<<endl;
        }
        infile.close();
    }

};

     int customer:: id=1;


class cabs
{
    public:
     int cabchoice;
     int kms;
     float currcost;
     static float finalcost;
    int hirecab;

     void cabdetails()
     {
         m:
         cout<<"we colaborated with smartest, safest and fastest cab services around the country\n\n";
         cout<<"\n---------------------Chirag Cabs------------------------\n\n";
         cout<<"1.Rent a standard Cab -> 1$ per mile\n";
         cout<<"2.Rent a Luxury Cab->1.5$ per mile\n\n";

         cout<<"chose your cab : 1<->Standard     2<->Luxury\n";
         string cabtype;
         cabchoice=getch()-'0';
         if(cabchoice!=1 && cabchoice!=2)
         {
            cout<<"invalid input!\n";

             return;
         }


         cout<<"Enter distance of trip in km\n";
         cin>>kms;

         if(cabchoice==1)
         {
             currcost=kms*1;
             cabtype="Standard";
         }
         else if(cabchoice==2)
         {
             currcost=kms*1.5;
             cabtype="Luxury";
         }

         cout<<"tour cost is calculated to be: "<<currcost<< "$\n";
         cout<<"press 1 to hire this cab or press 2 to select another cab\n";
         hirecab=getch()-'0';

         if(hirecab==1)
         {
             int prev_id;
             long long prev_mob;
             string prev_customer;
             ifstream infile("customers.txt");
             system("CLS");
             while(!infile.eof())
             {
                 infile>>prev_id>>prev_customer>>prev_mob;
             }
                 cout<<"Booking will be done with the following attributes :\n";
                 cout<<"---------------------------------------------------------\n";
                 cout<<"\t\t\tname: "<<prev_customer<<endl;
                 cout<<"\t\t\tid: "<<prev_id<<endl;
                 cout<<"\t\t\tmobile no : "<<prev_mob<<endl;
                 cout<<"\t\t\tcab : "<<cabtype<<endl;
                 cout<<"\t\t\tkms : "<<kms<<endl;
                 cout<<"---------------------------------------------------------\n";
                 cout<<"\t\t\tare you sure you want to book cab with the following details?"<<endl;
                 cout<<"\t\t\tfor yes, press 1......for no, press any other key\n";
                 int n;
                 n=getch()-'0';
                 if(n!=1)
                 {
                     system("CLS");
                    cout<<"we deeply regret that the booking was unsuccessful!\n\n\n if user details were wrong,   please register user details in customer management\n";
                    Sleep(3000);
                    for(int i=3;i>0;i--)
                    {
                        system("CLS");
                        cout<<"redirecting in "<<i<<endl;
                        Sleep(1000);
                    }
                    return;
                 }
            system("CLS");
             cout<<"Please wait while the booking is taking place........\n";
             Sleep(2000);
             finalcost=currcost;

             cout<<"\n successfully hired a "<<cabtype<<" cab for "<<kms<<" kms\n";

             cout<<"\ngo to menu to generate reciept or book a hotel\n";
             cout<<".........press any key to continue\n";
             getch();
             system("CLS");
             return ;
         }

         else if(hirecab==2)
         {
             system("CLS");
             goto m;
         }
         else
         {
             cout<<"invalid input!..try again\n";
             Sleep(2000);
             system("CLS");
             goto m;
         }
     }
};

float cabs::finalcost=0;

class booking
{
    public:
    int choicehotel;
    int days;
    int bookhotel;
    static int cost;

    void hotels()
    {
        m:
        string hotelNo[]={"Avendra","Abhinandan","greentop"};
        int priceNo[]={1000,2000,3000};
        for(int i=0;i<3;i++)
            cout<<i+1<<".  hotel "<<hotelNo[i]<<" price: "<<priceNo[i]<<endl<<endl;

        cout<<"currently we collaborated with above hotels!\n";
        cout<<"Enter hotel no. which you want to book\n";
        choicehotel=getch()-'0';
        system("CLS");
        if(choicehotel==1)
        {
            cout<<"welcome to the Hotel Avendra! the tourist's companion\n";
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
        }
        else if(choicehotel==2)
        {
            cout<<"greeting and welcomes.....as you are at hotel Abhinandan! \n";
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
        }
        else if(choicehotel==3)
        {
            cout<<"Wecome to greentop!...the pioneer in the art of hotel innovations\n";
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
        }
        else
        {
            cout<<"Invalid choice!...\n";
            Sleep(2000);
            system("CLS");
            return;
        }
        cout<<"Enter the no of days of stay\n";
        cin>>days;
        cout<<"total cost of stay is calculated to be "<<days*priceNo[choicehotel-1]<<endl;
        cout<<"press 1 to book the deal , press 2 to book any other hotel\n";
        bookhotel=getch()-'0';

         system("CLS");
         if(bookhotel==1)
         {
              int prev_id;
             long long prev_mob;
             string prev_customer;
             ifstream infile("customers.txt");
             while(!infile.eof())
             {
                 infile>>prev_id>>prev_customer>>prev_mob;
             }
                 cout<<"Booking will be done with the following attributes :\n";
                 cout<<"---------------------------------------------------------\n";
                 cout<<"\t\t\tname: "<<prev_customer<<endl;
                 cout<<"\t\t\tid: "<<prev_id<<endl;
                 cout<<"\t\t\tmobile no : "<<prev_mob<<endl;
                 cout<<"\t\t\thotel : "<<hotelNo[choicehotel-1]<<endl;
                 cout<<"\t\t\tdays of stay : "<<days<<endl;
                 cout<<"---------------------------------------------------------\n";
                 cout<<"\t\t\tare you sure you want to book hotel with the following details?"<<endl;
                 cout<<"\t\t\tfor yes, press 1......for no, press any other key\n";
                 int n;
                 n=getch()-'0';
                 if(n!=1)
                 {
                     system("CLS");
                    cout<<"we deeply regret that the booking was unsuccessful!\n\n\n if user details were wrong,   please register user details in customer management\n";
                    Sleep(3000);
                    for(int i=3;i>0;i--)
                    {
                        system("CLS");
                        cout<<"redirecting in "<<i<<endl;
                        Sleep(1000);
                    }
                    return;
                    }
             cout<<"Please wait while the booking is taking place........\n";
             Sleep(2000);
             cost=days*priceNo[choicehotel-1];

             cout<<"\nwe have successfully booked hotel "<<hotelNo[choicehotel-1]<< " for "<<days<<" days\n";
             cout<<"\ngo to menu to hire a cab/take the reciept\n";
             cout<<"press any key to continue\n";
             getch();
         }

         else if(bookhotel==2)
         {
             goto m;
         }
         else
         {
             system("CLS");
             cout<<"invalid input!\n";
         }
             system("CLS");
             return;
    }

};

 int booking::cost=0;

class charges : public customer,cabs,booking
{
    public:
    void printbill()
    {
        ofstream outfile("reciept.txt",ios_base::app);
        outfile<<"----------Chirag Travel Agency----------\n"<<endl;
        outfile<<"   ----------------reciept--------------\n"<<endl;
        outfile<<"Customer ID "<<customer::id<<endl;
        outfile<<"Cab cost : "<<cabs::finalcost<<endl;
        outfile<<"Hotel cost: "<<booking::cost<<endl;
        outfile<<"Total:  "<<cabs::finalcost+ booking::cost<<endl;
        outfile<<"_________________________\n "<<endl;
        outfile<<"Thankyou"<<endl<<endl<<endl;
        outfile.close();
        cabs::finalcost=0;
        booking::cost=0;
    }
    void showbills()
    {
        ifstream infile("reciept.txt");
        char a[999];
        if(!infile)
        {
            cout<<"Error\n\n";
        }
        while(!infile.eof())
        {
            infile.getline(a,999);
            cout<<endl<<a;
        }
        infile.close();
    }
};


void menu()
{
    m:
    int mainchoice;
    cout<<"\t\t_______________Chirag Travels Welcomes You onboard_________________\n\n\n";
    cout<<"\t\t\t\t customer management-> press 1\n";
    cout<<"\t\t\t\t Cabs management-> press 2\n";
    cout<<"\t\t\t\t hotel management-> press 3\n";
    cout<<"\t\t\t\t Charges and bills-> press 4\n";
    cout<<"\t\t\t\t Exit-> rest of the keys\n\n\n";
    cout<<"note->make sure to register user details for every booking\n\n\n";

    cout<<"Enter your choice: ";
    fflush(stdin);
    mainchoice=getch()-'0';
    system("CLS");
    customer a2;
    cabs a3;
    booking a4;
    charges a5;
    if (mainchoice==1)
    {
        cout<<"--------------customers----------------\n";
        cout<<"1.Enter new customer\n";
        cout<<"2.See old customers\n";

        cout<<"enter choice: ";
        int choice;
        choice=getch()-'0';
        system("CLS");
        if(choice==1)
        {
            a2.getdetails();
            goto m;
        }
        else if(choice==2)
        {
            a2.showdetails();
              cout<<"\n\npress any key to exit";
             getch();
        }
        else
        {
            cout<<"Invalid input!\n";
        }
    }
    else if (mainchoice==2)
        a3.cabdetails();
    else if(mainchoice==3)
        a4.hotels();
    else if(mainchoice==4)
        {
        cout<<"--------------reciepts----------------\n";
        cout<<"1.generate reciept\n";
        cout<<"2.See old reciepts\n";

        cout<<"enter choice: ";
        int choice;
        choice=getch()-'0';
        system("CLS");
        if(choice==1)
        {
             a5.printbill();
              cout<<"please wait while the reciept is being generated..................\n";
              Sleep(2000);
              system("CLS");
              cout<<"Reciept generated successfully in the billbox\n";
              cout<<"press any key to continue";
              getch();
        }
        else if(choice==2)
        {
            a5.showbills();
            cout<<"\n\npress any key to exit";
            getch();
        }
        else
        {
            cout<<"Invalid input! \n";
        }
    }
   else
   {
           cout<<"Thankyou for using our services!.........visit again!";
           Sleep(2000);
           system("CLS");
           exit(0);
   }
        cout<<"\nredirecting to the main menu........\n";
        Sleep(2000);
        system("CLS");
        goto m;
}



int main()
 {
    managemenu startObject;
    return 0;
}
