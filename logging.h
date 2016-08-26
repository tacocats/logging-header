/*
	Simple c++ header for logging information and displaying information
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma once
#include <string>
#include <fstream>
#include <windows.h>
#include <iostream>

using namespace std;

class logging {

	std::fstream logFile;
	bool consoleEnabled;

public:

	// Constructor	
	logging(bool enableConsole) {
		if (enableConsole) {
			consoleEnabled = true;
			AllocConsole();
			freopen("CONOUT$", "w", stdout);
		}
		else {
			consoleEnabled = false;
		}
	}

	// Log information to a file
	bool logToFile(string fileName, string input) {
		try {
			logFile.open(fileName, ios::out);
			logFile << input << endl;
			logFile.close();
		}
		catch (int e) {
			return false;
		}

		cout << input << endl;
		return true;
	}

	// Log information to console 
	bool logToConsole(string input) {
		if (consoleEnabled) {
			cout << input << endl;
			return true;
		}
		else {
			return false;
		}
	}
};