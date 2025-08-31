/*Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.*/

#include <iostream>
using namespace std;

int main() {
    int **temperature;
    int numDays, *timeInDay;
    cout << "Enter number of days: ";
    cin>>numDays;
    timeInDay = new int[numDays];
    temperature = new int*[numDays];
    for (int i =0;i<numDays;i++) {
        cout << "Enter number of times to record in day "<< i+1<<":";
        cin>> timeInDay[i];
        temperature[i] = new int[timeInDay[i]];
        for(int j = 0; j < timeInDay[i]; j++) {
            cout << "Enter temperature on day "<< i +1 << "at time "<< j<< ": ";
            cin >> temperature[i][j];
        }
    }
    float hottest = -100.0, coldest = 100.0;
    int hindex = 0, cindex = 0;
    for( int i = 0; i < numDays; i++) {
        int total = 0; float avg;
        for (int j =0;j<timeInDay[i];j++) {
            total += temperature[i][j];
        }
        avg = total/timeInDay[i];
        cout << "Average on Day "<< i+1<< "is " << avg << endl;
        if (hottest < avg) {
            hottest = avg; hindex = i;
        }
        if (coldest > avg) {
            coldest = avg; cindex = i;
        }
    }
    cout << "Hotest Day: Day "<<hindex +1<<endl;
    cout << "Coldest Day: Day "<<cindex +1<<endl;
}
