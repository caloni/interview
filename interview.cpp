/** @mainpage
* 
* This is a set of interview common questions and its answers in C++ language.
* Initially it was made based on the article
* [Top 30 Programming / Coding Interview Questions & Answers].
* 
* [Top 30 Programming / Coding Interview Questions & Answers]: https://www.softwaretestinghelp.com/coding-interview-questions/
*/
#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, InterviewQuestion> g_questions;


int AddInterviewQuestion(const char* name, InterviewQuestion question)
{
    g_questions[name] = question;
    return (int) g_questions.size();
}


int main()
{
  cout << "hello, interview! let's run some questions:" << endl;

  for (const auto& question : g_questions)
  {
      cout << "\n*** " << question.first << " BEGIN ***" << endl;
      question.second();
      cout << "*** " << question.first << " END ***\n" << endl;
  }
}

