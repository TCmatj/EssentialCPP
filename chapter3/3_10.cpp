#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string,int> words;
	set<string> word_exclusion = {"a","b"};
	string tword;
	while(cin >> tword){
		if(word_exclusion.count(tword))
			continue;
		words[tword]++;
	}

	map<string,int>::iterator it = words.begin();
	for( ; it != words.end(); it++){
		cout << "key:" << it->first
			 << "  value:" << it->second << endl;
	}
	
	return 0;
}
