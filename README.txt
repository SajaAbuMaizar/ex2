-------------------------------------------  EX02 - templates ------------------------------------------
------------------------------------------- Students and IDs ------------------------------------------- 
--- Students: Samah Rajabi (student number: 211558556) & Saja Abu Maizar (student number: 208072371) ---

----------------------------------------  General Description  -----------------------------------------
The program simulates an application form for registering a student for a specific school year.
The student answers some questions about themelves and thier educational plans.
The questions are:
1. What is your name?
2. What's your ID number?
3. What's your year of birth?
4. What faculty are you registering to?
5. Which year is it in your studies? (1-7)
6. How many courses are you taking this year?
The program checkes whether the intered answers are correct or not, and repetedly askes the student
to enter the wrong answers until all the answers are correct.

----------------------------------------------- Design ------------------------------------------------
We built our program according to the instructions and the base files that were given to us in the 
exercise's paper.
In our program, there are three main classes: Form class, Field class and validator class.
The program starts by creating seven fields; a field for every question in the form. Every question has
a field of its own that stores data about the question and the answer about that field.
The program continues by building validators for every field, again, every question has a validator of
its own that inherates from a base class validator and checks the entered answer and stores a boolean
value regarding whether the entered data is valid or not. Then, each field contains its validator.
Finally, a form object is built, the form contains the seven fields.
After a form is built, the program asks the questions and receives the answers one by one, at the end,
it checkes the values of the validators and repetedly asks the questions that has a non valid answer
until all the fields have valid answers.

---------------------------------- List of The Files of The Program -----------------------------------
---------------------------------------------- Headers: -----------------------------------------------
Read more data about the files in the "Main Data Structures: Classes" section bellow.
Form.h.
BaseField.h.
Field.h.
Validator.h.
NoDigitValidator.h.
IdValidator.h.
RangeValidator.h.
MinValidator.h.
TwoBaseValidator.h. 
Courses2YearValidator.h. 
Facuity2YearValidator.h.
FacultyValue.h.
DataBase.h.
Data.h.

------------------------------------------- Executable Files: ----------------------------------------
main.cpp: controles the program, builds validators, fields and a form. askes questions and receives answers.
Read more data about the files in the "Main Data Structures: Classes" section bellow.
Form.cpp.
BaseField.cpp.
Field.cpp.
Validator.cpp.
NoDigitValidator.cpp.
IdValidator.cpp.
RangeValidator.cpp.
MinValidator.cpp.
TwoBaseValidator.cpp. 
Courses2YearValidator.cpp. 
Facuity2YearValidator.cpp.
FacultyValue.cpp.
DataBase.cpp.
Data.cpp.

---------------------------------------- Main Data Structures ---------------------------------------
--------------------------------------------- Classes: ----------------------------------------------
Class Form: contains a vector of fields objects and a vector of form validators (validators between fields).
Class BaseField: contains virtual functions, is used to build a vector of different fields in the form.
Class Field: inherates from baseField, contains data about a question and its answer and a validator.
Class Validator: abstract class, has offspring validators.
Class NoDigitValidator: inherates from Validator, checkes if a name is valid (doesn't contain numbers).
Class IdValidator: inherates from Validator, checks if an ID number is valid (PS: WE FOUND THE CODE IN WEKIPEDIA)
Class RangeValidator: a tampalte class, inherates from Validator, checkes if a given value is in the range of two other values.
Class MinValidator: inherates from Validator, checks if a given value is greater og a predefined threshold.
Class TwoBaseValidator: an abstract class, has offspring validators.
Class Courses2YearValidator: inherates from TwoBaseValidator, contains a year field and a courses field and checks whether the number of courses suits the year. 
Class Facuity2YearValidator: inherates from TwoBaseValidator, contains a year field and a faculty field and checks whether the year suits the faculty. 
Class FacultyValue: defines three values for the three faculties.
Class DataBase: an abstract class.
Class Data: inherates from DataBase, prints different types of data in the console.

---------------------------------------- Notable Algorithms -----------------------------------------
-------------------------------------------- Known Bugs ---------------------------------------------
---------------------------------------- Additional Comments ----------------------------------------
-----------------------------------------------------------------------------------------------------