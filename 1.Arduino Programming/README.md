<p align="center">
	<img src="1. Dataset/arduino.jpg" />
</p>

**Arduino** is a prototype platform (open-source) based on an easy-to-use hardware and software. It consists of a circuit board, which can be programed (referred to as a microcontroller) and a ready-made software called **Arduino IDE** (Integrated Development Environment), which is used to write and upload the computer code to the physical board.

**Arduino** provides a standard form factor that breaks the functions of the micro-controller into a more accessible package.

# Key Features 
 - Arduino boards are able to read analog or digital input signals from different sensors and turn it into an output such as activating a motor, turning LED on/off, connect to the cloud and many other actions.

 - You can control your board functions by sending a set of instructions to the microcontroller on the board via Arduino IDE (referred to as uploading software).

 - Unlike most previous programmable circuit boards, Arduino does not need an extra piece of hardware (called a programmer) in order to load a new code onto the board. You can simply use a USB cable.

 - The Arduino IDE uses a simplified version of ***C++***, making it easier to learn to program.

 - Arduino provides a standard form factor that breaks the functions of the micro-controller into a more accessible package.
   <p align="center">
	<img src="1. Dataset/board.jpg" />
</p>

# Program Structure 
Arduino programs can be divided in three main parts: ***Structure***, ***Values*** (variables and constants), and ***Functions***.
Let us start with the **Structure**. Software structure consist of two main functions −

  - Setup( ) function
  - Loop( ) function
    
```C
void setup (){

}
```
The **setup()** function is called when a sketch starts. Use it to initialize the variables, pin modes, start using libraries, etc.
The ****setup*** function will only run once, after each power up or reset of the Arduino board. 

```C
void Loop (){

}
```
After creating a **setup()** function, which initializes and sets the initial values, the **loop()** function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond.
Use it to actively control the Arduino board.

# Data Types 
The Arduino environment is really just C++ with library support and built-in assumptions about the target environment to simplify the coding process. C++ defines a number of different data types

| Data Type  | Column 2 Header | Column 3 Header |
|-----------------|-----------------|-----------------|
| Boolean |8 bit | true/false |
| Byte | 8 bit | 0 to 255 |
| Char |8 bit| -128 to 127 |
| word | 16 bit | 0 to 65535 |
| int | 16 bit | -32768 to 32767 |
| long |32 bit|-2,147,483,648 to 2,147,483,647 |
| float | 32 bit | -3.4028235E38 to 3.4028235E38|

**Note:** ***signed*** variables allow both positive and negative numbers, while ***unsigned*** variables allow only <i> positive values </i>.

# Variables & Constants 

A scope is a region of the program and there are three places where variables can be declared. They are 
 - Inside a function or a block, which is called **local variables**.
 - In the definition of function parameters, which is called **formal parameters**.
 - Outside of all functions, which is called **global variables**.

## Local Variables 
  
    - Variables that are declared inside a function or block are local variables. <br>
    - They can be used only by the statements that are inside that function or block of code. 
    -  Local variables are not known to function outside their own. 
```C
Void setup () {

}

Void loop () {
   int x , y ;
   int z ; Local variable declaration
   x = 0;
   y = 0; actual initialization
   z = 10;
}
```

 ## Global Variables
  
    - Global variables are defined outside  of all the functions, usually at the top of the program. 
    - The global variables will hold their value throughout the life-time of your program.
    - A global variable can be accessed by any function.that is available for use throughout your entire program after its declaration.
```C
Int T , S ;
float c = 0 ; Global variable declaration

Void setup () {

}

Void loop () {
   int x , y ;
   int z ; Local variable declaration
   x = 0;
   y = 0; actual initialization
   z = 10;
}
```

## #define 
  The #define in Arduino is used to give a name to the constant value. It does not take any memory space on the chip.
  At the compile time, the compiler will replace the predefined value in the program to the constants with the defined value.

The syntax is:
```
#define nameOFconstant value  
```
**nameOFconstant**: It is the name of the macro or constant to define

**value**: It includes the value assigned to the constant or macro.

For example,
```C
#define LEDpin 12   // It is the correct representation of #define
  
  ```  

# Operators     
  An operator is a symbol that tells the compiler to perform specific mathematical or logical functions. C language is rich in built-in operators and provides the following types of operators −

