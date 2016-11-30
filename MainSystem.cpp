#include "RunnerRegister.h"
#include <iostream>

int menu();
void addProRunner(RunnerRegister &runnerregister);
void addAmateur(RunnerRegister &runnerregister);
void removeRunner(RunnerRegister &runnerregister);
void showAllRunners(const RunnerRegister &runnerregister);
void showAllProRunners(const RunnerRegister &runnrregister);
void showAllAmateurs(const RunnerRegister &runnerregister);
void changeSponsor(RunnerRegister &runnerregister);
void showAllSpecificAmateurs(RunnerRegister &runnerregister);

inline void testMemoryLeaks()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
	testMemoryLeaks();
	RunnerRegister runnerregister;
	int choice = 0;
	
	choice = menu();
	cin.ignore();
	while (choice!=0)
	{
		switch (choice)
		{
		case 1:addProRunner(runnerregister); break;
		case 2:addAmateur(runnerregister); break;
		case 3:removeRunner(runnerregister); break;  
		case 4:showAllRunners(runnerregister); break;
		case 5:showAllProRunners(runnerregister); break;
		case 6:showAllAmateurs(runnerregister); break;
		case 7:changeSponsor(runnerregister); break; //!
		case 8:showAllSpecificAmateurs(runnerregister); break;
		case 9:exit(0);
		}
		cout << endl;

		choice = menu();
		cin.ignore();
	}

	return 0;
}

int menu()
{
	int choice = 0;
	cout << "----------MENU----------" << endl;
	cout << "1. Add a professional runner" << endl;
	cout<< "2. Add an amateur runner" << endl;
	cout<< "3. Remove a runner given the start number" << endl;
	cout<< "4. Present all runners by name and start number" << endl;
	cout<< "5. Present all professional runners and the total number of professional runners" << endl;
	cout<< "6. Present all amateur runners and the total number of amateur runners" << endl;
	cout<< "7. Change the sponsor for professional runners" << endl;
	cout<< "8. Present all amateurs in a given interval of ages" << endl;
	cout<< "9. Exit" << endl;
	cout<< "Please enter your choice: ";
	cin >> choice;
	return choice;
}

void addProRunner(RunnerRegister & runnerregister)
{
	string name, club, sponsor;
	int startNum=0;

	cout << "Enter the name: ";
	getline(cin, name);
	cout << "Enter the start number: ";
	cin >> startNum;
	cin.ignore();
	cout << "Enter the club: ";
	getline(cin, club);
	cout << "Enter the sponsor: ";
	getline(cin, sponsor);

	runnerregister.addProRunner(name, startNum, club, sponsor);
	cout << "The professional runner has been created successfully !"<<endl;
}

void addAmateur(RunnerRegister & runnerregister)
{
	string name;
	int startNum=0, age=0;

	cout << "Enter the name: ";
	getline(cin, name);
	cout << "Enter the start number: ";
	cin >> startNum;
	cout << "Enter the age: ";
	cin >> age;

	runnerregister.addAmateur(name, startNum, age);
	cout << "The amateur runner has been created successfully!" << endl;
}

void removeRunner(RunnerRegister & runnerregister)
{
	int startNum=0;

	cout << "Enter the start number of the runner you want to remove: ";
	cin >> startNum;

	if (runnerregister.removeArunner(startNum)==false)
	{
		cout << "No runner is removed because there is no runner with the start number " << startNum << endl;
	}
	else
	{
		cout << "Runner with the start number " << startNum << " is removed " << endl;
	}
}

void showAllRunners(const RunnerRegister & runnerregister)
{
	string *stringsOfRunners = nullptr;
	int size = runnerregister.getNrOfRunners();

	stringsOfRunners = new string[size];

	bool  all = runnerregister.getAllRunners(stringsOfRunners, size);
	if (all)
	{
		cout << "these are the runners: " << endl;
	}
	else
	{
		cout << "These are the first " << size << " of the runners " << endl;
	}
	for (int i = 0; i <size; i++)
	{
		cout << stringsOfRunners[i] << endl;
	}
	delete[] stringsOfRunners;
}

void showAllProRunners(const RunnerRegister & runnrregister)
{
	string *stringsOfProRunners = nullptr;
	int size = runnrregister.getNrOfProRunners();

	stringsOfProRunners = new string[size];

	bool all = runnrregister.getAllProRunners(stringsOfProRunners, size);
	if (all)
	{
		cout << "These are the professional runners: " << endl;
	}
	else
	{
		cout << "These are the first " << size << " of the professional runners " << endl;
	}
	for (int i = 0; i <size; i++)
	{
		cout << stringsOfProRunners[i] << endl;
	}

	delete[] stringsOfProRunners;
	cout << "The total number of professional runners is: " << runnrregister.getNrOfProRunners()<<endl;
}

void showAllAmateurs(const RunnerRegister & runnerregister)
{
	string *stringsOfAmateurs = nullptr;
	int size = runnerregister.getNrOfAmateurs();

	stringsOfAmateurs = new string[size];

	bool all = runnerregister.getAllAmateurs(stringsOfAmateurs, size);
	if (all)
	{
		cout << "These are the amateur runners " << endl;
	}
	else
	{
		cout << "These are the first " << size << " of the amateur runners " << endl;
	}
	for (int i = 0; i < size; i++)
	{
		cout << stringsOfAmateurs[i] << endl;
	}
	delete[] stringsOfAmateurs;
	cout << "The total number of amateur runners is: " << runnerregister.getNrOfAmateurs() << endl;
}

void changeSponsor(RunnerRegister & runnerregister)
{
	int startNum;
	string sponsor;
	cout << "Enter the start number of the professional runner that you want to change the sponsor: ";
	cin >> startNum;
	cout << "Enter the sponsor you want: ";
	cin.ignore();
	getline(cin, sponsor);

	if (runnerregister.changeSponsor(sponsor,startNum)==true)
	{
		cout << "The sponsor has been changed! " << endl;
	}
	else
	{
		cout << "There is no runner with the start number " << startNum << endl;
	}
}

void showAllSpecificAmateurs(RunnerRegister & runnerregister)
{
	string *stringsOfSpecificAmateurs = nullptr;
	int low, up;

	cout << "Enter the lower limit of the age: ";
	cin >> low;
	cout << "Enter the upper limit of the age: ";
	cin >> up;
	
	int size = runnerregister.getNrOfAmateurs();
	stringsOfSpecificAmateurs = new string[size];

	bool all = runnerregister.getSpecificAmateurs(stringsOfSpecificAmateurs, low,up);
	if (all)
	{
		cout << "These are the amateurs in the given interval of ages: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << stringsOfSpecificAmateurs[i] ;
		}
	}
	else
	{
		cout << "There is no amateurs in the given interval of ages " << endl;
	}
	
	delete[] stringsOfSpecificAmateurs;
}


