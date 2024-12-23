# CPP_00
Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.


The goal of these modules is to introduce you to Object-Oriented Programming.

This will be the starting point of your C++ journey. Many languages are recommended to learn OOP. We chose C++ since it’s derived from your old friend C.

Because this is a complex language, and to keep things simple, your code will comply with the C++98 standard.

You will discover new concepts step-by-step. The exercises will progressively increase in complexity.

## C++ 98 Standard

Below are the key features and improvements brought by C++ 98:


|Feature|	Description|	Syntax|
|-------------|----------------------------------------------------------|----------------------|
|**Templates**|	C++ 98 standardized the use of templates, allowing the <ins>creation of generic functions and classes</ins>. This made it possible to write code that works with any data type.|	```template <typename T> T add(T a, T b) { return a + b; }```|
|**Exceptions**	|Exception handling was standardized in C++ 98, providing a <ins>structured way to handle errors</ins> and exceptional conditions in programs.	|```try { // code } catch (exception& e) { // handle error }```|
|**Namespaces**|	C++ 98 introduced namespaces to <ins>avoid name conflicts by grouping entities</ins> like classes, objects, and functions under a specific name.|	```namespace MyNamespace { int value; }```|
|The **bool Type**|	C++ 98 introduced the bool data type, along with the <ins>true and false</ins> keywords, for representing boolean values.|	```bool flag = true;```|
|The **typename** Keyword|	The typename keyword was introduced to <ins>disambiguate dependent names</ins> in templates, improving readability and reducing errors.|```typename T::iterator it;```|
|The **explicit** Keyword|	C++ 98 introduced the explicit keyword to <ins>prevent implicit type conversions</ins>, which can lead to subtle bugs.	|```explicit MyClass(int value);```|
|Member Function **const**ness|	C++ 98 allowed member functions to be declared as const, <ins>ensuring that they do not modify the object on which they are called</ins>.|```	int getValue() const { return value; }```|
|**Member Templates**|C++ 98 introduced the ability to <ins>define templates within class definitions</ins>, allowing for more flexible and reusable code.|```template <typename T> class MyClass { /*...*/ };```|
|**Template Specialization**|Allows the creation of template specializations for specific types, enabling <ins>more efficient or specialized implementations</ins>.|```template<> class MyClass<int> { /*...*/ };```|
|**Multiple Inheritance and Virtual Functions**|C++ 98 standardized the behavior of multiple inheritance and virtual functions, ensuring <ins>consistency across compilers</ins>.|```class Derived : public Base1, public Base2 { };```|
|The **mutable** Keyword|Allows modification of class members even if the containing object is const, providing <ins>more flexibility in certain designs</ins>.|```mutable int counter;```|
|**Dynamic Memory Management**|C++ 98 standardized the new and delete operators to <ins>handle heap memory allocation and deallocation consistently</ins>.|```c int* p = new int(5); delete p; ```|

## compilation flag

