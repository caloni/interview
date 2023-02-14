#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, InterviewQuestion> g_questions;


void AddInterviewQuestion(const char* name, InterviewQuestion question)
{
    g_questions[name] = question;
}


int main()
{
  cout << "hello, interview! let's run some questions:" << endl;

  for (const auto& question : g_questions)
  {
      cout << "*** " << question.first << " ***" << endl;
      question.second();
  }
}

