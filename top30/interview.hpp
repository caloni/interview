#pragma once

#define ADD_INTERVIEW_QUESTION(question) static int st_questionId = AddInterviewQuestion(#question, question)

typedef void (*InterviewQuestion)();

int AddInterviewQuestion(const char* name, InterviewQuestion question);

