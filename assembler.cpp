#include "parser.cpp"
#include "code.cpp"
#include "symboltable.cpp"

using namespace std;

string decimalToBinary(int dec)  {
	string out = "";
	bool inv = false;
	if(dec < 0)  {
		inv = true;
		dec = -(dec + 1);
	}

	while(dec > 0)  {
		out = (((dec - inv) % 2) ? "1" : "0") + out;
		dec /= 2;
	}

	while(out.length() < 15)  {
		out = ((inv) ? "1" : "0") + out;
	}

	return out;
}
bool isNumber(string s)  {
	int i = 0;
	if(s[0] == '-')  {
		i++;
	}
	for(; i < s.length(); i++)  {
		if(!(s[i] >= '0' && s[i] <= '9'))  {
			return false;
		}
	}

	return true;
}
int stringToNumber(string s)  {
	int num = 0;

	int i;
	for(i = 0; i < s.length(); i++)  {
		int val = s[i] - '0';
		num = (num * 10) + val;
	}
	return num;
}

void initSymTab(SymbolTable * symTab)  {
	symTab -> addEntry("SP", 0);
	symTab -> addEntry("LCL", 1);
	symTab -> addEntry("ARG", 2);
	symTab -> addEntry("THIS", 3);
	symTab -> addEntry("THAT", 4);
	symTab -> addEntry("R0", 0);
	symTab -> addEntry("R1", 1);
	symTab -> addEntry("R2", 2);
	symTab -> addEntry("R3", 3);
	symTab -> addEntry("R4", 4);
	symTab -> addEntry("R5", 5);
	symTab -> addEntry("R6", 6);
	symTab -> addEntry("R7", 7);
	symTab -> addEntry("R8", 8);
	symTab -> addEntry("R9", 9);
	symTab -> addEntry("R10", 10);
	symTab -> addEntry("R11", 11);
	symTab -> addEntry("R12", 12);
	symTab -> addEntry("R13", 13);
	symTab -> addEntry("R14", 14);
	symTab -> addEntry("R15", 15);
	symTab -> addEntry("SCREEN", 16384);
	symTab -> addEntry("KBD", 24576);
}

int main(int argc, char ** argv)  {
	SymbolTable symTab;
	initSymTab(&symTab);

	if(argc <= 1)  {
		cout << "No file input!\n";
		return 0;
	}

	string file = argv[1];
	
	Parser p(file);

	int lnAddr = 0;
	while(p.hasMoreCommands())  {
		if(p.commandType() == L_COM)  {
			symTab.addEntry(p.symbol(), lnAddr);
			lnAddr--;
		}

		lnAddr++;
		p.advance();
	}

	string outFile = "out.hack";
	ofstream outputStream(outFile);

	if(!outputStream)  {
		cout << "Couldn't open file out.hack for writing.\n";
		return 0;
	}
	
	Parser q(file);
	Code c;
	int varAddr = 16;
	while(q.hasMoreCommands())  {
		if(q.commandType() == C_COM)  {
			outputStream << "111" << c.comp(q.comp()) << c.dest(q.dest()) << c.jump(q.jump()) << endl;
		}
		if(q.commandType() == A_COM)  {
			if(!isNumber(q.symbol()))  {
				if(!symTab.contains(q.symbol()))  {
					symTab.addEntry(q.symbol(), varAddr);
					varAddr++;
				}
			}

			if(isNumber(q.symbol()))  {
				outputStream << "0" << decimalToBinary(stringToNumber(q.symbol())) << endl;
			}  else  {
				//cout << q.symbol() << ":" << symTab.getAddress(q.symbol()) << endl;
				outputStream << "0" << decimalToBinary(symTab.getAddress(q.symbol())) << endl;
			}
		}
		q.advance();
	}

	outputStream.close();

	return 0;
}
