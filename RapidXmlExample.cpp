#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;


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
commansd+=command;


  xml_node<> * command_node = root_node->first_node(commansd.c_str());

	    printf("Running adb command: %s no of times %s. \n",
	    	command_node->first_attribute("name")->value(),
	    	command_node->first_attribute("iterations")->value());
            // Interate over the beers
	    for(xml_node<> * Actual_command = command_node->first_node("Actual_command"); Actual_command; Actual_command = Actual_command->next_sibling())
	    {
	    	printf("Using  %s to run %s. \n\n",
	    		Actual_command->first_attribute("tool")->value(),
	    		Actual_command->first_attribute("shell_command")->value());
	    	printf("Logging: %s\n", Actual_command->value());
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

	printf("Here are the available commands.\n");
	// Iterate over the brewerys
    int iters=atoi(iter.c_str());

	for (int i=1; i!=iters+1;i++)
	{

        char buffer [33];
	    string adds=itoa (i,buffer,10);
	    string commands="Commands_";
	    commands+=adds;
	    xml_node<> * command_node = root_node->first_node(commands.c_str());
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
print_commands();
cout<<"Entrain a command :";
cin>>command;
command_executor(command);




}
