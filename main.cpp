#include "DataList.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv) {
	DataList dl;
	dl.append(1);
	dl.append(2);
	dl.print();
	dl.clear();
}