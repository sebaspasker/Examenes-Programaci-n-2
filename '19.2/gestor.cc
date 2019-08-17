#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct originalFormat  {
	char name[20];
	char surname1[20];
	char surname2[20];
	char adress[100];
	int balance;
};

struct newFormat {
	char fullName[75];
	char adress[75];
	float balance;
};

vector<originalFormat> convertBinToOriginal(string fileName, bool &Error) {
	ifstream binFile(fileName, ios::binary);
	originalFormat o;
	vector<originalFormat> ov;

	if(binFile.is_open()) {

		binFile.seekg(0, ios::end);
		int size = binFile.tellg()/sizeof(originalFormat);
		binFile.seekg(0, ios::beg);

		for(int i=0; i < size; i++) {
			binFile.read((char *)&o, sizeof(originalFormat));
			ov.push_back(o);
		}
/*
		strcpy(o.name, "Sebastian");
		strcpy(o.surname1, "Pasker");
		strcpy(o.surname2, "Gonzalez");
		strcpy(o.adress, "Calle Currican nº27, 7B");
		o.balance = 100;
		binFile.write((const char *)&o, sizeof(originalFormat));

		strcpy(o.name, "Jose");
		strcpy(o.surname1, "Alberto");
		strcpy(o.surname2, "Gerard");
		strcpy(o.adress, "Calle Mujol nº18, 1B");
		o.balance = -100;
		binFile.write((const char *)&o, sizeof(originalFormat));

		strcpy(o.name, "Josefina");
		strcpy(o.surname1, "Gonzalez");
		strcpy(o.surname2, "Fua");
		strcpy(o.adress, "Calle Yusep nº25, 2B");
		o.balance = 300;
		binFile.write((const char *)&o, sizeof(originalFormat));

strcpy(o.name, "Laura");
		strcpy(o.surname1, "Paskercita");
		strcpy(o.surname2, "Gonzalezita");
		strcpy(o.adress, "Calle Tumadre nº27, 7B");
		o.balance = 1000;
		binFile.write((const char *)&o, sizeof(originalFormat));

*/
		binFile.close();

	} else {
		cout << "File can't open" << endl;
		Error = true;
	}	

	return ov;
}

void convertOriginalToText(string fileName, vector<originalFormat> ov, bool &Error) {
	ofstream fileText(fileName);

	if(fileText.is_open()) {
		for(unsigned int i=0; i < ov.size(); i++) {
			fileText << ov[i].name << "|" << ov[i].surname1 <<"|" << ov[i].surname2 << "|" << ov[i].adress << "|";

			if(ov[i].balance >= 0){
				fileText << ov[i].balance;
			} else {
				fileText << "NA";
			}

			fileText << endl;
		}

		fileText.close();	
	} else {
		cout << "File can't open" << endl;
		Error = true;
	}
}

vector<originalFormat> convertTextToOriginal(string fileName, bool &Error) {
	ifstream fileText(fileName);
	string line, parameter;
	originalFormat o;
	vector<originalFormat> ov;
	int process = 0;

	if(fileText.is_open()) {
		while(getline(fileText, line)) {
			for(unsigned int i=0; i< line.size(); i++) {
				if(line[i] != '|') {
					parameter += line[i];
				} else if(process == 0 && line[i] == '|') {
					process++;
					strcpy(o.name, parameter.c_str());
					parameter.clear();
				} else if(process == 1 && line[i] == '|') {
					process++;
					strcpy(o.surname1, parameter.c_str());
					parameter.clear();
				} else if(process == 2 && line[i] == '|') {
					process++;
					strcpy(o.surname2, parameter.c_str());
					parameter.clear();
				} else if(process == 3 && line[i] == '|') {
					process++;
					strcpy(o.adress, parameter.c_str());
					parameter.clear();
				} 
			}

			if(parameter == "NA") {
				o.balance = 0;
			} else {
				o.balance = atof(parameter.c_str());
			}

			ov.push_back(o);
			parameter.clear();
			process = 0;
		}

		fileText.close();
	} else {
		cout << "File can't open" << endl;
		Error = true;
	}

	return ov;
}

vector<newFormat> convertOriginalToNew(vector<originalFormat> ov) {
	vector<newFormat> nv;
	newFormat n;

	strcpy(n.fullName, "");

	for(unsigned int i=0; i < ov.size(); i++) {
		strcat(n.fullName, ov[i].name);
		strcat(n.fullName, " ");
		strcat(n.fullName, ov[i].surname1);
		strcat(n.fullName, " ");
		strcat(n.fullName, ov[i].surname2);
		strcpy(n.adress, ov[i].adress);
		n.balance = ov[i].balance;
		nv.push_back(n);
		strcpy(n.fullName, "");
	}

	return nv;
}

void convertNewToBin(string fileName, vector<newFormat> nv, bool &Error) {
	ofstream newFile(fileName, ios::binary);

	if(newFile.is_open()) {
		for(unsigned int i=0; i < nv.size(); i++) {
			newFile.write((const char *)&nv[i], sizeof(newFormat));
		}

		newFile.close();
	} else {
		cout << "File can't open" << endl;
		Error = true;
	}
}


vector<newFormat> convertBinToNew(string fileName, bool &Error) {
	ifstream binFile(fileName, ios::binary);
	newFormat n;
	vector<newFormat> nv;

	if(binFile.is_open()) {

		binFile.seekg(0, ios::end);
		int size = binFile.tellg()/sizeof(newFormat);
		binFile.seekg(0, ios::beg);

		for(int i=0; i < size; i++) {
			binFile.read((char *)&n, sizeof(newFormat));
			nv.push_back(n);
		}

		binFile.close();

	} else {
		cout << "File can't open" << endl;
		Error = true;
	}	

	return nv;
}

int main(int argc, char *argv[]) {
	bool Error = false;

	if(argc == 4) {
		if(strcmp(argv[1], "-l") == 0) {
				vector<originalFormat> originalFormatList = convertBinToOriginal(argv[2], Error);
				if(!Error){
					convertOriginalToText(argv[3], originalFormatList, Error);
				}
		} else if(strcmp(argv[1], "-s") == 0) {
			vector<originalFormat> originalFormatList = convertTextToOriginal(argv[3], Error);
			if(!Error){
	 			vector<newFormat> newFormatList = convertOriginalToNew(originalFormatList);
	 			convertNewToBin(argv [2], newFormatList, Error);
			}
		} else if(strcmp(argv[1], "-prueba") == 0) {
			vector<newFormat> newFormatListProve = convertBinToNew(argv[2], Error<);

			for(unsigned int i=0; i<newFormatListProve.size(); i++) {
				cout << newFormatListProve[i].fullName << " " << newFormatListProve[i].adress << " " << newFormatListProve[i].balance << endl;
			}
		} else {
			cout << "Incorrect format" << endl;
		}
	}
}