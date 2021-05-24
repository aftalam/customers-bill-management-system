//Airtel Customer Care

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>

using namespace std;

class Airtel
{

private:
  char name[20], address[80], city[20], phone_no[11];
  unsigned int pre_reading, cur_reading, net_reading, customer_ID_no;
  float amount, net_amount;

public:
  Airtel();
  void input_details();
  void calculate();
  void print_details();
  void bill();
  char *get_phone_no();
  ~Airtel();
};

//Defination of Member Functions Starts

Airtel ::Airtel() //Constructors' Defination
{

  strcpy(name, "");
  strcpy(address, "");
  strcpy(city, "");
  strcpy(phone_no, "");
  pre_reading = 0;
  cur_reading = 0;
  net_reading = 0;
  customer_ID_no = 0;
  amount = 0;
  net_amount = 0;
}

void Airtel ::input_details() //Taking Details of Customer
{

  clrscr();
  cout << "\n  Enter Customer's NAME        :  ";
  gets(name);
  cout << "\n  Enter Customer's ADDRESS     :  ";
  gets(address);
  cout << "\n  Enter Customer's CITY name   :  ";
  gets(city);
  cout << "\n  Enter Customer's PHONE NO    :  ";
  gets(phone_no);
  cout << "\n  Enter Customer's ID NO       :  ";
  cin >> customer_ID_no;
  cout << "\n  Enter Previous Meter Reading :  ";
  cin >> pre_reading;
  cout << "\n  Enter Current Meter Reading  :  ";
  cin >> cur_reading;
}

void Airtel ::calculate() //Calculating Payable Amount
{

  net_reading = cur_reading - pre_reading;
  if (net_reading <= 100)
    amount = net_reading / 4;
  else if (net_reading <= 250)
    amount = net_reading / 2;
  else
    amount = net_reading;
  net_amount = amount + 500;
}

void Airtel ::print_details() //Printing Details of Customer
{

  calculate();
  cout << "\n\n\t\t\t  ____ DETAILS ____  \n\n";
  cout << "\n  Customer's NAME        :  " << name;
  cout << "\n  Customer's ADDRESS     :  " << address;
  cout << "\n  Customer's CITY name   :  " << city;
  cout << "\n  Customer's PHONE NO    :  " << phone_no;
  cout << "\n  Customer's ID NO       :  " << customer_ID_no;
  cout << "\n  Previous Meter Reading :  " << pre_reading;
  cout << "\n  Current Meter Reading  :  " << cur_reading;
  getch();
}

void Airtel ::bill() //Printing Bill of Customer
{

  calculate();
  cout << "\n\n\t\t\t  ____ " << name << "'s BILL ____  \n\n";
  cout << "\n  Customer's ID NO          :  " << customer_ID_no;
  cout << "\n  Net Meter Reading         :  " << net_reading;
  cout << "\n  Monthly Service Charges   :  " << 1000;
  cout << "\n  Customer's Call Charges   :  " << amount;
  cout << "\n  Net Amount to be Paid     :  " << net_amount + 1000;
  cout << "\n  Net Amount after Due Date :  " << net_amount + 1000 + 150;
  getch();
}

char *Airtel ::get_phone_no()
{
  return phone_no;
}

Airtel ::~Airtel() //Destructor
{
}

//Defination of Member Functions Ends

void create();
void search();
void delete_details();
void front_page();
void back_page();

void main()
{

  clrscr();
  front_page();
  getch();
  clrscr();
  int choice;
  char ch = 'y';

  do
  {

    clrscr();
    cout << "\n\n\t\t\t  WELCOME TO AIRTEL  \n";
    cout << "\t\t\t -------------------  \n\n  ";
    cout << "\n\n  1. Create a New Record  ";
    cout << "\n\n  2. View Details/Generate Bill  ";
    cout << "\n\n  3. Delete Existing Record  ";
    cout << "\n\n  4. EXIT  ";
    cout << "\n\n  Enter Your Choice (1-4) :  ";
    cin >> choice;

    switch (choice)
    {

    case 1:
      create();
      break;
    case 2:
      search();
      break;
    case 3:
      delete_details();
      break;
    case 4:
      back_page();
      getch();
      exit(0);
      break;
    default:
      cout << "\n  SORRY ! Invalid Input !  ";
      break;
    }

    cout << "\n\n  Do You Want To Continue ? (Y/N) :  ";
    cin >> ch;
  } while ((ch == 'y') || (ch == 'Y'));
  back_page();
  getch();
}

//Defination of Global Functions Starts

