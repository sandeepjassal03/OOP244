# Workshop #3: Member Functions and Privacy
* version 0.8  Submission is not open yet
* version 0.81 minor changes to clarify the steps
* version 0.9 Overview Session scheduled and Submissions open.
* version 0.91 Corrected the Overview Session date
* version 1.0 changed argument names not to match the attribute names
* version 1.1 Overview session corrections

In this workshop, you will use member functions, privacy, safe empty state and formatting of the output to complete your work.

## Workshop Online Overview Session.

The overview session will go through the workshop, explaining the steps and answering questions you might have.

The session will be online on BigBlueButton. Click on the link below 5 minutes before the session begins to join the session. 

### No listen only connections please
Make sure your microphone is set up and join with the microphone. This is an interactive session, avoid "Listen only" connections unless you REALLY have to.

[Click HERE to join the session](https://connect.rna2.blindsidenetworks.com/invite/to?c=YMcmr2B1j_Pq3papimNxoGXTQzb-9N3FCGTd-wulnek&m=df35c27d0f1972926dfb207f1c195b8402c73621&t=1664309714067&u=senecacollege)

### Overview session recordings
[Click here to view the recording](https://youtu.be/I-Eww9ImAIY)


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- to define a class type
- to privatize data within the class type
- to instantiate an object of class type
- to use member functions to query the state of an object
- to use member functions to change the state of an object
- to use standard library facilities to format data inserted into the output stream
- to describe to your instructor what you have learned in completing this workshop

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

Depending on the section you are enrolled in, the submission due day of the week may shift a day or two. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]

### Overall workshop due days
- day 1: Workshop open for preview<br/>
  (If you need to check your program with the submitter, you can use `-feedback` option to test the execution without submission)
- day 2: submission opens for both parts 1 and 2
- day 5: (end of day) Part 1 due
- day 8: (end of day) Part 2 due
- day 9: (end of day) submissions rejected

If at the deadline (end of day 8) the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.

### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

# Part 1 - LAB (50%)

Your task for part one of workshop 3 is to create a class called "CC" that encapsulates a Credit Card. (in CC.h and CC.cpp) and displays the credit card information in two formats: row and form.

## Attributes
This class must keep the following information:

- **The cardholder's name:** that is held dynamically in a C string.  (`char *`)
- **CVV**, **expiry month**, and **expiry year**: that are all held in short integers. (`short`)
- **Credit card number**: that is held in an unsigned long long integer (`unsigned long long`)

## Private methods
The CC class has the following Private functions:

```C++
bool validate(const char* name, 
              unsigned long long cardNo, 
              short cvv, 
              short expMon, 
              short expYear)const;
```
This function validates the credit card information as follows:
- name: should not be null and should be more than 2 characters long
- carNo: values between 4000000000000000 and 4099999999999999
- cvv: a three-digit number
- expMon: values between 1 and 12
- expYear: values between 22 and 32
  
it will return true if all the conditions are met, otherwise it will return false

This function does not modify the object.

```C++
void prnNumber()const;
```
This function prints a 16-digit number in a set of 4-digit numbers separated by spaces.

Forexample:  

`4098645375646543` will be printed as `4098 6453 7564 6543`

You can accomplish this by using the division and modulus operations. 

First, divide the number by 1000000000000 to get the left four digits and print it. Then extract the right 12 digits by using modulus and repeat this method until all the numbers are printed.

This function does not modify the object.

## Public methods

```C++
void set();
```
Sets the object to a safe empty state by setting all the values to zero and nullptr.

```C++
void cleanUp();
```
First, it will deallocate the cardholder's name and then calls the `set()` to set the object to a safe empty state.


```C++
bool isEmpty() const;
```
Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute of the object is nullptr, otherwise, it will return false.

```C++
void set(const char* cc_name, 
         unsigned long long cc_no, 
         short cvv, 
         short expMon, 
         short expYear);
```
First, it will `cleanUp()` the object. Then if all the arguments are valid using `validate()`, it will dynamically keep a copy of the name in the name attribute and set the rest of the attributes to their corresponding values. 

If any of the arguments are invalid, nothing will be set.

```C++
 bool read();
```
Assuming that the names are not longer than 70 characters, this function will attempt to read all the values from the console in local (`function scope`) variables first and if successful, they will be validated and then stored in the object.   

The function will return true if the values are stored in the object and false otherwise.

Follow these steps to write this function:
Create an array of 71 characters for the name and temporary variables for other attributes of the class.

The function will first call `cleanUp()` to deallocate possible previous data allocation and reads the values into local function scope variables as follows:

- Prompt `"Card holder name: "`
- using `cin.getline()` read 71 characters into a local name cstring.
- if cin has not failed prompt `"Credit card number: "`
- read the credit card number into a local unsigned long long variable.
- if cin has not failed prompt `"Card Verification Value (CVV): "`
- read the CVV number into a local short integer
- if cin has not failed prompt `"Expiry month and year (MM/YY): "`
- reads the expiry `month` and `year`  into short integer variables in one line by `cin.ignore()ing` the delimiter between them, you don't need to make sure it is a '/' character. This separator can be any non-digit character to separate the month and year values.
- check the status of cin to set the object:
   - if cin has not failed, call the set(name, no, cvv, mon,year) function to set the object
   - if cin has failed, `clear()` the cin.
- in any case, flush the keyboard using ignore
- at end return false if object `isEmpty()` and return true if not.



```C++
void display(int row = 0) const;
```
If the object `isEmpty()`, print `"Invalid Credit Card Record"`;

If it is not in a safe empty state, depending on the value of the row being greater than zero or not, print the CC information in a row, or in a form format respectively:

#### if row > 0:

When printing, all the values have one space between them and the separator bar (see example).

- row: right justified in 3 spaces 
- Name: left justified in 30 spaced
- Card number: printed using `prnNumber`
- cvv: printed as is
- Month: right justified in 2 spaces
- slash ('/')
- year: printed as it.
- newline

Example:
```text
|  30 | Homer Simpson                  | 4089 0511 8229 9500 | 815 |  6/30 |
```
> note: using `cout.setf(ios::left)` or `cout.setf(ios::right)`, its a good practice to `unsetf` them after printing the field (ie. `cout.unsetf(ios::left)` or `cout.unsetf(ios::right)`).  This will put `cout` back in its neutral state.


#### if row < = 0

Display the CC information in the following way (no formatting, other than the prnNumber function)

```text
Name: Hubert Blaine
Creditcard No: 4098 7654 2345 7896
Card Verification Value: 123
Expiry Date: 5/25
```



## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop 3 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream> // works like istream (cin) but for files
#include <cstdio>
#include "CC.h"
using namespace std;
using namespace sdds;
void listCCs();
int main() {
   CC cc;
   cc.set();
   cc.set("Hubert Blaine", 4098765423457896, 123, 5, 25);
   cout << "Valid credit card record: " << endl;
   cc.display();
   cout << "------------------------------------------------------" << endl; 
   cout << "Valid credit card with very long name: " << endl;
   cc.set("Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.", 4098765423457896, 123, 5, 25);
   cc.display();
   cout << "------------------------------------------------------" << endl;
   cout << endl << "reading Tests: " << endl;
   cout << "Enter the following values:" << endl
      << "Fred<ENTER>\naaa<ENTER>" << endl;
   if(cc.read()) {
      cout << "This should have failed right after card entry!" << endl;
   }
   else {
      cout << "aaa is not a valid number!" << endl;
   }
   cout << "Enter the following values:" << endl
      << "Fred<ENTER>\n123<ENTER>\nbbb<ENTER>" << endl;
   if(cc.read()) {
      cout << "This should have failed right after card entry!" << endl;
   } else {
      cout << "bbb is not a valid number!" << endl;
   }
   cout << "Enter the following values:" << endl
      << "Fred<ENTER>\n123<ENTER>\n123<ENTER>\n11/11<ENTER>" << endl;
   if(cc.read()) {
      cout << "This should have failed right after card entry!" << endl;
   } else {
      cout << "Values are readable but not valid credit card information!" << endl;
   }
   cout << "Press Enter to start validation tests, all the following must fail." << endl;
   cin.ignore(1000, '\n');
   cc.set("HB", 4098765423457896, 123, 5, 25);
   cc.display();
   cc.set(nullptr, 4098765423457896, 123, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 3999999999999999, 123, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4100000000000000, 123, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 99, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 1000, 5, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 0, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 13, 25);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 5, 21);
   cc.display();
   cc.set("Hubert Blaine", 4098765423457896, 123, 5, 33);
   cc.display();
   cc.cleanUp();
   cout << "Press Enter to test the row display. Formatting test..." << endl;
   cin.ignore(1000, '\n');
   listCCs();
   return 0;
}
void listCCs() {
   char name[71]{};
   unsigned long long no{};
   short cvv{};
   short expMon{};
   short expYear{};
   CC cc;
   cc.set();
   ifstream filein("cc.csv");
   int row = 1;
   cout << "|     |                                |                     |     | Expiry|" << endl;
   cout << "| Row | Card holder name               | Credit card number  | CVV | MM/YY |" << endl;
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;

   do {
      filein.getline(name, 71, ',');
      filein >> no;
      filein.ignore();
      filein >> cvv;
      filein.ignore();
      filein >> expMon;
      filein.ignore();
      filein >> expYear;
      filein.ignore();
      if(filein) {
         cc.set(name, no, cvv, expMon, expYear);
         cc.display(row++);
      }
   } while(filein);
   cout << "+----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.cleanUp();
}
```
## Execution Sample

```text
Valid credit card record:
Name: Hubert Blaine
Creditcard No: 4098 7654 2345 7896
Card Verification Value: 123
Expiry Date: 5/25
------------------------------------------------------
Valid credit card with very long name:
Name: Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.
Creditcard No: 4098 7654 2345 7896
Card Verification Value: 123
Expiry Date: 5/25
------------------------------------------------------

