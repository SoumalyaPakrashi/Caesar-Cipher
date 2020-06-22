#include <iostream>
#include <string>
#include "Cipher.h"

int main() {
	std::string input_file, output_file;
	std::string key;

	int choice;
	std::cout << "Do you want to encrypt a file or decrypt?\n";
	std::cout << "1. Encrypt \n2. Decrypt \nChoice (1 / 2) : ";
	std::cin >> choice;
	// This is to clear the input stream
	char temp = std::getchar();

	if (choice == 1) {
		std::cout << "\nEnter path to the source file which is to be encrypted : ";
		std::getline(std::cin, input_file);
		std::cout << "Enter path to the file in which encrypted contents will be stored (optional) : ";
		std::getline(std::cin, output_file);

		CaesarCipher cc(input_file, output_file);

		char key_choice;
		std::cout << "\nGenerate a Key before encryption? (If no, then you will have to provide a valid key!) (y / n) : ";
		std::cin >> key_choice;
		if (key_choice == 'y') {
			key = cc.keyGenerator();
			std::cout << "\nKey generated. Please save it for use during decryption.\n";
			std::cout << "Key = " << key << std::endl;
		}
		else if (key_choice == 'n') {
			std::cout << "Enter a Valid Key : ";
			std::cin >> key;
		}
		else {
			std::cout << "\nWrong Input!\n";
			return 0;
		}

		try {
			cc.encrypt(key);
		}
		catch (const char* error_message) {
			std::cout << "\n" << error_message << "\n";
			return 0;
		}
		std::cout << "\nFile successfully encrypted.\n";
	}

	else if (choice == 2) {
		std::cout << "\nEnter path to the file which is to be decrypted : ";
		std::getline(std::cin, input_file);
		std::cout << "Enter path where the decrypted file will be stored (optional) : ";
		std::getline(std::cin, output_file);

		std::cout << "\nEnter Key to decrypt : ";
		std::cin >> key;

		CaesarCipher cc(input_file, output_file);

		try {
			cc.decrypt(key);
		}
		catch (const char* error_message) {
			std::cout << "\n" << error_message << "\n";
			return 0;
		}

		std::cout << "\nFile successfully decrypted\n";
	}

	else
		std::cout << "\nWrong Choice!\n";

	std::cin.get();
	return 0;
}