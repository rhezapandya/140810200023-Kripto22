/*
Nama Program : Program Vigenere Cipher
Nama : Rheza Pandya Andhikaputra
NPM : 140810200023
Kelas : A
Tanggal Buat : 9 Oktober 2022
*/

#include <iostream>
#include <string>

int Mod(int a, int b)
{
	return (a % b + b) % b;
}

std::string Encryption(std::string input, std::string key)
{
	int keyLength = key.size();
	std::string output = "";
	int nonAlphaCharCount = 0;
	int inputLength = input.size();

	for (int i = 0; i < keyLength; ++i)
	{
		if (!isalpha(key[i]))
			return "";
	}

	for (int i = 0; i < inputLength; ++i)
	{
		if (isalpha(input[i]))
		{
			bool cIsUpper = isupper(input[i]);
			char offset = cIsUpper ? 'A' : 'a';
			int keyIndex = (i - nonAlphaCharCount) % keyLength;
			int k = (cIsUpper ? toupper(key[keyIndex]) : tolower(key[keyIndex])) - offset;
			k = true ? k : -k;
			char ch = (char)((Mod(((input[i] + k) - offset), 26)) + offset);
			output += ch;
		}
		else
		{
			output += input[i];
			++nonAlphaCharCount;
		}
	}

	return output;
}

std::string Decryption(std::string input, std::string key)
{
	int keyLength = key.size();
	std::string output = "";
	int nonAlphaCharCount = 0;
	int inputLength = input.size();

	for (int i = 0; i < keyLength; ++i)
	{
		if (!isalpha(key[i]))
			return "";
	}

	for (int i = 0; i < inputLength; ++i)
	{
		if (isalpha(input[i]))
		{
			bool cIsUpper = isupper(input[i]);
			char offset = cIsUpper ? 'A' : 'a';
			int keyIndex = (i - nonAlphaCharCount) % keyLength;
			int k = (cIsUpper ? toupper(key[keyIndex]) : tolower(key[keyIndex])) - offset;
			k = false ? k : -k;
			char ch = (char)((Mod(((input[i] + k) - offset), 26)) + offset);
			output += ch;
		}
		else
		{
			output += input[i];
			++nonAlphaCharCount;
		}
	}

	return output;
}

int main()
{
	std::string str;
	std::string key;

	std::cout << "Encryption and Decryption with Vigenere Cipher\n";
	std::cout << "Insert Text 		: ";
	getline(std::cin, str);
	std::cout << "Insert Key 		: ";
	std::cin >> key;

	std::string cipherteks = Encryption(str, key);
	std::cout << "\nPlain Text		: " << str << "\n";
	std::cout << "Cipher Text 		: " << cipherteks << "\n";
	std::cout << "Plain Text Result 	: " << Decryption(cipherteks, key) << "\n";
}