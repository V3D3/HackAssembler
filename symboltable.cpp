#include <iterator>
#include <map>
using namespace std;

class SymbolTable  {
	private:
		map<string, int> table;
	public:
		void addEntry(string, int);
		bool contains(string);
		int getAddress(string);
};

void SymbolTable::addEntry(string symbol, int address)  {
	if(contains(symbol))  {
		table[symbol] = address;
	}  else  {
		table.insert(pair<string, int>(symbol, address));
	}
}

bool SymbolTable::contains(string symbol)  {
	return table.find(symbol) != table.end();
}

int SymbolTable::getAddress(string symbol)  {
	return table.find(symbol) -> second;
}