[-std=c++98](https://gcc.gnu.org/onlinedocs/gcc-3.3.5/gcc/C-Dialect-Options.html#C-Dialect-Options)

```c++
g++ -std=c++98 main.cpp -o main
```

### ex00

Write a program that behaves as follows

```bash
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```


# Cpp piscine Day 00
## Namespaces

Scope resolution operator `::`



```cpp
#include <stdio.h>

int	gl_var = 1;
int	f( void ) { return (2); }

namespace	Foo
{
	int	gl_var = 3;
	int	f( void ) { return (4); }
}

namespace	Bar
{
	int	gl_var = 5;
	int	f( void ) { return (6); }
}

namespace Muf = Bar;

int	main ( void )
{
	printf( "gl_var:     [%d]\n", gl_var );
	printf( "f():        [%d]\n\n", f() );

	printf( "gl_var:     [%d]\n", Foo::gl_var );
	printf( "f():        [%d]\n\n", Foo::f() );

	printf( "gl_var:     [%d]\n", Bar::gl_var );
	printf( "f():        [%d]\n\n", Bar::f() );

	printf( "gl_var:     [%d]\n", Muf::gl_var );
	printf( "f():        [%d]\n\n", Muf::f() );

	printf( "gl_var:     [%d]\n", ::gl_var );
	printf( "f():        [%d]\n\n", ::f() );

	return (0);
}
```

``` bash
gl_var:     [1]
f():        [2]

gl_var:     [3]
f():        [4]

gl_var:     [5]
f():        [6]

gl_var:     [5]
f():        [6]

gl_var:     [1]
f():        [2]
```

## Iostreams

Two magical objects `cin` and 'cout'
Two new operators `<<` (back arrows or ) and `>>` (forward arrows or greater than greater than)

```cpp
#include <iostream>
 std::endl
 ```

 `endl` is an object from standard library that represents the `carriage return` for the operating system.

 [c++ iosstream reference](https://cplusplus.com/reference/iostream/)
 
 ## Classes and instances

Do not forget `;` at class's end declaration.

Class Name is used as Contructor for the class.

Member attribute is a variable in the class declared in the public part
Member functions is a function the class can use. I declare it with the namespace

## Instance constructor with **initialitation list**

```cpp
Sample1::Sample1( char p1, int p2, float p3 ): a1(p1), a2(p2), a3(p3)
{
    std::cout << "Constructor Sample1 called" << std::endl;
    std::cout << "this->a1 = " << this->a1 << std::endl;
    std::cout << "this->a2 = " << this->a2 << std::endl;
    std::cout << "this->a3 = " << this->a3 << std::endl;
    this->bar();
    return ;

}
```

## Const

The keyword `const` declares a variable as a constant.

A constant can not be assigned any value to, except at initialization time.

The more constants we use in our code the safer code we will produce.

Inside a class, when a member attribute is declared const, the value to such const will be defined at instantiation time, at run-time, not at compile-time.

Attention to the language describing what happens during initialization list. 

In `a1(p1)` we do not **assign** the value `p1` to the attribute `a1`, but we **initialize** the attribute `a1` with the value `p1`
### const function or read-only classes.
We must, as a good practice, add the keyword `const` after the declaration and the definition of a member function that does not modifiy any member attribute. The compiler will save us from involuntary modifications of of attributes inside member functions that do not have to modify nothing.

THat good practice will help us to generate more robust code.

## Visibility (public, private)

Controls class's encapsulation.
Define which member attributes and member functions are accessible from inside or outside 

private, only accesible form class inside.
public, accesible from class inside and outside

constructor and destructor go in the public side.

Prefix with underscore private members.

The compiler will report any tentative of access from class outside to private members.

It is crucial a good definition of what is visible and what is hidded to the classe user.

## Class vs struct

struct's syntax is a mimetic  class's syntax

In C++ by default the struct' scope is public and the class' scope is private

## Accessors

For private attribute we create small proxy funcions to access them.

We name this small proxy funcion using prefixes "get" and "set"

The get proxies must be "Const".

The set proxies take care of private class invariants.

## Comparisons

Comparisons on structures. Compares only structures addresses. if structures have same values, a regular comparison with == gives a wrong answer.

Let's say == test if both structures are phisically in same memory space.
We need a member function that test individually if any structure field differ from the
corresponding field form other strucuture. 

## Non member attributes and functions

Non member attributes/functions means class attributes/functions.

The member exists dans un instance. it is different for each instance.

`static` has a new meaning in Cpp. we use it to declare nom member attributes/functions

Instead of `this->` we use the class name to access non member attributes/functions.

Non member attributes initialization takes place inside the class.cpp file

## Pointers to members

pointers 
## Conclusionn





# Cpp piscine Day 01
## New et delete
Neither Malloc nor free form c call the class's constructor/destructor. THis is why new and delete exist in c++;

new() calls first to malloc() then calls the class constructor and returns a pointer to the new created object.

delete() first calls the class destructor then free().

```c++
 Student *jim = new Student("jim");
 delete jim;
```
 ### Creation of an array of object

 New() wiht an array does not accept any argument, so a constructor wihtout parametre must exist in the class.

 ```c++
 Students *students = new Student[42];
 delete [] students;
```
Pay attention to the empty pair of square bracktes before the array of object to destroy.

## References

A reference is a pointer with this characteristiques:


+ It is constant.
+ It is alway dereferenced.
+ it is never null.

  It works like an alias to a variable

  ```c++
  int	num = 42;
  int *numptr = &num;
  inr &numref = num
  int &numref2; //invalid. you can not create a reference pointign to null.
  ```

A reference always point towards something. It is never null. But if what was pointed towards has been released, the reference had not the right to access to it.

numref is used as it is. no need por asterisk or ampersand.

### Passing parameters by reference

#### parameter definition inside the function

std::string text = "Luis"

| type | Parameter definition     |funcion call|
|------|--------------------------|------------|
|by ptr|f(std::string *name)      |f(&text)    |
|by ptr|f(std::string const *name)|f(&text)    |
|by ref|f(std::string &name)      |f(text)     |
|by ref|f(std::string const &name)|f(text)     |

#### Argument passage inside the funciton 's call.


## Filestreams

Input file std::ifstream
Output file std::ifstream
