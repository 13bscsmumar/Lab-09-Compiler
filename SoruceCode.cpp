#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

/*std::deque<std::string> split(const std::string &text, char sep) {
    std::deque<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        std::string temp = text.substr(start, end - start);
        if (temp != "") tokens.push_back(temp);
        start = end + 1;
    }
    std::string temp = text.substr(start);
    if (temp != "") tokens.push_back(temp);
    return tokens;
}*/
string removeSpaces(string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}

string removeSemiColon(string input)
{
  input.erase(std::remove(input.begin(),input.end(),';'),input.end());
  return input;
}

bool findSemiColon(string input)
{
	if (input.find(";") != std::string::npos) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Variable
{
	string name;
	int value;

	void setValue(int val)
	{
		value = val;
	}
	void setname(string nam)
	{
		name = nam;
	}
	int getValue()
	{
		return value;
	}
	string getName()
	{
		return name;
	}
};

bool isParam(string line){
    if(isdigit(atoi(line.c_str()))) return true;
    return false;
} 

int main() 
{ 
	deque<string> line;
	int read = 1;
	int lineCount = 0;
    ifstream file("code.txt");
    string str; 
    while (std::getline(file, str))
    {
		lineCount++;
		istringstream iss(str);
		deque<string> line;
		//string lineNo = to_string(lineCount);
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(line));
		//line.push_back(lineNo);
		for(int i = 0;i<line.size();i++)
		{
			line[i] = removeSpaces(line[i]);
			
		}

		//**********************************
		if(findSemiColon(line[line.size()-1]) == false)
			{
				
				read = 0;
				line.clear();
				break;
			}
			else
			{
				//check other conditions
				read = 1;
				line[line.size()-1] = removeSemiColon(line[line.size()-1]);
				if (line[0]=="Let")
				{
					//delarative tests
					
					//Variable line[1];
					string temp = line[2];
					Variable line[1];

					Variable line[1];

					Variable line[1].setValue(line[4]);

				}
				//else if (line[0]=="")
				
			}
		//***********************************
		/*for(int i = 0;i<line.size();i++)
		{
			
			cout<<"\nin check"<<" true fale: "<<findSemiColon(line[line.size()-1])<<" value: "<<line[3];

			
		}
		if (read == 0)
		{
			
			break;
		}*/
		/*cout<<"\n";
		bool myvar = findSemiColon(line[line.size()-1]);
		cout<<"\n";
		cout<<"\n";
		cout<<myvar;*/

	}
		if(read == 0)
		{
			cout<<"\n\nSyntax Error in line number: "<<lineCount<<endl;
		}
		else
			cout<<"\n\nbuilt ";
}