|   Arithmetic Operators         | Operator simple | Description                                                                               | Example             |
|-------------------------|-----------------|-------------------------------------------------------------------------------------------|---------------------|
| Assignment operator     | =               | Stores the value to the right of the equal sign in the variable to the left of the equal sign. | A = B               |
| Addition                | +               | Adds two operands                                                                         | A + B will give 30  |
| Subtraction             | -               | Subtracts second operand from the first                                                    | A - B will give -10 |
| Multiplication          | *               | Multiply both operands                                                                    | A * B will give 200 |
| Division                | /               | Divide numerator by denominator                                                           | B / A will give 2   |
| Modulo                  | %               | Modulus Operator and remainder of after an integer division                                | B % A will give 0   |

---

| Comparison Operators    | Operator simple |     Description                                                                                         |     Example                  |
|-------------------------|----------------|-------------------------------------------------------------------------------------------|---------------------|
| Equal to                | ==             | Checks if the value of two operands is equal or not, if yes then condition becomes true. | (A == B) is not true |
| Not equal to            | !=             | Checks if the value of two operands is equal or not, if values are not equal then condition becomes true. | (A != B) is true |
| Less than               | <              | Checks if the value of left operand is less than the value of right operand, if yes then condition becomes true. | (A < B) is true |
| Greater than            | >              | Checks if the value of left operand is greater than the value of right operand, if yes then condition becomes true. | (A > B) is not true |
| Less than or equal to   | <=             | Checks if the value of left operand is less than or equal to the value of right operand, if yes then condition becomes true. | (A <= B) is true |
| Greater than or equal to| >=             | Checks if the value of left operand is greater than or equal to the value of right operand, if yes then condition becomes true. | (A >= B) is not true |

---

| Boolean Operators       |  Operator simple               |    Description                                                                                          |    Example                   |
|-------------------------|----------------|-------------------------------------------------------------------------------------------|---------------------|
| And                     | &&             | Called Logical AND operator. If both the operands are non-zero then then condition becomes true. | (A && B) is true |
| Or                      | \|\|           | Called Logical OR Operator. If any of the two operands is non-zero then then condition becomes true. | (A \|\| B) is true |
| Not                     | !              | Called Logical NOT Operator. Use to reverses the logical state of its operand. If a condition is true then Logical NOT operator will make false. | !(A && B) is false |

---

| Bitwise Operators       |   Operator simple              |     Description                                                                                         |  Example                     |
|-------------------------|----------------|-------------------------------------------------------------------------------------------|---------------------|
| And                     | &              | Binary AND Operator copies a bit to the result if it exists in both operands.             | (A & B) will give 12 which is 0000 1100 |
| Or                      | \|             | Binary OR Operator copies a bit if it exists in either operand                            | (A \| B) will give 61 which is 0011 1101 |
| XOR                     | ^              | Binary XOR Operator copies the bit if it is set in one operand but not both.              | (A ^ B) will give 49 which is 0011 0001 |
| Not                     | ~              | Binary Ones Complement Operator is unary and has the effect of 'flipping' bits.            | (~A) will give -60 which is 1100 0011 |
| Shift Left              | <<             | Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand. | A << 2 will give 240 which is 1111 0000 |
| Shift Right             | >>             | Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand. | A >> 2 will give 15 which is 0000 1111 |

---

| Compound Operators      |   Operator simple              |       Description                                                                                       |      Example                 |
|-------------------------|----------------|-------------------------------------------------------------------------------------------|---------------------|
| Increment               | ++             | Increment operator, increases integer value by one                                         | A++ will give 11    |
| Decrement               | --             | Decrement operator, decreases integer value by one                                         | A-- will give 9     |
| Compound Addition       | +=             | Add AND assignment operator. It adds right operand to the left operand and assign the result to left operand. | B += A is equivalent to B = B + A |
| Compound Subtraction    | -=             | Subtract AND assignment operator. It subtracts right operand from the left operand and assign the result to left operand. | B -= A is equivalent to B = B - A |
| Compound Multiplication | *=             | Multiply AND assignment operator. It multiplies right operand with the left operand and assign the result to left operand. | B *= A is equivalent to B = B * A |
| Compound Division       | /=             | Divide AND assignment operator. It divides left operand with the right operand and assign the result to left operand. | B /= A is equivalent to B = B / A |
| Compound Modulo         | %=             | Modulus AND assignment operator. It takes modulus using two operands and assign the result to left operand. | B %= A is equivalent to B = B % A |
| Compound Bitwise OR     | \|=            | Bitwise inclusive OR and assignment operator.                                              | A \|= 2 is same as A = A \| 2 |
| Compound Bitwise AND    | &=             | Bitwise AND assignment operator.                                                            | A &= 2 is same as A = A & 2 |

