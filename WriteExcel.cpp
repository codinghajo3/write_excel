#include <iostream>
#include <fstream>
#include <sstream>
#include "client.h"
#include "libxl.h"
using namespace std;
using namespace libxl;

void writeExcel(string& filename, Client* list, int size)
{
	Book* book = xlCreateBook();
	if (book)
	{
		Sheet* sheet = book->addSheet(L"Sheet1");
		if (sheet)
		{
			sheet->writeStr(2, 1, L"Hello, World !");
			sheet->writeNum(3, 1, 1000);
		}
		book->save(L"file.xls");
		book->release();
	}
}

int main() {
	int size = 1;
	string filename = "file.xls";
	Client* list;
	list = new Client[size];

	writeExcel(filename, list, size);

	return 0;
}