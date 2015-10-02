#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;
int max_commands=0;
int brute_force=100, timeout=6000,s_timeout=300;

string banner="**********************************************************\n\\
        Welcome to the Dragon Android Manager\nThis software was designed by Storm, all rights reserved.\n\\
**********************************************************";
void command_processor(string commands)
{


cout<<"\n*******************ADB|Output***************************\n";
system(commands.c_str());
cout<<"*******************ADB|Output***************************\n\n\n";
}
void command_executor(string command)
{

    cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile ("beerJournal.xml");
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
	    printf("Running %s command: %s no of times. \n",
	    	command_node->first_attribute("name")->value(),
	    	command_node->first_attribute("iterations")->value());
            // Interate over the beers
        for (int i=0;i<iters;i++)
	    for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
	    {


	    		commands+=Actual_command->first_attribute("tool")->value();
                commands+=ha;
	    		commands+=Actual_command->first_attribute("shell_command")->value();

	    	printf("Logging: %s\n", Actual_command->value());
	    	command_processor(commands);
	    	commands="";
	    	cout<<"Count :"<<i+1<<endl;
	    }
	    cout << endl;

}

void print_commands(void)
{
cout << "Parsing commands..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile ("beerJournal.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("Instructubles");

	string iter=root_node->first_attribute("no_of_commands")->value();

	cout<<"No of commands available :"<<iter<<endl;

	printf("Here are the available commands.\n\n");
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
}
int main(void)
{
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



}
