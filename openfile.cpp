// openfile.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<iterator>
#include<fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream outFile_even, outFile_odd;
	outFile_even.open("outFile_even.txt");
	outFile_odd.open("outFile_evem.txt");
	if (!outFile_even || !outFile_odd){
		cerr << "file can't be open" << endl;
		return -1;
	}
	istream_iterator<int>in_iter(cin), end;
	ostream_iterator<int>out_odd_iter(outFile_odd," ");
	ostream_iterator<int>out_even_iter(outFile_even, "\n");
	while (in_iter != end){
		if (*in_iter % 2 == 0){
			*out_even_iter++= *in_iter++;
		}
		else
		{
			*out_odd_iter++ = *in_iter++;
		}
	}
	outFile_even.close();
	outFile_odd.close();
	cout << endl;
	system("pause");
	return 0;
}

