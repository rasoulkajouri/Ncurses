## Welcome to the Ncurses project's page

I would like to make a courses about the Ncurses package and also would like to talk with each other about the package.
Moreover, you can find some explanation about each codes at the [@kajothecoder](https://www.instagram.com/kajothecoder/) page in Instagram. Of course, those videos are in persian languages.
I sure you can find the best explanation about this package in English language in internet.


## How to run the Nncurses package
First of all, you need to install this package on your system! Cuz this package is not a built-in library (**standard library**) for programming languages.
Second, you can find it so easily in internet but I also put here a brief manual about installing it.

### GNU-Linux OS
To install this package on your machine, you need only type the following commands
#### Deb Base
``` 
sudo apt install libncurses5-dev libncursesw5-dev
```
You surely can find other version of ncurses in internet, but the maintend codes has been written and compiled under fifth version of Ncurses 
#### RPM Base 
```
sudo yum install ncurses-devel
```
I compiled the codes with Ubuntu 20.04 LTS operating system and also G++ version 7.

## How to compile a code
```
[compiler name] [flags] [source files] -lncurses -o [name of executable version] 
```
For an example
```
g++ -Wextra -Werror -Wall -W -std=c++11 less-01.cpp -lncurses -o run
```

I suggest you to make a Makefile to compile your codes swift 

I made a makefile for these code and I update it week by week, but you now need to know how you can compile each lesson by the given makefile
to compile each lesson you need write the name of the lesson at the front of the "make" command, for more details follow the below
```
make less01
```
The above command starts the compiling process at the makefile's directory and creates an executable file which entited "run"

<hr>

## The most important functions in NCurses

To start coding in the Ncurses environment, you, firstly, need to call the Ncurses library in the header. ``` #include<ncurses.h>```. then, you have to initialize the Ncurses environment. To initialize this medium, you only need to call the following function.
```initscr();````
