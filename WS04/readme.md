# Workshop #4: Constructors, Destructors, and the *this* object
* Version 0.9 (submission is not open yet and the text is under review)
* Version 1.0 (Submissions will be open by your profs shortly and return type of find_similar is corrected)
* Version 1.1 (Added costume code submission)


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:


- Create default and overloaded constructors
- Create destructors
- Initialize class member variables 
- Release member pointers

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


# Part 1 - lab (50%) 
## `CarInventory` Module
Design and implement a class named `CarInventory` that stores the following information for a car entry:
* Type of the car (i.e SUV)
* The brand of the car (i.e Volvo)
* The model of the car (i.e XC90)
* The year of the car (i.e 2021)
* The code for the car inventory (i.e 100)
* The price of the car (i.e 90000)

Each object of the class `CarInventory` can be created in either of the following ways:
* By default set everything to null and 0
* Provide the type, brand, and model of the car
* Provide all the required information

The `CarInventory` provides functionalities to reset the information, add information, print the information, check the validity of the information, and check if the two entries are the same. Details of these will be provided below.

## Implementation
Create a class named `CarInventory` and add the following members.

### Private Member Variables

```C++
char* m_type;
char* m_brand;
char* m_model;
int m_year;
int m_code;
double m_price;
```
#### Valid CarInventory member variable values  
```Text
type, not null
brand, not null
model, not null
year >= 1990
code, three digit integer
prince > 0
```
### Constructors
```C++
CarInventory();
```
The default constructor will initialize the member variables by calling the [`resetInfo()`](#private-member) method (the details of this method will be provided in the **Private Member** section.

--------------------------------------------------------

```C++
CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price);
```
This constructor will first [reset the data](#private-member) and then dynamically keep the values of the C-string argument in their corresponding attributes and set the rest of the attributes the corresponding argument values if they pass validation.<br />

When instantiated using this constructor, if the **year**, **code** or **price** arguments are not provided they will be set to **2022**, **100** and **1.0**  using default values for the arguments.

--------------------------------------------------------
### Destructor
This destructor should deallocate the dynamically allocated memory in type, brand, and model.
--------------------------------------------------------

### Private Member
```C++
void resetInfo();
```
This method resets the values for all member variables by setting type, brand, and model to **nullptr** and setting the year, code, and price to 0.

--------------------------------------------------------
### Public Members
```C++
CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
```
This method will first deallocate all the allocated memory and then set the attributes to the corresponding arguments exactly like the 6-argument constructor. <br />
Note: this function does not have any default values for its arguments.<br />
In the end, it will return the reference of the current object.


--------------------------------------------------------
```C++
void printInfo() const;
```
This method prints the values of all the member variables on the screen in the following format.<br />
Order:<br />
TYPE,BRAND,MODEL,YEAR,CODE,PRICE<br />
Spacing:
```text
| 10  spaces | 16        spaces | 16        spaces | 9999 |  999 | 999999.99 |
| Left       | left             | Left             |      | right|     right |
```

--------------------------------------------------------
```C++
bool isValid() const;
```
This method returns whether all member variables have valid values or not based on the criteria stated in the [Private Member Variables](#valid-carinventory-member-variable-values).

--------------------------------------------------------
```C++
bool isSimilarTo(const CarInventory& car) const;
```
This function is to check whether the type, make, brand and year of an object of `CarInventory` are equal to another object of this class. The function will return `true` only if all those values match.  
> if any of the values are nullptr, the function will return false;

--------------------------------------------------------

Also, implement a global function in the `sdds` namespace to check whether there are duplicate entries in the entire inventory:


```C++
int find_similar(CarInventory car[], const int num_cars)   
```

It returns the index of the first match, if it finds two `CarInventory` objects that have similar information in the car array. See below for the function implementation logic:

```C++
for (int i = 0; i < num_cars; i++){
  for (int j = i+1; j < num_cars; j++){
    if (car[i] is Simialr to car[j]){
        // match is found
    }
  }
}
```

--------------------------------------------------------

## Testing Program

[main.cpp](lab/main.cpp)

## Sample Output

[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  

```Text
CarInventory.h
CarInventory.cpp
main.cpp
```

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


> **⚠️Important:**  Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty



# PART 2 - DIY (50%)

> Please note that you can (and probably should) add more member functions to make the DIY part work better or more efficiently.

Write a program in two modules for a Label Maker application:

The Two modules are used as follows to print labels:  

## The Label Module  

The label class creates a label by drawing a frame around a one-line text with an unknown size (maximum of 70 chars, **must be kept dynamically**).

The frame is dictated by a series of 8 characters in a Cstring. These characters indicate how the frame is to be drawn:
```Text
character 1: top left corner character.
character 2: character to repeat for the top line.
character 3: top right corner character
character 4: character to repeat for the right line.
character 5: bottom right corner character
character 6: character to repeat for the bottom line.
character 7: bottom left corner character
character 8: character to repeat for the left line.
```
For example the following CString: ``` "AbCdEfGh" ``` <br />
will generate the following frame around a text:
```Text
AbbbbbbbbbbbbbbbbbbbbbbbbbC
h                         d
h                         d
h                         d
GfffffffffffffffffffffffffE
```

## Mandatory constructors and methods:
### Label()
Creates an empty label and defaults the frame to ```"+-+|+-+|"```
### Label(const char* frameArg)
Creates an empty label and sets the frame to the **frameArg** argument. If the `frameArg` is nullptr, the default frame will be used instead.
### Label(const char* frameArg, const char* content)
Creates a Label with the **frame** set to **frameArg** and the content of the Label set to the corresponding argument. Note that you must keep the content dynamically even though it should never be more than 70 characters.

### destructor
Makes sure there is no memory leak when the label goes out of scope.

###  istream& readLabel();
Reads the content of the label from the console up to 70 characters and stores it in the Label as shown below and then returns the `cin`.
###  std::ostream& printLabel()const;
Prints the label by drawing the frame around the content as shown below. Note that no newline is printed after the last line and cout is returned at the end. 

```text
+-------------------+
|                   |
| My Label Content! |
|                   |
+-------------------+
```

### Label& text(const char* content);
Sets the content of the Label (up to 70 characters) dynamically and then returns the reference of the current object.

## The LabelMaker Module  
The LabelMaker class creates a dynamic array of Labels and then reads the contents of each Label so it can print them all at once when needed.

## Mandatory constructors and methods:
### LabelMaker(int noOfLabels);
creates a dynamic array of Labels to the size of **noOfLabels**
### void readLabels();
Gets the contents of the Labels as demonstrated below (Assuming there are two labels in the LabelMaker):
```text
Enter label number 1
> First Label Content!
Enter label number 2
> Second Label Content!
```
### void printLabels();
Prints the Labels as demonstrated below (Assuming the above two labels are added to LabelMaker):
```text
+----------------------+
|                      |
| First Label Content! |
|                      |
+----------------------+
+-----------------------+
|                       |
| Second Label Content! |
|                       |
+-----------------------+
```

### ~LabelMaker();
Deallocates the memory when LabelMaker goes out of scope.


> Modify the tester program to test are the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Tester Program

[main.cpp](DIY/main.cpp)

## Execution Sample

[correct_output.txt](DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)
Files to submit:  
```Text
Label.cpp
Label.h
LabelMaker.cpp
LabelMaker.h
main.cpp
```

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


> **⚠️Important:**  Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty