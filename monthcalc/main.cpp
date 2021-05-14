
//Celeste Tan
//inputs month day year
//process and output the day of the week

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

void getInput(int &month, int& day, int &year);// gets the input of the month day and year of a date

bool is_leap_year(int year); // determine if that year inputed is a leap year

int getCenturyValue(int year);//gets a value that is based on the century of that year

int getYearValue(int year);//gets a value that is based on that year

int getMonthValue(int month, int year);//gets a value that is based on that month



int main()
{
    const int maxdaysinweek = 7;
    int month, day, year, dayofweek,sum;

     char tryAgain = 'y';
     while (tryAgain == 'y' || tryAgain == 'Y')
     {
    getInput(month, day, year);
    is_leap_year(year);
    getCenturyValue(year);
    getYearValue(year);

    getMonthValue( month,  year);

    sum = getCenturyValue(year)+getYearValue(year)+
          getMonthValue( month,  year)
          + day;
    dayofweek = sum%maxdaysinweek;

    switch(dayofweek){
        case 0:
            cout << "Sunday\n";
            break;
        case 1:
            cout << "Monday\n";
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        case 4:
            cout <<"Thursday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        case 6:
            cout << "Saturday\n";
            break;

    }

         cout << "Try again? Press Y for 'Yes' and N for 'No' \n";
         cin >> tryAgain;
     }




}

void getInput(int &month, int& day, int &year){
    cout << "Enter a month, day, and year\n";
    cin >> month;
    cin >> day;
    cin >> year;
}

bool is_leap_year(int year){
    bool leapyear;
    if(year%400 == 0 || (year%4 == 0 && year%100 != 0)){
        leapyear = true;
    }
    else if(!(year%400 == 0 || (year%4 == 0 && year%100 != 0))){
        leapyear = false;
    }

    return leapyear;
}

int getCenturyValue(int year){

    int cremainder = (year/100)%4 ;
    int bothdigits = 2;



    return  bothdigits*( 3-cremainder);



}

int getYearValue(int year){

    int ones = year % 10;
    int tens = year / 10 % 10;











    return year % 100 + (year % 100) / 4;
}

int getMonthValue(int month, int year){
    int value;
    switch(month){
        case 1:
            if(is_leap_year(year) == true){
                value = 6;
            }
            else{
                value = 0;
            }
            break;
        case 2:
            if(is_leap_year(year) == false){
                value = 2;
            }
            else{
                value = 3;
            }
            break;
        case 3:
        case 11:
            value = 3;
            break;
        case 4:
        case 7:
            value = 6;
            break;
        case 5:
            value = 1;
            break;
        case 6:
            value = 4;
            break;
        case 8:
            value = 2;
            break;
        case 9:
        case 12:
            value = 5;
            break;
        case 10:
            value = 0;
            break;


    }

    return value;
}

// /
//  * example output: Enter a month, day, and year
// 10
// 4
// 2019
// friday
// Try again? Press Y for 'Yes' and N for 'No'
// y
// Enter a month, day, and year
// 7
// 4
// 2008
// friday
// Try again? Press Y for 'Yes' and N for 'No'
