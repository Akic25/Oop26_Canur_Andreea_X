#include <fstream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<string> stringWords(const string& myString)
{
	vector<string> words;
	size_t start = 0;
	size_t end;

	while ((end = myString.find_first_of(".' '", start)) != string::npos)
	{
		if (end > start)//daca avem spatii duble
		{
			words.push_back(myString.substr(start, end - start));
	    }
		start = end + 1;
	}
	if (start < myString.length())
		words.push_back(myString.substr(start));
	return words;
}

map<string, int> wordFrequency(vector<string>& words)
{
	map<string, int>frec;
	for (const string& word : words)
	{
		frec[word]++;
	}
	return frec;
}

bool compareWords(const pair<string, int>& a, const pair<string, int>& b) 
{
	if (a.second != b.second)
		return a.second < b.second;
	return a.first > b.first;
}

vector<pair<string, int >> sortWords(const map<string, int> frecv)
{
	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&compareWords)> pq(compareWords);
	for (const auto& entry : frecv)
		pq.push(entry); 
	vector<pair<string, int >> sortedList;
	while (!pq.empty())
	{
		sortedList.push_back(pq.top());
		pq.pop();
	}
	return sortedList;
}//intreaba prof


int main()
{
	string myString;
	ifstream myFile("input.txt");
	if (!myFile)
	{
		cout << "Eroare la deschiderea fisierului";
		return 0;
	}

	if (!getline(myFile , myString))
	{
		cout << "Eroare la citirea fisierului";
		return 0;
	}

	map<char, int>myMap;
	cout << "Sirul citit este : " << myString.c_str() << endl;

	vector<string>splitWords = stringWords(myString);
	map<string, int>frecv = wordFrequency(splitWords);
	vector<pair<string, int>> sorteList = sortWords(frecv);
	for (const auto& word : sorteList)
		cout << word.first << " => " << word.second << endl;
	return 0;
}