#include "String.h"
#include <iostream>
TString::TString()
{
	len = 0;
	str = 0;
}

TString::TString(int _len, char* s)
{
	if (_len < 0)
		throw "error";
	len = _len;
	str = new char[_len];
	for (int i = 0; i < _len - 1; i++)
		str[i] = s[i];
	str[len - 1] = '\0';
}

TString::TString(int l)
{
	str = new char[l];
	len = l;
	for (int i = 0; i < len; i++)
		str[i] = '\0';
}

TString::TString(char* s)
{
	if (s == 0)
		throw "error";
	len = strlen(s) + 1;
	str = new char[len];
	for (int i = 0; i < len - 1; i++)
		str[i] = s[i];
	str[len - 1] = '\0';
}

TString::TString(TString& p)
{
	len = p.len;
	str = p.str;
	for (int i = 0; i < len; i++)
		str[i] = p.str[i];
}

TString::~TString()
{
	if (str != 0)
		str = 0;
	delete[]str;
	str = 0;
	len = 0;
}

int TString::GetLen()
{
	return len;
}

void TString::SetLen(int l)
{
	TString B(str);
	delete[]str;
	str = new char[l];
	len = l;
	for (int i = 0; i < l - 1; i++)
		str[i] = B[i];
	str[l] = '\0';
}

char* TString::GetStr()
{
	return str;
}

void TString::Duplication(int k)
{
	for (int i = 0; i < k; i++)
	{
		std::cout << *this;
	}
}

int TString::Entering(char* c)
{
	int l = 0, a = 0;
	for (int i = 0; i < len - 1;)
	{
		for (int j = 0; j < strlen(c);)
		{
			if (str[i] == c[j])
			{
				i++;
				j++;
				a++;
			}
			else
			{
				i++;
				if (i >= len - 1)
					break;
				j = 0;
			}
		}
		l++;
	}
	if (a == 0)
		l = 0;
	return l;
}

void simvv(TString a, int l, int u)
{
	int i = l;
	int j = u;
	char tmp = 0;

	char x = a[(int)((l + u) / 2)];

	do
	{
		while (a[i] < x)++i;
		while (a[j] > x)--j;

		if (i <= j)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i < j);
	if (l < j)
		simvv(a, l, j);
	if (i < u)
		simvv(a, i, u);
}

char TString::Simv()
{
	simvv(*this, 0, len - 1);
	int* mas = new int[len];
	for (int i = 0; i < len; i++)
		mas[i] = 0;
	int j = 0;
	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			mas[j]++;
		}
		else
			j++;
	}
	int a = -1;
	for (int j = 0; j < len - 1; j++)
	{
		if (mas[j] > mas[j + 1])
		{
			a = j;
		}
	}
	delete[] mas;
	return str[a];
}

TString TString::Povtor()
{
	simvv(*this, 0, len - 1);
	TString mas(len);
	int j = 1;
	mas.str[0] = str[1];
	for (int i = 1; i < len - 1; i++)
	{
		if (str[i] != str[i + 1])
		{
			mas.str[j] = str[i + 1];
			j++;
		}
	}
	return mas;
}

void TString::CountSimv()
{
	simvv(*this, 0, len - 1);
	TString mas(len);
	int* a = new int[len];
	for (int i = 0; i < len; i++)
		a[i] = 1;
	int j = 0;
	for (int i = 1; i < len; i++)
	{
		if (str[i] != str[i + 1])
		{
			mas.str[j] = str[i];
			j++;
		}
		else
		{
			a[j]++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		std::cout << mas[i] << " = " << a[i] << '\t';
	}
	std::cout << std::endl;
	delete[] a;
}

TString TString::operator+(TString& p)
{
	TString res(len + p.len - 1);
	for (int i = 0; i < len; i++)
		res.str[i] = str[i];
	for (int i = len - 1; i < len + p.len - 1; i++)
		res.str[i] = p.str[i - len + 1];
	return res;
}

char& TString::operator[](int i)
{
	if (str == 0)
		throw "error";
	if (i < 0 && len < i)
		throw "error";
	return str[i];
}

TString TString::operator+=(const TString& p)
{
	int l = p.len + len - 1;
	char* c = new char[l];
	for (int i = 0; i < len - 1; i++)
		c[i] = str[i];
	for (int i = 0; i < p.len; i++)
		c[i + len - 1] = p.str[i];
	delete[]str;
	str = c;
	len = l;
	return*this;
}

bool TString::operator==(const TString& p)
{
	if (len != p.len)
		return false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != p.str[i])
			return false;
	}
	return true;
}

