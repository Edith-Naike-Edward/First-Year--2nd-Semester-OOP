#include <iostream>

using namespace std;

class Property{
public:
    void SaleorLet();
    void SoldorRented();
    void PropertyTypeDetails();
    void Info();

public:
    double price;
    int propertynumber;// changed from char to int
    string propertyname[3];//made it an array to make it easier to type with spaces
    int propertytype;// made it an int because the string aint working
    string propertystyle;
    struct Location{
        string streetname;
        string city;
        string plotno;
        string houseno;
        string apartmentno;
        string postalcode;
    };
    Location address;

    Property()
    {

    }
};

void Property :: PropertyTypeDetails()
{
    Property property1;
    cout << "Enter the property number: " << endl;
    cin >> propertynumber;
    cout << "Enter the property price: " << endl;
    cin >> price;
    cout << "Enter the property name: " << endl;
    cin >> propertyname[2];
    cout << "Types of properties: \n\t1.Land\n\t2.Apartment\n\t3.House" <<endl;
    cout << "Enter the property type:"<< endl;
    cin >> propertytype;
    if (propertytype == 1)
    {
        cout <<"Enter the plot number:" << endl;
        cin >> address.plotno;
    }else if(propertytype == 2)
    {
        cout <<"Enter the apartment number:" << endl;
        cin >> address.apartmentno;

    }else if(propertytype == 3){
        cout <<"Enter the house number:"<< endl;
        cin >> address.houseno;
        cout << "Enter the property style:"<< endl;
        cin >> propertystyle;
    }else{
        cout << "Invalid input." << endl;
        exit(0);
    }
    cout << "Enter the street name: " << endl;
    cin >> address.streetname;
    cout << "Enter the city:"<< endl;
    cin >> address.city;
    cout << "Enter the postal code:"<< endl;
    cin >> address.postalcode;
};

void Property :: Info()
{
    int n;
    double totalrepayment;
    double mortgageamount;
    double loantype;
    string amenities[n];
    int availableplots;
    double interestrate;
    double minprice;
    double maxprice;
    double askingprice;
    cout << "Enter the number of amenities:";
    cin >> n;
    for (int i=0;i<=n;i++)
    {
        cout << "Enter the amenity:",i;
        cin >> amenities[n];
    }
    cout << "Enter the total repayment:";
    cin >> totalrepayment;
    cout << "Enter the mortgage amount:";
    cin >> mortgageamount;
    cout << "Enter the loan type:";
    cin >> loantype;
    cout << "Enter the available plots:";
    cin >> availableplots;
    cout << "Enter the interest rate:";
    cin >> interestrate;
    cout << "Enter the maximum price:";
    cin >> maxprice;
    cout << "Enter the minimum price:";
    cin >> minprice;
    cout << "Enter the asking price:";
    cin >> askingprice;
};

void Property :: SaleorLet()
{
    string choice;
    string sale;
    string let;
    cout << "Do you want to sale or rent/let?";
    cin >> choice;
    if (choice == "sale")
    {
        cout << "Property is on sale." << endl;
    }
    else if (choice == "let")
    {
        cout << "Property is on let" << endl;
    }
    else{
        cout << "NOT on sale or let." << endl;
        exit(0);
    }
};

void Property :: SoldorRented()
{
    string decision;
    string sold;
    string rented;
    cout << "Is property sold or rented?";
    cin >> decision;
    if (decision == "sold")
    {
        cout << "Property sold." << endl;
    }
    else if (decision== "rented")
    {
        cout << "Property rented." << endl;
    }
    else{
        cout << "NOT bought or rented." << endl;
        exit(0);
    }
};

class Agent:public Property{
public:
    int noofagents;
    string agentname;
    string id;
    string company;

   void AgentDetails()
    {
        cout << "Enter the number of agents:" <<endl;
        cin >> noofagents;
        for (int i=0;i<=noofagents;i++)
        {
            cout << "Enter your name: " << endl;
            cin >> agentname;
            cout << "Enter your ID:"<< endl;
            cin >> id;
            cout << "Enter your Company:"<< endl;
            cin >> company;
        }
    }
};

class Client: public Property
{
public:
    string firstname;
    string lastname;
    int phoneno;
};

int main()
{
    int number;
    int i;

    do{
            cout << "\t\t\t\t MENU"<<endl;
            cout <<"~(1).Property Details"<<endl;
            cout <<"~(2).Agent Details" << endl;
            cout <<"~(3).Sale or Let"<<endl;
            cout <<"~(4).Sold or Rented" << endl;
            cin >> number;

            if (number==1)
            {
                Property();
                Property a,z;
                a.PropertyTypeDetails();
                z.Info();
            }
            else if (number==2)
            {
                Agent b;
                b.AgentDetails();
            }
            else if (number==3)
            {
                Property();
                Property c;
                c.SaleorLet();
            }
            else if (number==4)
            {
                Property();
                Property d;
                d.SoldorRented();
            }
            else
            {
                cout << "Made by Edith Naike Edward"<< endl;
                cout << "P15/143394/2021 GROUP 2"<<endl;
                exit(0);
            }


            cout << "Do you wish to continue?\n1-Yes OR 0-No:\n";
            cin >> i;
    }
    while(i==1);

    return 0;
}
