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
      cout << "*** " << question.first << " BEGIN ***" << endl;
      question.second();
      cout << "*** " << question.first << " END ***" << endl;
  }
}