reading Tests:
Enter the following values:
Fred<ENTER>
aaa<ENTER>
Card holder name: Fred
Credit card number: aaa
aaa is not a valid number!
Enter the following values:
Fred<ENTER>
123<ENTER>
bbb<ENTER>
Card holder name: Fred
Credit card number: 123
Card Verification Value (CVV): bbb
bbb is not a valid number!
Enter the following values:
Fred<ENTER>
123<ENTER>
123<ENTER>
11/11<ENTER>
Card holder name: Fred
Credit card number: 123
Card Verification Value (CVV): 123
Expiry month and year (MM/YY): 11/11
Values are readable but not valid credit card information!
Press Enter to start validation tests, all the following must fail.

Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Invalid Credit Card Record
Press Enter to test the row display. Formatting test...

|     |                                |                     |     | Expiry|
| Row | Card holder name               | Credit card number  | CVV | MM/YY |
+-----+--------------------------------+---------------------+-----+-------+
|   1 | Abraham Simpson                | 4012 0304 5093 6880 | 543 | 11/27 |
|   2 | Agnes Skinner                  | 4042 0463 9151 1300 | 336 |  2/22 |
|   3 | Akira Kurosawa                 | 4072 4709 2063 0570 | 380 |  5/22 |
|   4 | Alice Glick                    | 4045 3069 7101 6370 | 558 | 10/27 |
|   5 | Allison Taylor                 | 4044 9880 6004 1360 | 634 | 10/23 |
|   6 | Apu Nahasapeemapetilon         | 4062 8292 7668 2490 | 895 |  7/32 |
|   7 | Artie Ziff                     | 4042 5561 0941 5380 | 483 | 12/24 |
|   8 | Baby Gerald                    | 4042 0856 2992 2780 | 162 |  3/30 |
|   9 | Barney Gumble                  | 4040 9829 5631 5120 | 799 |  9/26 |
|  10 | Bart Simpson                   | 4076 4013 8517 0770 | 641 | 11/29 |
|  11 | Bernice Hibbert                | 4041 8536 0518 7420 | 379 |  6/25 |
|  12 | Brandine Spuckler              | 4008 9484 2517 5710 | 788 |  6/31 |
|  13 | Bumblebee Man                  | 4093 2118 6115 7700 | 273 |  7/24 |
|  14 | Carl Carlson                   | 4069 1381 4031 9260 | 935 |  1/29 |
|  15 | Chazz Busby                    | 4004 4052 2425 1240 | 444 | 11/27 |
|  16 | Cletus Spuckler                | 4045 2329 9910 2640 | 363 |  6/26 |
|  17 | Comic Book Guy                 | 4007 3061 9272 9270 | 961 |  7/24 |
|  18 | Dewey Largo                    | 4099 1396 2669 0960 | 955 | 11/32 |
|  19 | Disco Stu                      | 4006 8268 3456 5050 | 241 |  3/23 |
|  20 | Dolph Starbeam                 | 4018 3782 5225 6280 | 975 |  5/29 |
|  21 | Drederick Tatum                | 4034 8603 9745 0550 | 820 |  7/24 |
|  22 | Edna Krabappel                 | 4051 1122 1629 8740 | 922 |  3/24 |
|  23 | Elizabeth Hoover               | 4029 7021 3249 4360 | 252 | 10/29 |
|  24 | Gil Gunderson                  | 4063 8362 0058 9550 | 412 |  2/30 |
|  25 | Gloria Jailbird                | 4091 5678 8277 1220 | 919 |  6/23 |
|  26 | Groundskeeper Willie           | 4075 0820 0250 8710 | 143 |  3/28 |
|  27 | Hans Moleman                   | 4004 9963 9969 6390 | 470 |  5/27 |
|  28 | Helen Lovejoy                  | 4099 2117 6594 1340 | 959 |  7/24 |
|  29 | Herman Hermann                 | 4051 4179 0302 9720 | 499 | 11/23 |
|  30 | Homer Simpson                  | 4089 0511 8229 9500 | 815 |  6/30 |
|  31 | Jacqueline Bouvier             | 4084 3766 4930 0010 | 707 |  4/27 |
|  32 | Janey Powell                   | 4097 8322 0444 8380 | 595 |  4/28 |
|  33 | Jasper Beardly                 | 4025 8087 2766 0100 | 150 |  4/28 |
|  34 | Jessica Lovejoy                | 4076 0628 4206 6590 | 465 |  9/30 |
|  35 | Jimbo Jones                    | 4035 3920 2314 4010 | 973 |  6/31 |
|  36 | Johnny Tightlips               | 4058 1325 0122 4250 | 583 | 11/23 |
|  37 | Judge Roy Snyder               | 4088 0531 4737 1690 | 634 |  3/23 |
|  38 | Kearney Zzyzwicz               | 4043 0678 4543 8600 | 108 |  5/28 |
|  39 | Kent Brockman                  | 4040 7016 2277 2900 | 402 |  9/32 |
|  40 | Kirk Van Houten                | 4042 5969 9130 6260 | 183 |  5/22 |
|  41 | Krusty The Clown               | 4071 7799 4052 1810 | 105 | 10/31 |
|  42 | Kumiko Albertson               | 4015 2534 9118 9570 | 437 | 10/29 |
|  43 | Lenny Leonard                  | 4007 2522 6965 0990 | 478 |  2/23 |
|  44 | Lindsey Naegle                 | 4049 0768 1341 0570 | 397 | 11/23 |
|  45 | Ling Bouvier                   | 4098 8136 1588 8300 | 182 |  8/31 |
|  46 | Lionel Hutz                    | 4001 5289 3435 2310 | 323 |  7/25 |
|  47 | Lisa Simpson                   | 4036 4106 5434 0270 | 145 |  6/27 |
|  48 | Luann Van Houten               | 4047 0700 5409 5800 | 568 |  2/25 |
|  49 | Luigi Risotto                  | 4088 5872 1729 2090 | 567 |  1/22 |
|  50 | Lunchlady Doris                | 4055 2813 8901 0150 | 201 |  4/24 |
|  51 | Maggie Simpson                 | 4064 0024 2510 8890 | 337 |  9/31 |
|  52 | Manjula Nahasapeemapetilon     | 4009 5924 8223 9410 | 142 |  2/29 |
|  53 | Marge Simpson                  | 4002 4454 5830 7380 | 555 |  9/27 |
|  54 | Martin Prince                  | 4059 7702 1745 5840 | 788 |  3/27 |
|  55 | Maude Flanders[D]              | 4034 6632 5706 6840 | 700 |  4/28 |
|  56 | Mayor Joe Quimby               | 4083 1894 9999 2960 | 525 |  4/25 |
|  57 | Milhouse Van Houten            | 4032 8474 3158 0090 | 119 | 12/27 |
|  58 | Miss Springfield               | 4074 7481 1091 5720 | 599 | 10/22 |
|  59 | Moe Szyslak                    | 4099 7353 9411 0140 | 797 | 10/30 |
|  60 | Mona Simpson                   | 4093 2268 6828 0220 | 233 |  5/27 |
|  61 | Ned Flanders                   | 4052 5988 7854 4440 | 448 |  6/22 |
|  62 | Nelson Muntz                   | 4027 7426 4236 1430 | 365 |  5/23 |
|  63 | Old Jewish Man                 | 4018 2928 0329 6190 | 428 |  7/29 |
|  64 | Patty Bouvier                  | 4016 1411 5071 1400 | 319 | 10/24 |
|  65 | Rabbi Hyman Krustofsky         | 4026 1668 9542 3890 | 909 |  9/31 |
|  66 | Rainier Wolfcastle             | 4075 8477 9623 3210 | 768 |  8/23 |
|  67 | Ralph Wiggum                   | 4068 3987 3135 0700 | 273 | 10/32 |
|  68 | Rod Flanders                   | 4046 8093 3643 3120 | 466 |  7/23 |
|  69 | Roger Meyers Jr.               | 4025 9688 9492 2520 | 869 |  2/24 |
|  70 | Ruth Powers                    | 4044 5996 0696 0030 | 226 |  6/23 |
|  71 | Sarah Wiggum                   | 4079 5360 5556 5390 | 264 |  8/24 |
|  72 | Sea Captain                    | 4036 7551 9712 5620 | 422 |  5/24 |
|  73 | Selma Bouvier                  | 4055 4352 1777 6770 | 321 |  5/26 |
|  74 | Seymour Skinner                | 4003 9658 9816 7660 | 694 | 11/27 |
|  75 | Shauna Chalmers                | 4084 9945 0723 7530 | 836 |  4/26 |
|  76 | Sideshow Mel                   | 4083 2708 0096 4480 | 389 |  3/30 |
|  77 | Snake Jailbird                 | 4036 1371 6724 8070 | 132 | 10/32 |
|  78 | Squeaky-Voiced Teen            | 4052 4291 9612 0580 | 862 |  6/28 |
|  79 | Surly Duff                     | 4050 4367 5792 2640 | 912 |  8/23 |
|  80 | The Rich Texan                 | 4086 8890 4744 7940 | 328 |  5/25 |
|  81 | Todd Flanders                  | 4088 2541 8250 3370 | 617 | 10/30 |
|  82 | Troy McClure                   | 4016 3907 5769 0770 | 452 | 10/26 |
|  83 | Uter Zorker                    | 4036 7255 4412 6900 | 253 | 10/27 |
|  84 | Waylon Smithers                | 4091 6939 0931 0650 | 726 |  9/30 |
|  85 | Wendell Borton                 | 4092 4524 5743 7810 | 213 |  7/32 |
|  86 | Wise Guy                       | 4084 6255 1909 8910 | 581 |  8/28 |
|  87 | Hubert Blaine Wolfeschlegelste | 4098 7654 2345 7896 | 123 |  5/25 |
+-----+--------------------------------+---------------------+-----+-------+