TString& TString::operator=(TString& p)
{
	if (this == &p)
		return*this;
	delete[]str;
	len = p.len;
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = p.str[i];
	return*this;
}

bool TString::operator!=(TString& p)
{
	if (len != p.len)
		return true;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != p.str[i])
			return true;
	}
	return false;
}

bool TString::operator<(TString& p)
{
	if (len < p.len)
		return true;
	if (len > p.len)
		return false;
	if (len == p.len)
	{
		for (int i = 0; i < len - 1; i++)
		{
			if (str[i] < p.str[i])
				return true;
			if (str[i] > p.str[i])
				return false;
		}
	}
	return false;
}

bool TString::operator>(TString& p)
{
	if (len > p.len)
		return true;
	if (len < p.len)
		return false;
	if (len == p.len)
	{
		for (int i = 0; i < len - 1; i++)
		{
			if (str[i] > p.str[i])
				return true;
			if (str[i] < p.str[i])
				return false;
		}
	}
	return false;
}

int TString::Find(char* c)
{
	int k = 0, l = -1;
	for (int i = 0; i < len;)
	{
		for (int j = 0; j < strlen(c);)
		{
			if (str[i] == c[j])
			{
				k = j;
				i++;
				j++;
			}
			else
			{
				if (j != 0)
				{
					j = 0;
				}
				else
				{
					i++;
					if (i > len)
						break;
				}
			}
		}
		if (k == strlen(c) - 1)
		{
			l = i - strlen(c);
			break;
		}
	}
	return l;
}

int TString::Find(char c)
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int TString::split(char c)
{
	int r = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
			r++;
	}
	if (r == len - 1)
		r--;
	return r + 1;
}

TString* Split(char c, TString& p)
{
	int r = 0;
	r = p.split(c);

	TString* mas = new TString[r];
	int k = 0, start = 0;
	
	for (int i = 0; i < p.len-1; i++)
	{
		if (p.str[i] == c)
		{
			if (k == 0) 
			{
				mas[k].str = new char[i + 2];
				for (int a = 0; start < i + 1; start++, a++)
				{
					mas[k].str[a] = p.str[start];
				}
				mas[k].str[i + 1] = '\0';
			}
			else
			{
				mas[k].str = new char[i - start + 1];
				for (int a = 0, j = start + 1; j < i + 1; j++, a++)
				{
					mas[k].str[a] = p.str[j];
				}
				mas[k].str[i - start] = '\0';
			}
			start = i;
			k++;

			if (k == r - 1)
			{
				if (p.str[p.len - 2] != c)
				{
					mas[k].str = new char[p.len - i - 1];
					for (int j = i + 1, a = 0; j < p.len; j++, a++)
					{
						mas[k].str[a] = p.str[j];
					}
				}
			}
		}
	}
	return mas;
}

std::ostream& operator<<(std::ostream& B, TString& p)
{
	for (int i = 0; i < p.GetLen(); i++)
	{
		B << p.GetStr()[i];
	}
	B << std::endl;
	return B;
}

std::istream& operator>>(std::istream& B, TString& p)
{
	for (int i = 0; i < p.GetLen() - 1; i++)
	{
		B >> p.GetStr()[i];
	}
	return B;
}