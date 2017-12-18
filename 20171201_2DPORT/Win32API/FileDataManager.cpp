#include "stdafx.h"
#include "FileDataManager.h"

void FileDataManager::TextSave(string Filename, string JsonString)
{
	ofstream fileOut;
	fileOut.open(Filename, ios_base::out);
	fileOut << JsonString;
	fileOut.close();
}

void FileDataManager::JsonSave(string Filename, json JsonData)
{
	ofstream fileOut;
	fileOut.open(Filename, ios_base::out);
	fileOut << JsonData.dump(4);
	fileOut.close();
}

json FileDataManager::JsonLoad(string Filename)
{
	json loadData;     //  remove comments
	ifstream i(Filename);
	if (!i.bad())   //  file loaded
		i >> loadData;
	return loadData;
}

json FileDataManager::JsonLoad(string Key, string Filename)
{
	json loadData;     //  remove comments
	ifstream i(Filename);
	if (!i.bad())   //  file loaded
	{
		auto releaseIter = m_mapJsonData.find(Key);
		if (releaseIter != m_mapJsonData.end())
			return releaseIter->second;

		i >> loadData;

		m_mapJsonData.insert(pair<string, json>(Key, loadData));
		return loadData;
	}
	else
	{
		return loadData;
	}
}

void FileDataManager::JsonRelease(string Key)
{
	auto releaseIter = m_mapJsonData.find(Key);
	if (releaseIter != m_mapJsonData.end())
		m_mapJsonData.erase(releaseIter);
}

json FileDataManager::JsonFind(string Key)
{
	auto findIter = m_mapJsonData.find(Key);
	if (findIter != m_mapJsonData.end())
		return m_mapJsonData.find(Key)->second;
	else
		return nullptr;
}

void FileDataManager::JsonUpdate(string Key, json JsonData)
{
	m_mapJsonData.find(Key)->second = JsonData;
}

void FileDataManager::FileAppend(string Filename, string StringData)
{
	ofstream fileOut;
	fileOut.open(Filename, ios_base::app);
	fileOut << StringData;
	fileOut.close();
}

string FileDataManager::MakeCsvString(vector<string> VecArray)
{
	string szBuffer = "";

	for (int i = 0; i < (int)VecArray.size(); i++)
	{
		szBuffer.append(VecArray[i]);
		szBuffer.append(",");
	}

	return szBuffer;
}

vector<string> FileDataManager::CharArraySeperation(char CharArray[])
{
	vector<string> vecArray;
	char* temp = NULL;
	char* separator = ",";
	char* token;

	token = strtok_s(CharArray, separator, &temp);
	if (token != NULL)
		vecArray.push_back(token);

	while ((token = strtok_s(NULL, separator, &temp)) != NULL)
	{
		vecArray.push_back(token);
	}

	return vecArray;
}

void FileDataManager::Tokenizer(const string & str, vector<string>& tokens, const string & token)
{
	// �� ù ���ڰ� �������� ��� ����
	string::size_type lastPos = str.find_first_not_of(token, 0);
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	string::size_type pos = str.find_first_of(token, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of(token, pos);
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
		pos = str.find_first_of(token, lastPos);
	}
}
