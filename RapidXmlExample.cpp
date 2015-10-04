#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "rapidxml-1.13/rapidxml.hpp"
#include <conio.h>
using namespace rapidxml;
using namespace std;
int max_commands=0;
int brute_force=100, timeout=4000,s_timeout=300,to_exit=0;

string banner="**********************************************************\n\\
        Welcome to the Dragon Android Manager\nThis software was designed by Storm, all rights reserved.\n\\
**********************************************************";
void ClearScreen(void);
void command_processor(string commands)
{


cout<<"\n*******************ADB|Output***************************\n";
system(commands.c_str());
cout<<"*******************ADB|Output***************************\n\n\n";
}
void command_executor(string file_name,string command)
{

    cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (file_name.c_str());
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Instructubles");
	// Iterate over the brewerys
    string commansd="Commands_";
    string iter;
    string ha=" ";
    int iters;
    commansd+=command;
    string commands;

    xml_node<> * command_node = root_node->first_node(commansd.c_str());
    iter=command_node->first_attribute("iterations")->value();
    iters=atoi(iter.c_str());
	    cout<<"Running :"<<command_node->first_attribute("name")->value()<<endl<<command_node->first_attribute("iterations")->value()<<":no of times. \n";

            // Interate over the beers
        for (int i=0;i<iters;i++)
	    for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
	    {


	    		commands+=Actual_command->first_attribute("tool")->value();
                commands+=ha;
	    		commands+=Actual_command->first_attribute("shell_command")->value();

	    	cout<<"Logging: "<<Actual_command->value()<<endl;
	    	command_processor(commands);
	    	commands="";
	    	cout<<"Count :"<<i+1<<endl;
	    }
	    cout << endl;

}
void command_selector(string filename,string command)
{

    cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (filename.c_str());
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Instructubles");
	// Iterate over the brewerys
    string commansd="Commands_";
    string iter;
    string ha=" ";
    int iters;
    commansd+=command;
    string commands;

    xml_node<> * command_node = root_node->first_node(commansd.c_str());
    iter=command_node->first_attribute("iterations")->value();
    iters=atoi(iter.c_str());

	    	cout<<"Running :"<<command_node->first_attribute("name")->value()<<"\n"<<command_node->first_attribute("iterations")->value()<< "No of times \n";
            // Interate over the beers
        for (int i=0;i<iters;i++)
	    for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
	    {


	    		commands+=Actual_command->first_attribute("tool")->value();
                commands+=ha;
	    		commands+=Actual_command->first_attribute("shell_command")->value();

	    	cout<<"Logging: "<<Actual_command->value()<<"\n";
	    	command_processor(commands);
	    	commands="";
	    	cout<<"Count :"<<i+1<<endl;
	    }
	    cout << endl;

}
void print_commands(string xml_filename)
{
cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (xml_filename.c_str());
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Instructubles");

	string iter=root_node->first_attribute("no_of_commands")->value();

	cout<<"No of commands available :"<<iter<<endl;

	cout<<"Here are the available commands.\n\n";
	// Iterate over the brewerys
    int iters=atoi(iter.c_str());
    max_commands=iters;
	for (int i=1; i!=iters+1;i++)
	{

        char buffer [33];
	    string adds=itoa (i,buffer,10);
	    string commands="Commands_";
	    commands+=adds;
	    xml_node<> * command_node = root_node->first_node(commands.c_str());
	    Sleep(s_timeout);
	    printf("%s.%s. \n",
            command_node->first_attribute("no")->value(),
	    	command_node->first_attribute("name")->value());
	    	//command_node->first_attribute("iterations")->value());
            // Interate over the beers
        /***
	    for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
	    {
	    	printf("Using  %s to run %s. \n\n",
	    		Actual_command->first_attribute("tool")->value(),
	    		Actual_command->first_attribute("shell_command")->value());
	    	printf("Logging: %s\n", Actual_command->value());
	    }
	    **/
	    //cout << endl;
	}
	cout<<max_commands+1<<".Back.\n";
	to_exit=max_commands+1;

}
void display_initial_entry(string menu_file)
{
cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (menu_file.c_str());
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Instructubles");

	string iter=root_node->first_attribute("no_of_items")->value();

	cout<<"No of commands available :"<<iter<<endl;

	printf("Here are the available commands.\n\n");
	// Iterate over the brewerys
    int iters=atoi(iter.c_str());
    max_commands=iters;
	for (int i=1; i!=iters+1;i++)
	{

        char buffer [33];
	    string adds=itoa (i,buffer,10);
	    string commands="acvite_item_";
	    commands+=adds;
	    xml_node<> * command_node = root_node->first_node(commands.c_str());
	    Sleep(s_timeout);
	    printf("%s.%s. \n",
            command_node->first_attribute("no")->value(),
	    	command_node->first_attribute("item_name")->value());
	    	//command_node->first_attribute("iterations")->value());
            // Interate over the beers
        /***
	    for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
	    {
	    	printf("Using  %s to run %s. \n\n",
	    		Actual_command->first_attribute("tool")->value(),
	    		Actual_command->first_attribute("shell_command")->value());
	    	printf("Logging: %s\n", Actual_command->value());
	    }
	    **/
	    //cout << endl;
	}
	cout<<iters+1<<". Exit"<<endl;
}

void select_from_initial_entry(string menu_file,string menu_item_no)
{

    cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (menu_file.c_str());
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Instructubles");
	// Iterate over the brewerys
    string commansd="acvite_item_";
    string iter;
    int iters;
    commansd+=menu_item_no;
    string commands,choice;

    xml_node<> * command_node = root_node->first_node(commansd.c_str());
    //iter=command_node->first_attribute("no_of_items")->value();
    //iters=atoi(iter.c_str());

   int breaks=0;
            // Interate over the beers
       while(!breaks)
       {
        Sleep(s_timeout);
        ClearScreen();
        print_commands(command_node->first_attribute("file")->value());
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        if (to_exit!=atoi(choice.c_str()))
        command_executor(command_node->first_attribute("file")->value(),choice);
        else
            breaks=1;

	    //cout << endl;
       }
        cout<<"Going back."<<endl;


}
void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }
int main(void)
{

/***
string command;


while (1)
{

cout<<banner;
Sleep(s_timeout);
print_commands();
cout<<"Entrain a command :";
cin>>command;
if (atoi(command.c_str())>max_commands||atoi(command.c_str())==0)
    cout<<"Invalid Command."<<endl;
else
    command_executor(command);
}
**/

string selected;

while (1)
{



cout<<banner<<endl;
Sleep(timeout);
ClearScreen();
display_initial_entry("items.xml");
cout<<"Entrain a command :"<<endl;
cin>>selected;

if (atoi(selected.c_str())==max_commands+1)
    {
    cout<<"Exiting"<<endl;
    exit(0);
    }
else if (atoi(selected.c_str())>max_commands||atoi(selected.c_str())==0)
    cout<<"Invalid Command."<<endl;
else
{
    ClearScreen();
    select_from_initial_entry("items.xml",selected);
}

}


}
