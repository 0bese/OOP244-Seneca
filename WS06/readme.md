# Workshop #6: Classes and resources, IO operators
# version 1.0

In this workshop, you will implement a class with overloaded constructors. Then you will overload IO operators that will be used to read and write on the screen and files.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and implement multiple constructors
- define and implement the rule of three
- Read formatted data using `istream`
- Write formatted data using `ostream`
- Overload the extraction and insertion operators for I/O, using iostream 

## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

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
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

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


> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace.

## Before starting with part 1, we will introduce two functions 

These two member functions are available in istream:

```C++
setstate(); 
peek();
```

- **setstate()** manually sets the status of the istream object to the desired state. In our case we will be calling `setstate` as follows to manually set any object of istream (like cin) to a **fail** state:

```C++
// Examples:
// assuming there is a funciton called readData as follows
istream& readData(istream& istr){
    type variable{};
    istr >> variable;
    if(/*logic for variable being invalid*/){
        istr.setstate(ios::failbit); // this manually sets istr to failure
                                     // if the variable is readable but not acceptable
    }
    return istr;
}
// Or:

int getAge(){
    int age{};
    cin >> age;
    if(age < 19){
        cin.setstate(ios::failbit); // this sets cin to fail if the age is bellow 19
    }
    return age;
}

void someLogic(){
    cout << "Enter your name: ";
    int age = getAge();
    if(cin.fail()){
       cout << "You are not old enough to consume alcoholic drinks in Ontario!" <<endl; 
       cin.clear();
    }
}

```

- **peek()** it peeks and checks the next character without extracting it from the keyboard. With this function, you can check and see what is the next character before reading it. 
setting m_name to nullptr before constructor invocation 

```C++
// Example
char next;
int value;

cout <<"Enter a number: ";
next = cin.peek();
if(next < '0' || next >'9'){ // checking if the next character in keyboard is not a digit
    cout << "You did not enter a number!";
}
else{
    cin >> value;
}
cin.ignore(1000, '\n'); // flush the invalid value or everything after the number.
```

## Part 1 - lab (50%), The HealthCard class

Your task for this part of your workshop is to complete the implementation of a class called HeathCard. This class encapsulates some basic health-card information of a person in Ontario using the following attributes:

```C++
 class HealthCard {
      char* m_name{}; 
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
    public:
      ...
   };
```

- **m_name** to hold the full name of a person which is Dynamically allocated
- **m_number** to hold the main health card number 
- **m_vCode** Version code of the card
- **m_sNumber** Stock Control Number


### Validation
These values are validated (considered **valid**) as follows:
   - Full name is a Cstring that is not null and not empty.
   - The main health number consists of 10 digits (>999999999 and <9999999999)
   - The version number consists of two characters
   - The Stock control number consists of nine characters
   
The HeathCard class is to validate and store the above information via initialization and data entry from istream.

Also, the HeathCard class must comply with the rule of three. (i.e. the implementation of copy constructor, copy assignment and destructor)

Although the name of the HealthCard is dynamically held, we can assume that the maximum length for a name is 55 characters. This value should be kept in a constant global variable so it can be changed at compile-time if needed.

```C+
   const int MaxNameLength = 55;
```

Finally, A HeathCard object should reveal its status (of being valid or invalid) via a Boolean type conversion overload (a true outcome means the object is valid and a false outcome means it is invalid).

To accomplish the above and have an organized and modular code, implement these private methods to help you with the implementation of the whole logic: (you can add more if you like to)

### Private Methods

