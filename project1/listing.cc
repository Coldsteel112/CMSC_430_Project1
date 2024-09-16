// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the bodies of the functions that produces the 
// compilation listing

#include <cstdio>
#include <string>
#include <queue>

using namespace std;

#include "listing.h"

static int lineNumber;
static string error = "";
int totalErrors = 0;
int lexicalErrorCount = 0;
int syntacticErrorCount = 0;
int semanticErrorCount = 0;

queue<string> errorQueue;

static void displayErrors();

void firstLine()
{
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}
void nextLine()
{
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine()
{
    printf("\r");
    displayErrors();
    printf("     \n");

    if (totalErrors > 0) {
        printf("Total Errors: %d\n", totalErrors);
        if (lexicalErrorCount > 0) {
            printf("Lexical Errors: %d\n", lexicalErrorCount);
        }
        if (syntacticErrorCount > 0) {
            printf("Syntactic Errors: %d\n", syntacticErrorCount);
        }
        if (semanticErrorCount > 0) {
            printf("Semantic Errors: %d\n", semanticErrorCount);
        }
    } else {
        printf("Compiled Successfully \n");
    }

    return totalErrors;
}

void appendError(ErrorCategories errorCategory, string message)
{
    string messages[] = { "Lexical Error, Invalid Character: ", "", 
        "Semantic Error: ", "Semantic Error, Duplicate: ", 
        "Semantic Error, Undeclared: " };

    string errorMessage = messages[errorCategory] + message;
    errorQueue.push(errorMessage); // Add the error message to the queue

    // Increment the appropriate error counter
    switch (errorCategory) {
        case LEXICAL:
            lexicalErrorCount++;
            break;
        case SYNTAX:
            syntacticErrorCount++;
            break;
        case GENERAL_SEMANTIC:
        case DUPLICATE_IDENTIFIER:
        case UNDECLARED:
            semanticErrorCount++;
            break;
    }

    totalErrors++; // Increment the total error count
}

void displayErrors()
{
    while (!errorQueue.empty()) {
        printf("%s\n", errorQueue.front().c_str());
        errorQueue.pop();
    }
}
