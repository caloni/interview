# Programming / Coding Interview Questions & Answers

This repo is starting based on the article [Top 30 Programming / Coding Interview Questions & Answers](https://www.softwaretestinghelp.com/coding-interview-questions/).

The project idea is a monolithic program that is receiving interview questions by the function AddInterviewQuestion. An InterviewQuestion function is a function receving and returning no parameter. The objetive in this structure is to allow add and remove questions as modules in the project. By example, a question1.cpp can add its main function using AddInterviewQuestion, but once que question1.cpp is removed from the project the program still compiles and runs, with the difference that the code for this question is not running.

In order to do this a numeric id is returned in the function AddInterviewQuestion that must populate a static variable in this module. In that way the static/global initialization in a C++ program is automatically populating the interview questions before running the C++ main function, that iterate thru those questions and run the main function for each one of them. Below an example on how to call a new question in its own module:

```//question2.cpp

void Question2();

static int st_questionId = AddInterviewQuestion(Question2); // called before main().
```
