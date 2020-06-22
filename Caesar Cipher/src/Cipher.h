#pragma once

#include <fstream>
#include <string>

class CaesarCipher {
private:
	std::string KEY = "";
	std::string input_file, encrypted_file, decrypted_file;
	const int key_length = 10;

public:
	// Takes the input and output file locations. An absolute path or a relative path
	// can be used. The output file path is optional. If it is not give, the output file path
	// is considered to be the same as the input file path
	CaesarCipher(const std::string& input_file, const std::string& output_file = "");

	// Generates a key and returns it. Also saves it internally for later use
	std::string keyGenerator();

	// Encrypts files based on the key given as argument. If no key is given, it uses
	// the key corresponding to the object. If no key was generated prior to calling this
	// function, it will throw an error.
	void encrypt(const std::string& key = "");

	// Decrypts a file based on the key given.
	// Throws error if no key or invalid key is given
	void decrypt(const std::string& key);
};