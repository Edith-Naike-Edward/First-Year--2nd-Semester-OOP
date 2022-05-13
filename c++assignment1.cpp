#include <iostream>
#include <cmath>
using namespace std;

class Math{
public:
    double x1;
    double x2;
    double y1;
    double y2;
    double d1;
    double midpoint1;
    double midpoint2;

    Math()
    {
        cout << "Enter the value for x1:";
        cin >> x1;
        cout << "Enter the value for y1:";
        cin >> y1;

        cout << "Enter the value for x2:";
        cin >> x2;
        cout << "Enter the value for y2:";
        cin >> y2;

        d1= pow((x2 - x1),2) + pow((y2 - y1),2);
        d1=sqrt(d1);
        cout <<"The distance between point A and B is :"<<d1<<endl;

    }

    void midpoint()
    {

       midpoint1=(x1+x2)/2;
       midpoint2=(y1+y2)/2;
       //cout << "The midpoint is "<< "( , )"<<midpoint1 <<midpoint2 << endl;
       cout << "\nThe midpoint of Points A and B is::  " << "(" << midpoint1 << "," << midpoint2 << ")" << endl ;
    }
};

class triArea: public Math
{
 public:
     double x3,y3;
     double d2,d3;
     double A,s;

     void Distance1()
     {
         cout << "Enter the value for x3:";
         cin >> x3;
         cout << "Enter the value for y3:";
         cin >> y3;

         d2= pow((x3 - x1),2) + pow((y3 - y1),2);
         d2=sqrt(d2);
         cout <<"The distance is between point C and A is:"<<d2<<endl;

         d3= pow((x3 - x2),2) + pow((y3 - y2),2);
         d3=sqrt(d3);
         cout <<"The distance is between point C and B is:"<<d3<<endl;
     }

     void AreaofT()
     {
         s = (d1 + d2 + d3)/2;
         A =sqrt(s*(s-d1)*(s-d2)*(s-d3));
         cout <<"The Area is:"<<A<<endl;
     }
};

class quadArea : public triArea
{
public:
    double x4,y4;
    double d4,d5;

    void Distance2()
    {
        cout << "Enter the value for x3:";
        cin >> x3;
        cout << "Enter the value for y3:";
        cin >> y3;

        d2= pow((x4 - x2),2) + pow((y4 - y2),2);
        d2=sqrt(d4);
        cout <<"The distance is D and A:"<<d2<< "cm"<<endl;

        d3= pow((x4 - x3),2) + pow((y4 - y3),2);
        d3=sqrt(d5);
        cout <<"The distance is :"<<d3<< "cm"<<endl;
    }

    void Area()
    {
        if (d1 == d2 == d3 == d4)
        {
            cout<< "The quadrilateral is a square!!"<<endl;
        }
        else if (d1 == d2 && d3 == d4)
        {
            cout<<"The quadrilateral is a rectangle"<<endl;
        }
        else if (d1 == d4 && d3 == d2)
        {
            cout<<"The quadrilateral is a rectangle"<<endl;
        }
        else if (d1 == d3 && d4 == d2)
        {
            cout<<"The quadrilateral is a rectangle"<<endl;
        }
        else
        {
            cout<<"The quadrilateral is not a square or a rectangle!!"<<endl;
        }
    }
};
int main()
{
    int number;

    cout << "\t\t\t\t MENU"<<endl;
    cout <<"~(1).Distance between 2 points A and B"<<endl;
    cout <<"~(2).Midpoint of 2 points A and B" << endl;
    cout <<"~(3).Area of a Triangle resulting from Points A,B and C"<<endl;
    cout <<"~(4).Area of a Quadilateral resulting Points A,B,C and D" << endl;
    cin >> number;

    if (number == 1)
    {
        Math();
    }
    else if (number == 2)
    {
        Math a;
        a.midpoint();
    }
    else if (number == 3)
    {
        triArea b;
        b.Distance1();
        b.AreaofT();
    }
    else if (number == 4)
    {
       quadArea c;
       c.Distance2();
       c.Area();
    }
    else
    {
        cout << "Made by Edith Naike Edward"<< endl;
        cout << "P15/143394/2021 GROUP 2"<<endl;
        exit(0);
    }
    return 0;
}
