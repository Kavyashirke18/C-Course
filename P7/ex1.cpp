#include <string>
#include <vector> 
#include <iostream>
#include <sstream>
using namespace std;

class Date{
      public: 
      int day, month, year;
      Date(int day, int month, int year): day(day), month(month), year(year)
      {}
  };

class Blood
{
  
  public:
    int systolic, diastolic;
    Date date;
    Blood(int systolic, int diastolic, Date date): systolic(systolic), diastolic(diastolic), date(date)
    {}

};

class Patient
{
  
  public:
    string name;
    Patient(string name) {
      name = name;
    }
    
    vector<Blood> bloodList;

    void addRecord(Blood blood)
    {
      bloodList.push_back(blood);
    }

    void printReport()
    {
      Blood highest = bloodList.at(0);
      vector<Blood> list_highest;
      list_highest.push_back(highest);
      int average = 0;

      for(int i=0; i < bloodList.size(); i++)
      {
        Blood temp = bloodList.at(i);
        
        average += temp.diastolic; 

        if(temp.systolic > 140 && temp.systolic >= highest.systolic)
        {
          if(highest.systolic == temp.systolic) 
          {
            list_highest.push_back(temp);
          }
          else 
          {
            highest = temp;
            while(list_highest.size() != 0)
            {
              list_highest.pop_back();
            }
            list_highest.push_back(temp);
          }
        }        
      }
      
      if(highest.systolic < 140) 
      {
        cout << "No measurement was too high" << endl;
      }
      else 
      {
        cout << "The highest abnormal systolic value is " << highest.systolic << endl;
        cout << "and diastolic value is " << highest.diastolic << endl;
        cout << "Taken on " << highest.date.day << "/" << highest.date.month << "/" << highest.date.year << endl;
        cout << "Highest abnormal systolic value is " << endl;
        for (int i = 0; i < list_highest.size(); i++)
        {
          cout << list_highest.at(i).systolic << endl;
        }
      }


      average = average/bloodList.size();

      cout << "Average Diastolic value - " << average << endl;

    }

};

int main() {

//create patient Mary with blood record
Patient mary("Mary");
mary.addRecord(Blood(94,61, Date(2,5,2013)));
mary.addRecord(Blood(97,65, Date(3,5,2013)));
mary.addRecord(Blood(144,99, Date(4,5,2013)));
mary.addRecord(Blood(123,88, Date(5,5,2013)));
mary.addRecord(Blood(177,110, Date(6,5,2013)));
mary.addRecord(Blood(145,89, Date(7,5,2013)));
mary.printReport();

//create patient John with blood record
Patient john("John");
john.addRecord(Blood(88,57, Date(15,5,2013)));
john.addRecord(Blood(95,61, Date(16,5,2013)));
john.addRecord(Blood(144,80, Date(17,5,2013)));
john.addRecord(Blood(151,96, Date(18,5,2013)));
john.addRecord(Blood(176,104, Date(19,5,2013)));
john.addRecord(Blood(176,110, Date(20,5,2013)));
john.printReport();

return 0;
}