```

## PART 1 Submission (lab)

### Files to submit:  

```Text
CC.h
CC.cpp
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

Follow the instructions of the tester.

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



# DIY (50%) 

Your task for the DIY section is to create a NameTag class to hold a name up to 50 chars (not dynamic) and print it with a frame around it. 

Then you must create a class called TagList that holds a dynamic array of NameTags and prints all the tags with the frame size matching the longest name in the list.

## NameTag class
A name tag holding "Fred Soley" is printed as follows:

Smallest frame possible:
```text
**************
* Fred Soley *
**************
```
Or it can be printed with bigger frame and the name will be left justified in it:
```text
*******************************
* Fred Soley                  *
*******************************
```

The length of the frame must be modifiable (using a modifier method) so the TagList be able to change it, to set all the frames to the same size.


### Methods of NameTag used in the main.
Only one method of the NameTag is used in the main function:  
  
```C++
void set(const chat* name).
```
This method sets the name, held by the NameTag object.

The rest of the methods or attributes of NameTag are to be designed by you. 

## TagList

TagList needs to have the following methods:

```C++
void set();
```
Sets the TagList to an empty state
```C++
void set(int num);
```
Calls `CleanUp()` and then dynamically creates an array of `num` NameTags.

```C++
void add(const NameTag& nt);
```
Adds up to `num` (of the set method) NameTags to the TagList.
```C++
void print();
```
Prints all the tags with the same size that is the frame size of the longest name in the list.
```C++
void cleanup();
```
Deallocates the NameTags and put the TagList back to a safe empty state. 