void create() //Creating New Record
{

  ofstream air_file;
  air_file.open("Airtel.dat", ios::binary | ios::out | ios::app);
  if (air_file.eof())
  {
    cout << "\n  File can not be Opened  ";
    getch();
    exit(0);
  }

  Airtel a;
  char ch = 'y';

  do
  {

    a.input_details();
    air_file.write((char *)&a, sizeof(a));
    cout << "\n\n  Record Added !  ";
    cout << "\n\n  Want To Add Another Record ? (Y/N) :  ";
    cin >> ch;
  } while ((ch == 'y') || (ch == 'Y'));
  air_file.close();
}

void search() //Searching Existing Record
{

  clrscr();
  ifstream air_file;
  air_file.open("Airtel.dat", ios::binary | ios::in);
  if (air_file.eof())
  {
    cout << "\n  File can not be Opened  ";
    getch();
    exit(0);
  }

  Airtel a;
  char num[11];
  int x;
  int pos = 0;
  cout << "\n\n  Enter Customer's PHONE NO :  ";
  gets(num);
  air_file.read((char *)&a, sizeof(a));

  while (air_file && pos == 0)
  {

    if (!strcmp(num, a.get_phone_no()))
    {

      cout << "\n  Wait for a While. Searching.....  ";
      for (double i = 0; i < 999999999; i++)
        ; //To Delay the Execution
      cout << "\n\n  Record Found !  ";
      cout << "\n\n  What Do You Want To Do ?  ";
      cout << "\n\t  1. View Details  ";
      cout << "\n\t  2. Generate Bill  ";
      cout << "\n\t  3. OR Both  ";
      cout << "\n\n  Enter Your Choice (1-3) :  ";
      cin >> x;

      if (x == 1)
      {
        clrscr();
        a.print_details();
      }
      else if (x == 2)
      {
        clrscr();
        a.bill();
      }
      else if (x == 3)
      {
        clrscr();
        a.print_details();
        a.bill();
      }
      else
      {
        cout << "\n  SORRY ! Invalid Input !  ";
      }
      pos++;
    }
    air_file.read((char *)&a, sizeof(a));
  }

  if (pos == 0)
  {
    cout << "\n  Wait for a While.Searching.....  ";
    for (double i = 0; i < 999999999; i++)
      ; //To Delay the Execution
    cout << "\n\n  SORRY ! This Customer Does Not Exist In Our Records ";
  }
  air_file.close();
}

void delete_details() //Deleting Existing Record
{

  clrscr();
  ofstream file;
  file.open("New.dat", ios::binary);
  if (file.eof())
  {
    cout << "\n  File can not be Opened  ";
    getch();
    exit(0);
  }

  ifstream oldfile;
  oldfile.open("Airtel.dat", ios::binary);
  Airtel a;
  if (oldfile.eof())
  {
    cout << "\n  File can not be Opened  ";
    getch();
    exit(0);
  }
  char num[11];
  int pos = 0;
  cout << "\n\n  Enter Customer's PHONE NO :  ";
  gets(num);
  oldfile.read((char *)&a, sizeof(a));

  while (oldfile)
  {

    if (!strcmp(num, a.get_phone_no()))
    {
      pos++;
      cout << "\n\n  Record Deleted !  ";
    }
    if (strcmp(num, a.get_phone_no()))
    {
      file.write((char *)&a, sizeof(a));
    }
    oldfile.read((char *)&a, sizeof(a));
  }
  if (pos == 0)
    cout << "\n\n  Record Not Found !  ";
  oldfile.close();
  file.close();
  remove("Airtel.dat");
  rename("New.dat", "Airtel.dat");
}

void front_page() //To Display Front Page
{

  cout << "\n\n\t\t\t  AIRTEL CUSTOMER CARE  \n";
  cout << "\t\t\t ----------------------  \n\n";
  cout << "\n\n  BY Mohd. Aftab Alam  ";
  cout << "\n\n\n  the Software will help you with the Following :  ";
  cout << "\n\n  ==>  Creating New Record  ";
  cout << "\n\n  ==>  Searching Existing Record :  ";
  cout << "\n\t\t  *>  To View Details  ";
  cout << "\n\t\t  *>  To Generate Bill  ";
  cout << "\n\n  ==>  Deleting Existing Record  ";
}

void back_page() //To Display Back Page
{

  clrscr();
  cout << "\n\n\n\n\t\t *** Hope You Had A Wonderful Experiance *** ";
  cout << "\n\n\n\t\t  *** Thank You For Using Our Services ***  ";
}

//Defination of Global Functions Ends

//THE  END
