#include <bits/stdc++.h>
using namespace std;
int main() {
	cout << "ソースコード" <<endl;
	string code;
	cin >> code;
	cout << "標準入力" <<endl;
	string inpt;
	cin >> inpt;
	int code_size = code.size();
	int inf = 1 << 16;
	vector<char> mem(inf, 0);
	int pnt = 0;
	int read = 0;
	bool skp = false;
	int loop_code;
	cout << "標準出力" << endl;
	for (int i=0;i<code_size;i++){
		if (skp) {
			if (code.at(i) == ']') {
				skp = false;
			}
		}
		else if (code.at(i) == ',') {
			mem.at(pnt) = inpt.at(read);
			read++;
		}
		else if (code.at(i) == '.') cout << mem.at(pnt);
		else if (code.at(i) == '+') mem.at(pnt)++;
		else if (code.at(i) == '-') mem.at(pnt)--;
		else if (code.at(i) == '>') pnt++;
		else if (code.at(i) == '<') pnt--;
	 	else if (code.at(i) == '[' && mem.at(pnt) == 0) skp = true;
		else if (code.at(i) == '[') loop_code = i;
		else if (code.at(i) == ']') i= loop_code-1;
	}
	cout << endl;	
}