## Tester Program
```C++
/***********************************************************************
// OOP244 Workshop 3 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "TagList.h"
#include "NameTag.h"
using namespace sdds;
int noOfNames(FILE* fptr) {
   char ch;
   int recs = 0;
   rewind(fptr);
   while(fscanf(fptr, "%c", &ch) == 1) {
      recs += (ch == '\n');
   }
   rewind(fptr);
   return recs;
}
int main() {
   char name[51]{};
   FILE* fptr = fopen("simpsons.txt","r");
   NameTag nt;
   TagList tl;
   tl.set();
   tl.set(noOfNames(fptr));
   while(fscanf(fptr, "%[^\n]\n", name) == 1) {
      nt.set(name);
      tl.add(nt);
   }
   tl.print();
   tl.cleanup();
   fclose(fptr);
   return 0;
}
```
## Execution Sample

```text
******************************
* Baby Gerald                *
******************************
******************************
* Groundskeeper Willie       *
******************************
******************************
* Dolph Starbeam             *
******************************
******************************
* Kirk Van Houten            *
******************************
******************************
* Artie Ziff                 *
******************************
******************************
* Edna Krabappel             *
******************************
******************************
* Luann Van Houten           *
******************************
******************************
* Janey Powell               *
******************************
******************************
* Akira Kurosawa             *
******************************
******************************
* Luigi Risotto              *
******************************
******************************
* Homer Simpson              *
******************************
******************************
* Selma Bouvier              *
******************************
******************************
* Wendell Borton             *
******************************
******************************
* Manjula Nahasapeemapetilon *
******************************
******************************
* Kearney Zzyzwicz           *
******************************
******************************
* Brandine Spuckler          *
******************************
******************************
* Moe Szyslak                *
******************************
******************************
* Ralph Wiggum               *
******************************
******************************
* Rod Flanders               *
******************************
******************************
* Gloria Jailbird            *
******************************
******************************
* Gil Gunderson              *
******************************
******************************
* Barney Gumble              *
******************************
******************************
* Krusty The Clown           *
******************************
******************************
* Agnes Skinner              *
******************************
******************************
* Bumblebee Man              *
******************************
******************************
* Helen Lovejoy              *
******************************
******************************
* Shauna Chalmers            *
******************************
******************************
* Disco Stu                  *
******************************
******************************
* Roger Meyers Jr.           *
******************************
******************************
* Carl Carlson               *
******************************
******************************
* Waylon Smithers            *
******************************
******************************
* Squeaky-Voiced Teen        *
******************************
******************************
* Bernice Hibbert            *
******************************
******************************
* Dewey Largo                *
******************************
******************************
* Mayor Joe Quimby           *
******************************
******************************
* Rabbi Hyman Krustofsky     *
******************************
******************************
* Kent Brockman              *
******************************
******************************
* Lindsey Naegle             *
******************************
******************************
* Ned Flanders               *
******************************
******************************
* Cletus Spuckler            *
******************************
******************************
* Herman Hermann             *
******************************
******************************
* Lunchlady Doris            *
******************************
******************************
* Uter Zorker                *
******************************
******************************
* Rainier Wolfcastle         *
******************************
******************************
* Sarah Wiggum               *
******************************
******************************
* Allison Taylor             *
******************************
******************************
* Martin Prince              *
******************************
******************************
* Todd Flanders              *
******************************
******************************
* Jimbo Jones                *
******************************
******************************
* Judge Roy Snyder           *
******************************
******************************
* Hans Moleman               *
******************************
******************************
* Jessica Lovejoy            *
******************************
******************************
* Milhouse Van Houten        *
******************************
******************************
* Marge Simpson              *
******************************
******************************
* Wise Guy                   *
******************************
******************************
* Miss Springfield           *
******************************
******************************
* Patty Bouvier              *
******************************
******************************
* Elizabeth Hoover           *
******************************
******************************
* Lisa Simpson               *
******************************
******************************
* Kumiko Albertson           *
******************************
******************************
* Jasper Beardly             *
******************************
******************************
* Seymour Skinner            *
******************************
******************************
* The Rich Texan             *
******************************
******************************
* Jacqueline Bouvier         *
******************************
******************************
* Sea Captain                *
******************************
******************************
* Apu Nahasapeemapetilon     *
******************************
******************************
* Sideshow Mel               *
******************************
******************************
* Mona Simpson               *
******************************
******************************
* Bart Simpson               *
******************************
******************************
* Ruth Powers                *
******************************
******************************
* Johnny Tightlips           *
******************************
******************************
* Troy McClure               *
******************************
******************************
* Abraham Simpson            *
******************************
******************************
* Surly Duff                 *
******************************
******************************
* Alice Glick                *
******************************
******************************
* Nelson Muntz               *
******************************
******************************
* Chazz Busby                *
******************************
******************************
* Lionel Hutz                *
******************************
******************************
* Comic Book Guy             *
******************************
******************************
* Lenny Leonard              *
******************************
******************************
* Ling Bouvier               *
******************************
******************************
* Maude Flanders[D]          *
******************************
******************************
* Drederick Tatum            *
******************************
******************************
* Snake Jailbird             *
******************************
******************************
* Maggie Simpson             *
******************************
```

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
NameTag.h
NameTag.cpp
TagList.h
TagList.cpp
main.cpp
```

### Data Entry

No data entry needed

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

