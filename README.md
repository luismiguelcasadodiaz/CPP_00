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


# cpp Piscine
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

## iostreams

Two magical objects `cin` and 'cout'
Two new operators `<<` (back arrows or ) and `>>` (forward arrows or greater than greater than)

```cpp
#include <iostream>
 std::endl
 ```

 `endl` is an object from standard library that represents the `carriage return` for the operating system.

 [c++ iosstream reference](https://cplusplus.com/reference/iostream/)
 
 ## classes and instances

Do not forget `;` at class's end declaration.

Class Name is used as Contructor for the class.

Member attribute is a variable in the class declared in the public part
Member functions is a function the class can use. I declare it with the namespace

