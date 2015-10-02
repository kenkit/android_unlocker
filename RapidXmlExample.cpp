#include <string.h>
#include <stdio.h>
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
	for (xml_node<> * command_node = root_node->first_node(command.c_str()); command_node; command_node = command_node->next_sibling())
	{
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
	printf("No of commands available :%s \n \n",root_node->first_attribute("no_of_commands")->value());
	printf("Here are the available commands.\n");
	// Iterate over the brewerys
	for (xml_node<> * command_node = root_node->first_node("Commands"); command_node; command_node = command_node->next_sibling())
	{
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
print_commands();
}
