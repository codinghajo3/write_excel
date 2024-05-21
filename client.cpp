#include <iostream>
#include <fstream>
#include <sstream>
#include "client.h"
#include "libxl.h"

Client::Client()
{
	this->id = "1";
	this->name = "È«±æµ¿";
	this->gender = "³²";
	this->age = 25;
	this->phonenumber = 01011112222;
	this->visit = 1;
}

void Client::writeExcel(std::string& filename, Client* list, int size)
{
	libxl::Book* book = xlCreateBook();
	if (book)
	{
		libxl::Sheet* sheet = book->addSheet(L"Sheet1");
		if (sheet)
		{
			sheet->writeStr(2, 1, L"Hello, World !");
			sheet->writeNum(3, 1, 1000);
		}
		book->save(L"file.xls");
		book->release();
	}
}