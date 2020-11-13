#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

#define A_COM 0
#define C_COM 1
#define L_COM 2

class Parser  {
	private:
		ifstream inputStream;
		string currentCommand;
		string trim(string);
	public:
		Parser(string);
		bool hasMoreCommands();
		void advance();
		int commandType();
		string symbol();
		string dest();
		string comp();
		string jump();
};

Parser::Parser(string file)  {
	inputStream::open(file);
	advance();
}

bool Parser::hasMoreCommands()  {
	streampos curr = inputStream.tellg();
	string newLine;

	while(inputStream)  {
		getline(inputStream, newLine);
		newLine = trim(newLine);

		if(newLine.length() == 0 || (newLine[0] == '/' && newLine[1] == '/'))  {
			curr = inputStream.tellg();
		}  else  {
			inputStream.seekg(curr, ios_base::beg);
			return true;
		}
	}

	return false;
}

void Parser::advance()  {
	string newLine;

	while(inputStream)  {
		getline(inputStream, newLine);
		newLine = trim(newLine);

		if(newLine.length() == 0 || (newLine[0] == '/' && newLine[1] == '/'))  {
			continue;
		}  else  {
			currentCommand = newLine;
			return;
		}
	}
}

int Parser::commandType()  {
	if(currentCommand[0] == '@')  {
		return A_COM;
	}
	if(currentCommand[0] == '(')  {
		return L_COM;
	}
	return C_COM;
}

string Parser::symbol()  {
	if(commandType() == A_COM)  {
		return currentCommand.substr(1, currentCommand.length() - 1);
	}
	return currentCommand.substr(1, currentCommand.length() - 2);
}

string Parser::dest()  {
	int i;
	for(i = 0; i < currentCommand.length(); i++)  {
		if(currentCommand[i] == '=')  {
			break;
		}
	}

	if(i == currentCommand.length())  {
		return "";
	}
	return currentCommand.substr(0, i);
}

string Parser::comp()  {
	int eqIndex = -1;
	int scIndex = -1;
	int i;
	for(i = 0; i < currentCommand.length(); i++)  {
		if(currentCommand[i] == '=')  {
			eqIndex = i;
		}
		if(currentCommand[i] == ';')  {
			scIndex = i;
		}
	}

	if(eqIndex < 0 && scIndex < 0)  {
		return currentCommand;
	}
	if(eqIndex < 0)  {
		return currentCommand.substr(0, scIndex);
	}
	if(scIndex < 0)  {
		return currentCommand.substr(eqIndex + 1, currentCommand.length() - eqIndex - 1);
	}
	return currentCommand.substr(eqIndex + 1, scIndex - eqIndex - 1);
}

string Parser::jump()  {
	int i;
	for(i = 0; i < currentCommand.length(); i++)  {
		if(currentCommand[i] == ';')  {
			break;
		}
	}

	if(i == currentCommand.length())  {
		return "";
	}

	return currentCommand.substr(i + 1, currentCommand.length() - i - 1);
}

string Parser::trim(string input)  {
	string fin = "";

	int i;
	for(i = 0; i < input.length(); i++)  {
		if(input[i] != ' ')  {
			fin += input[i];
		}
	}

	return fin;
}
