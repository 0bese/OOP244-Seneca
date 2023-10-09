# Workshop #5: Member Operators, Helper functions
Version 0.8 Under review

In this workshop, you will implement different types of operator overload in a partially developed class.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create binary member operators
- define and create type conversion operators
- define and create unary operators
- define and create helper operator between a primitive type and a class.

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit you work up to 2 days after due date with 30% penalty for each day. After that the submission will be closed and the mark will be zero.

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


# LAB (50%) The Flight module.

Your task for this lab is to complete the implementation of the **Flight** module for holding the name of the flight ( a string ) number of passengers that boarded the plane (an integer) and fuel loaded into the plane fuel tank (a double value). 

# The Flight class
The Flight class has three attributes; a cstring for the name of the flight (**m_title**) and a double for fuel loaded into the plane fuel tank (**m_fuel**) and an integer for the number of passengers that boarded the plane (**m_passengers**) 

The **Flight** class can be in three different states: 

* Empty Plane <br />
A Flight is considered Empty when zero passengers have boarded. This state of the **Flight** class is flagged by setting the (**m_passengers**) to **0**.


* Low Fuel <br />
A Flight is in the **Low Fuel** state if the amount of fuel in the plane's tank  (**m_fuel**)  is less than the minimum required to carry the number of passengers currently onboard the plane.  The plane needs a minimum of 600 Liters of fuel for each passenger. 


* Ready to Depart<br />
A **Flight** is considered **Ready to Depart** if there is at least one passenger on board, and the fuel requirement is met. 

## Already implemented parts:
### Constructors
The **Flight** can be created in two different ways:
- default constructor *(implemented)* 
```C++
  Flight();
```
The default constructor sets the Flight name as **EmptyPlane** with the number of passengers to **0**, and fuel in the tank to **0.00**  
- Three argument constructor (integer,  double, and string) *(implemented)*
```C++
  Flight(int passengers, double fuel, const char* title);
```
The three-argument constructor sets the Flight number of passengers, Flight fuel, and flight title to incoming arguments only if the number of passengers is greater than **0**, and less than or equal to the Boeing 747 Max Capacity of **388**, Flight fuel is a positive number, and less than or equal to the Boeing 747 fuel Tank Max Capacity **238840**.  If any of these conditions are not met the Flight is set to **EmptyPlane** state.

### display function. 
```C++
   ostream& display() const
```
Displays the Flight on the screen.<br />
If the Flight is empty, it is going to print:  **Flight  |  Empty Plane**. If the Flight is low on Fuel Flight, it will print instead **Flight  |  Low on Fuel** and will also display the details of the flight.  If the flight is ready to depart it will display**Flight  |  Ready to depart** and will also display the details of the flight. <br />
At the end **display** will return the **cout** object.

## To be implemented:
### type conversion operators
- **operator bool**<br />
Returns **true** if the Flight number of passengers is greater than **0**, and the amount of fuel in the plane's tank is equal to or greater than the minimum required to carry the number of passengers currently on the plane. otherwise **false**. This operator can not modify the **Flight** object.
- **operator int**<br />
Returns the **Flight number of passengers**. This operator can not modify the **Flight** object.
- **operator double**<br />
Returns the **Flight Fuel**. This operator can not modify the **Flight** object.

- **operator const char***<br />
Returns the **Flight Title**. This operator can not modify the **Flight** object.

### Unary member operator
- **bool operator ~**<br />
This operator returns **true** if the Flight number of passengers is equal to  **0**, otherwise, it will return **false**.  This operator can not modify the **Flight** object.

### Binary member operators


#### assignment operators

- overload the **assignment operator** so a **Flight** can be set to another **Flight** object. This action should **move** the Flight passengers and the Flight fuel, Flight title from one Flight to another; therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the details of the left Flight will be set to the details of the right Flight and the right Flight number of passengers will be set to  **0**, fuel to  **0.00**, and title to **EmptyPlane**. <br />

A reference of the **current object** (**Flight**) should be returned. 



- Overload the **assignment operator** so a **Flight** can be set to an **integer**. Doing so should set the **Flight number of passengers** of the **Flight** to the **integer value**, only if the **integer value** is positive and less than or equal to the Boeing 747 Passenger Max Capacity. <br />

A reference of the **current object** (**Flight**) should be returned. 

- Overload the **assignment operator** so a **Flight** can be set to a **double**. Doing so should set the **Flight fuel** of the **Flight** to the **double value**, only if the **double value** is positive and less than the Boeng747 Fuel Tank Max Capacity. <br />

A reference of the **current object** (**Flight**) should be returned. 

- Overload the **+= operator** to add a double value to a Flight. This should act like adding fuel into the Flight Tank. (i.e. the value of the double should be added to the m_fuel)<br />

If the double value is negative or Flight Tank is full, no action should be taken.  You can fill the Flight Tank with more fuel, the double value, until the Flight Tank is full <br />
In any case, a reference of the **current object** (**Flight**) should be returned. 

- Overload the **+= operator** to add an integer value to a Flight. This should act like adding more passengers to the Flight. (i.e. the value of the integer should be added to the m_passengers)<br />

If the integer value is negative or Flight full, no action should be taken.  You can board more passengers into the Flight, the integer value, until the Flight FULL <br />

In any case, a reference of the **current object** (**Flight**) should be returned. 

- overload the **-= operator** to reduce a Flight fuel by a double value. This should act like pumping out fuel from the Flight Fuel Tank. (i.e. the value of the Flight fuel should be reduced by the double value)<br />

