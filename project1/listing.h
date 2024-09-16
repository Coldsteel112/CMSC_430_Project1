// CMSC 430 Compiler Theory and Design
// Project 1 Skeleton
// UMGC CITE
// Summer 2023

// This file contains the function prototypes for the functions that produce
// the compilation listing
#include <queue>
#include <string>

enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
	UNDECLARED};

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, string message);

// Global variables for error count
extern int lexicalErrorCount;
extern int syntacticErrorCount;
extern int semanticErrorCount;
extern int totalErrors;

// Global queue to store error messages
extern std::queue<std::string> errorQueue;
