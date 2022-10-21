#include<iostream>
using namespace std;
int main(){
    int quant=0;
    int m;
    //Quantity
    int qrooms=0, qpasta=0, qshake=0, qmaggie=0, qchicken=0;
    //Sold number
    int srooms=0, spasta=0, sshake=0, smaggie=0, schicken=0;
    //Total price
    int total_rooms=0, total_pasta=0, total_shake=0, total_maggie=0, total_chicken=0;

    cout<<"\t Quantity of items in Hotel "<<endl;
    cout<<"Enter total number of rooms available: "<<endl;
    cin>>qrooms;
    cout<<"Enter total number of pasta: "<<endl;
    cin>>qpasta;
    cout<<"Enter total number of shake: "<<endl;
    cin>>qshake;
    cout<<"Enter total number of maggie: "<<endl;
    cin>>qmaggie;
    cout<<"Enter total number of chicken roll: "<<endl;
    cin>>qchicken;

    //Menu 
    
    menu:
    cout<<"Select from menu: "<<endl;
    cout<<"1) Room "<<endl;
    cout<<"2) Pasta "<<endl;
    cout<<"3) Shake "<<endl;
    cout<<"4) Maggie "<<endl;
    cout<<"5) Chicken Roll "<<endl;
    cout<<"6) Information of todays sale and collection "<<endl;
    cout<<"7) Exit "<<endl;

    cout<<"Please enter your choice: "<<endl;
    cin>>m; 

    switch (m){
        case 1:
        cout<<"Enter number of rooms required: "<<endl;
        cin>>quant;
        if(qrooms-srooms>=quant){
        srooms= srooms + quant;
        qrooms= qrooms-quant;
        total_rooms=total_rooms + (2000*quant);
        cout<<"Booking successfull!!"<<endl;
        }
        else{
            cout<<"Sorry!! We don't have sufficient rooms"<<endl;
            cout<<"Available rooms are: "<<qrooms-srooms;
        }
        break;

        case 2:
        cout<<"Enter number of pasta required: "<<endl;
        cin>>quant;
        if(qpasta-spasta>=quant){
        spasta= spasta + quant;
        qpasta= qpasta-quant;
        total_pasta=total_pasta + (300*quant);
        cout<<"Booking successfull!!"<<endl;

        }
        else{
            cout<<"Sorry!! We don't have sufficient pasta"<<endl;
            cout<<"Available pasta are: "<<qpasta-spasta;
        }
        break;

        case 3:
        cout<<"Enter number of shake required: "<<endl;
        cin>>quant;
        if(qshake-sshake>=quant){
            sshake= sshake+ quant;
            qshake= qshake-quant;
            total_shake=total_shake+ (100*quant);
            cout<<"Booking successfull!!"<<endl;

        }
        else{
            cout<<"Sorry!! We don't have sufficient shake"<<endl;
            cout<<"Available shake are: "<<qshake-sshake;
        }
        break;

        case 4:
        cout<<"Enter total number of maggie required: "<<endl;
        cin>>quant;
        if(qmaggie-smaggie>=quant){
            smaggie=smaggie+quant;
            qmaggie=qmaggie-quant;
            total_maggie =total_maggie+ (150*quant);
            cout<<"Booking successfull!!"<<endl;

        }
        else{
            cout<<"Sorry!! We don't have sufficient maggie"<<endl;
            cout<<"Available maggie are: "<<qmaggie-smaggie;
        }
        break;

        case 5:
        cout<<"Enter total number of chicken roll required: "<<endl;
        cin>>quant;
        if(qchicken-schicken>=quant){
            schicken=schicken+quant;
            qchicken=qchicken-quant;
            total_chicken=total_chicken+ (470*quant);
            cout<<"Booking successfull!!"<<endl;

        }
        break;

        case 6:
        cout<<"/t Information about sales and collection"<<endl;
        cout<<" Number of rented rooms: "<<srooms<<endl;
        cout<<" Remaining number of rooms: "<<qrooms-srooms<<endl;
        cout<<" Income generated by renting rooms: "<<total_rooms<<endl;

        cout<<"Sold number of pasta: "<<spasta<<endl;
        cout<<" Remaining number of pasta: "<<qpasta-spasta<<endl;
        cout<<" Income generated by selling pasta: "<<total_pasta<<endl;

        cout<<"Sold number of shake: "<<sshake<<endl;
        cout<<" Remaining number of shake: "<<qshake-sshake<<endl;
        cout<<" Income generated by selling shake: "<<total_shake<<endl;

        cout<<"Sold number of maggie: "<<smaggie<<endl;
        cout<<" Remaining number of maggie: "<<qmaggie-smaggie<<endl;
        cout<<" Income generated by selling maggie: "<<total_maggie<<endl;

        cout<<"Sold number of chicken: "<<schicken<<endl;
        cout<<" Remaining number of chicken: "<<qchicken-schicken<<endl;
        cout<<" Income generated by selling chicken-roll: "<<total_chicken<<endl;
        cout<<"Total revenue generated: "<<total_rooms+total_pasta+ total_maggie+ total_shake+ total_chicken<<endl;
    
        break;

        case 7:
        cout<<"Thank you for visting!!"<<endl;
        break;

        default:
        cout<<"Re-enter correct option"<<endl;

    }
    cout<<endl;
    goto menu;
    return 0;
}