#### bool validID(const char* name, long long number, const char vCode[] , const char sNumber[]) const; 
Returns true is the four parts of the ID card are valid. (see [Validation](#validation))

#### void setEmpty();
Sets the HeathCard object to a recognizable empty (invalid) state by setting **m_name** to nullptr;

#### void allocateAndCopy(const char* name);
- Free the memory pointed by **m_name** 
- Allocate enough memory to store **name** Cstring
- Copy the Cstring pointed by **name** into the newly allocated memory pointed by **m_name**

#### void HealthCard::extractChar(istream& istr, char ch) const;
"peek()" and see if the next character in the keyboard buffer is the same as the **ch** argument 
  - If it is the same, Remove it from the keyboard and throw it away! (i.e. istr.ignore())
  - If not:
    - Ignore all the remaining characters (up to 1000 characters) or the value of ch (use istr.ignore(int n,char c))
    - Set the istream into a fail state (use istr.setstate(iso::failbit))
#### ostream& printIDInfo(ostream& ostr)const;
Inserts the three parts related to the main card number, version code and stock number of the health card information into the **istr** object in the following format:

`1234567890-AB, XY7652341`

and then returns the **istr** object reference


#### void set(const char* name, long long number, const char vCode[], const char sNumber[]);
Validates the arguments,  reallocates memory for the name and sets the object attributes to their corresponding values.
- If the name and the three parts are valid (see [Validation](#validation)) `call the private function to validate`
    - Calls the **reallocateAndCopy** function to set the name
    - Sets the three parts to their values (m_number, m_vCode, m_sNumber)
- If not, it deletes the memory pointed by **m_name** and sets the object to a safe empty state (**setEmpty()**)

#### Constructors
The HeathCard can either get created with no values (default constructor) into a safe empty state or use all four values. 

> Instead of overloading the constructor you can use one constructor with the default values for the four parameters, (i.e nullptr, 0, {}, {} ) and remember to reuse the **set** function for the latter case. 

> Note that since the **m_name** attribute is initialized in the class definition to be **nullptr**, there is no need to worry about setting it to **nullptr** before calling the set function.

### Rule of three
#### Copy Constructor
`HeathCard(const HeathCard& hc);`
- if the **hc** object is valid it will set the values of the current object to those of the incoming argument (**hc** using assignment to *this).

#### Copy Assignment operator overload
`HeathCard& operator=(const HeathCard& hc);`
- First, it will make sure that this is not a "self-copy" by comparing the address of the current object and the address of the incoming argument.
  - If it is not a self copy this function works exactly like the copy constructor
- If it is a self copy don't perform any action 
At the end return the reference of the current object.

#### Destructor
deletes the memory pointed by **m_name**.

### Boolean type conversion operator
Returns true if **m_name** is not nullptr, else it will return false

### ostream& print(ostream& ostr, bool toFile = true) const;
If the current object is in a valid state it inserts the values of the card information in two different formats based on the value of the **toFile** argument:
- if **toFile** is true, prints the data in a comma-separated format:
    - prints the name
    - print comma
    - print the health card ID information using the private function printIDInfo
- if **toFile** is false prints the data in the following format:
    - In 50 characters, left-justified and padded with dots ('.'): prints the name
    - print the health card ID information using the private function printIDInfo
- At the end, it returns the **ostr** reference

### istream& read(istream& istr);
Reads the Contact information in following format:
- name
- comma
- main health number
- dash
- version number characters
- comma
- stock control number


Example: `Luke Skywalker,1231231234-XL,AF1234567`

#### implementation

- define local variables for the four parts.
- using istream::get() read the name up to **MaxNameLength** or a comma (do not extract comma)
- extract a comma using **extractChar** private function
- extract the main health number into a local variable (istr >> m_number;)
- extract a dash **'-'** using **extractChar** private function
- extract the version number code into a vCode local variable using get for 3 char or up to ',' whichever comes first
- extract a comma **','** using **extractChar** private function
- extract the stock control number to the local variable (using get to read 10 char or up to '\n' whichever comes first)
- if **istr** is not in a failure state
    - all data were read successfully, use the **set** private function to set values of the object to read value
- before returning, clear the state using istr.clear() and ignore the remaining of the line until '\n'
- at the end return the **istr** reference

### insertion operator overload
`ostream& operator<<(ostream& ostr, const Contact& hc);`

if **hc** is valid it will print it using the **print** function on the screen and not on File, (i.e. onFile is false). Otherwise, it will print `"Invalid Card Number"`.

In the end, it will return the **ostr** reference.

### extraction operator overload
`istream& operator>>(istream& istr, Contact& hc)`

returns the **read** method of the **hc** argument.

## The tester program
[main.cpp](./lab/main.cpp)

## Tester output

[correct_output.txt](./lab/correct_output.txt)

### Files to Submit
```Text
HealthCard.h
HealthCard.cpp
main.cpp
HealthCardInfo.csv
```

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

Follow the instructions in the tester 

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

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
```text
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **??Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty

# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.