If the double value is negative no action should be taken.  You can pump fuel out of the Flight Tank until is empty.  It is not allowed for the **m_fuel** to be a negative number<br />
In any case, a reference of the **current object** (**Flight**) should be returned. 

- Overload the **-= operator** to reduce the number of passengers in a Flight fuel by an integer value. This should act like disembarking a number of passengers from the Flight. (i.e. the value of the Flight m_passengers should be reduced by the integer value)<br />

If the integer value is negative no action should be taken.  The maximum you can deplane is the number of passengers the Flight currently has.  It is not allowed for the **m_passengers** to be a negative number<br />
In any case, a reference of the **current object** (**Flight**) should be returned. 


- Overload the **<< operator*** (left shift operator) to move passengers from the right Flight to the left. After this operation, the total number of passengers in the left Flight will be the sum of both up to the Maximum Capacity of the Boeing 747, and the number of passengers in the right Flight will be zero or the remaining number of passengers after the left plane reached its maximum capacity.<br />

It is not allowed to move passengers from a plane back to itself.  If any of the two flights don't evaluate to **TRUE**,  no action should be taken.

A reference of the **current object** (**Flight**) should be returned. 


- Overload the **>> operator** (right shift operator) to move passengers from the left Flight to the right. After this operation, the total number of passengers in the right Flight will be the sum of both up to the Maximum Capacity of the Boeing 747, and the number of passengers in the left Flight will be zero or the remaining number of passengers after the right plane reached its maximum capacity.<br />

It is not allowed to move passengers from a plane back to itself.  If any of the two flights don't evaluate to **TRUE**,  no action should be taken.

A reference of the **current object** (**Flight**) should be returned. 

- Overload the binary member **+ operator** that accepts a **constant Flight reference** and returns a **int** value. <br />
The **int** value should be the **sum** of the **number of passengers** of the current flight and the other Flight.<br />
If any of the two Flights don't evaluate to  **TRUE**, then **zero** is returned.<br />
This operator can not modify the **Flight** objects.


### Binary helper operator

-- create a binary stand alone helper **+= operator** that accepts an **int reference** at left and a **constant Flight reference** at right and returns an **int** value. <br />
The number of the passengers of the right operand (Flight reference) should be added to the left operand (integer reference) <br />
Then the value of the integer reference is returned. 



## The tester program.

[main.cpp](lab/main.cpp)

## Expected output

[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  
```Text
Flight.cpp
Flight.h
main.cpp
```

### Data Entry

No data entry required.

### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```bash
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail


> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

# DIY (50%)
> Please note that you can (and probably should) add more member functions to make the DIY part work.


An Investment Portfolio could be in any range of financial instruments such as stocks, commodities, cash, etc. 

In this part of the lab, you will create a Module with the name **Portfolio**.

## The Portfolio class
### Already implemented parts:
#### Constructors
*(implemented)* 

#### display function. 
*(implemented)*

#### Operator and conversion overloads
- Portfolio can be casted to a double (double type). The result would be the value of the Portfolio **m_value**. This operator can not modify the **Portfolio** object.

- Portfolio can be casted to C-string (const char* type). The result would be the name of the stock **m_stock**. This operator can not modify the **Portfolio** object.

- Portfolio can be casted to a char (char type). The result would be the type of investment **m_type**. This operator can not modify the **Portfolio** object.

- Portfolio can be casted to a bool (boolean type). This will return TRUE if the type of the investment **m_type** is Growth 'G' or Value 'V or Investment 'I'. For any other types, it will return FALSE.

- A double can be added to the value of the Portfolio **m_value** using += operator; if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted. Reference of the Portfolio is returned after the operation.

- A double can be subtracted from the value of the Portfolio **m_value** using -= operator; if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted. Reference of the Portfolio is returned after the operation.

- The **bool operator ~()** will return true if **m_value** is negative. This operator can not modify the **Portfolio** object.

- overload the **<< operator*** (left shift operator) to move $dollar investment value **m_value** from Portfolio in the right to the left.  After this operation, the total investment value of the Portfolio on the left will be the sum of both Portfolios.  The Portfolio on the right is set to empty.

It is not allowed to invest values from a Portfolio back to itself.  If any of the two portfolios don't evaluate to **TRUE**,  no action should be taken.

- overload the **>> operator*** (right shift operator) to move $dollar investment value **m_value** from Portfolio in the left to the right.  After this operation, the total investment value of the Portfolio in the right will be the sum of both Portfolios.  The Portfolio on the left is set to empty.

It is not allowed to invest values from a Portfolio back to itself.  If any of the two portfolios don't evaluate to **TRUE**,  no action should be taken.
  
### Binary helper operators

- create a binary stand alone helper **+ operator** that accepts a **constant Portfolio reference** at left and another **constant Portfolio reference** at right and returns a **double** value. <br />
The **double** value should be the **sum** of the **m_values** of the two Flights.<br />
If any of the two Portfolios don't evaluate to  **TRUE**, then **zero** is returned.<br />

- create a binary stand alone helper **+= operator** that accepts a **double reference** at left and a **constant Portfolio reference** at right and returns a **double** value. <br />
The $dollar investment value of the right operand (Portfolio reference) should be added to the left operand (double reference) <br />
Then the value of the double reference is returned. 


## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output

[correct_output.txt](DIY/correct_output.txt)


> Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  
```Text
Portfolio.h
Portfolio.cpp
main.cpp
```


### Data Entry

No data entry required.

### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```bash
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



