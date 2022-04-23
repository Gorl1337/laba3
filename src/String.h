#pragma once
#include <iostream>
class TString
{
public:
	TString();
	TString(int _len, char* s);
	TString(int l);
	TString(char* s);
	TString(TString& p);
	~TString();
	int GetLen();
	void SetLen(int l);
	char* GetStr();
	void Duplication(int k);
	int Entering(char* c);
	char Simv();
	TString Povtor();
	void CountSimv();
	TString operator+(TString& p);
	char& operator[](int i);
	TString operator+=(const TString& p);
	bool operator==(const TString& p);
	TString& operator=(TString& p);
	bool operator!=(TString& p);
	bool operator<(TString& p);
	bool operator>(TString& p);
	int Find(char* c);
	int Find(char c);
	friend TString* Split(char c, TString& p);
	int split(char c);
	friend std::ostream& operator<<(std::ostream& B, TString& p);
	friend std::istream& operator>>(std::istream& B, TString& p);
protected:
	int len;
	char* str;
};