#include <iostream>
using namespace std;

class Code  {
	public:
		string dest(string);
		string comp(string);
		string jump(string);
};

string Code::dest(string mnemonic)  {
	bool hasM = false;
	bool hasA = false;
	bool hasD = false;

	int i;
	for(i = 0; i < mnemonic.length(); i++)  {
		if(mnemonic[i] == 'M')  {
			hasM = true;
		}
		if(mnemonic[i] == 'A')  {
			hasA = true;
		}
		if(mnemonic[i] == 'D')  {
			hasD = true;
		}
	}

	string ret = "";
	ret += (hasA) ? "1" : "0";
	ret += (hasD) ? "1" : "0";
	ret += (hasM) ? "1" : "0";
	
	return ret;
}

string Code::jump(string mnemonic)  {
	if(mnemonic.length() == 0)  {
		return "000";
	}
	if(!mnemonic.compare("JGT"))  {
		return "001";
	}
	if(!mnemonic.compare("JEQ"))  {
		return "010";
	}
	if(!mnemonic.compare("JGE"))  {
		return "011";
	}
	if(!mnemonic.compare("JLT"))  {
		return "100";
	}
	if(!mnemonic.compare("JNE"))  {
		return "101";
	}
	if(!mnemonic.compare("JLE"))  {
		return "110";
	}
	if(!mnemonic.compare("JMP"))  {
		return "111";
	}

	return "000";
}

string Code::comp(string mnemonic)  {
	if(!mnemonic.compare("0"))  {
		return "0101010";
	}
	if(!mnemonic.compare("1"))  {
		return "0111111";
	}
	if(!mnemonic.compare("-1"))  {
		return "0111010";
	}
	if(!mnemonic.compare("D"))  {
		return "0001100";
	}
	if(!mnemonic.compare("A"))  {
		return "0110000";
	}
	if(!mnemonic.compare("M"))  {
		return "1110000";
	}
	if(!mnemonic.compare("!D"))  {
		return "0001101";
	}
	if(!mnemonic.compare("!A"))  {
		return "0110001";
	}
	if(!mnemonic.compare("!M"))  {
		return "1110001";
	}
	if(!mnemonic.compare("-D"))  {
		return "0001111";
	}
	if(!mnemonic.compare("-A"))  {
		return "0110011";
	}
	if(!mnemonic.compare("-M"))  {
		return "1110011";
	}
	if(!mnemonic.compare("D+1"))  {
		return "0011111";
	}
	if(!mnemonic.compare("A+1"))  {
		return "0110111";
	}
	if(!mnemonic.compare("M+1"))  {
		return "1110111";
	}
	if(!mnemonic.compare("D-1"))  {
		return "0001110";
	}
	if(!mnemonic.compare("A-1"))  {
		return "0110010";
	}
	if(!mnemonic.compare("M-1"))  {
		return "1110010";
	}
	if(!mnemonic.compare("D+A"))  {
		return "0000010";
	}
	if(!mnemonic.compare("D+M"))  {
		return "1000010";
	}
	if(!mnemonic.compare("D-A"))  {
		return "0010011";
	}
	if(!mnemonic.compare("D-M"))  {
		return "1010011";
	}
	if(!mnemonic.compare("A-D"))  {
		return "0000111";
	}
	if(!mnemonic.compare("M-D"))  {
		return "1000111";
	}
	if(!mnemonic.compare("D&A"))  {
		return "0000000";
	}
	if(!mnemonic.compare("D&M"))  {
		return "1000000";
	}
	if(!mnemonic.compare("D|A"))  {
		return "0010101";
	}
	if(!mnemonic.compare("D|M"))  {
		return "1010101";
	}

	return "0000000";
}
