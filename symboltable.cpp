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
	map.insert(pair<string, int>(symbol, address);
}

bool contains(string symbol)  {
	return table.find(symbol) == table.end();
}

int getAddress(string symbol)  {
	return table.find(symbol) -> second;
}
