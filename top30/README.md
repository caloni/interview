# Programming / Coding Interview Questions & Answers

This code was made based on the article [Top 30 Programming / Coding Interview Questions & Answers](https://www.softwaretestinghelp.com/coding-interview-questions/).

The project idea is a monolithic program that is receiving interview questions by the function AddInterviewQuestion. An InterviewQuestion function is a function receving and returning no parameter. The objetive in this structure is to allow add and remove questions as modules in the project. By example, a question1.cpp can add its main function using AddInterviewQuestion, but once que question1.cpp is removed from the project the program still compiles and runs, with the difference that the code for this question is not running.

## How to use

In order to do this a numeric id is returned in the function AddInterviewQuestion that must populate a static variable in this module. In that way the static/global initialization in a C++ program is automatically populating the interview questions before running the C++ main function, that iterate thru those questions and run the main function for each one of them. Below an example on how to call a new question in its own module:

```//question2.cpp

void Question2();

static int st_questionId = AddInterviewQuestion("Question2", Question2); // called before main().
```

A macro is available to make easier to padronize the implementation in each module:

```//question2.cpp

void Question2();

ADD_INTERVIEW_QUESTION(Question2);
```

## Common issues

If there is more than one function with the same signature in different modules (by example, an utility function to deal with linked lists) the linker will complain about redefinition. In order to fix that let those functions as static, or in other words, they will be visible only in their own modules.

## Documentation

The documentation in this project is generated using doxygen. To generate useful documentation about this repo download or build doxygen and use it like in the command line bellow:

```
doxygen
```

The documentation will be generated in the docs folder.

