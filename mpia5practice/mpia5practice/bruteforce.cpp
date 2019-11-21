#include "bruteforce.h"
#include "sha256.h"

std::vector<std::string> allPasswords;
void visit(std::string const& chars, size_t max_len, std::string const& cur) {
	if (cur.length() == max_len) {
		return;
	}
	else {
		for (auto c : chars) {
			std::string next = cur + c;

			allPasswords.push_back(next);
			visit(chars, max_len, next);
		}
	}
}

std::vector<std::string> all_words(const std::string &alphabet, int max_length) {
    // Return all possible different words that can be created with symbols from the alphabet.
    // Alphabet - string of symbols, symbols are not repeated.
    // Words length - from 1 up to max length included, i.e. in [1, max_length].
    // Order of words in the result isn't important.
    // Return empty array if there are no symbols in the alphabet or if max length is less then 1.

	allPasswords.clear();
	visit(alphabet, max_length, "");

    return allPasswords;
}

std::string bruteforce(const std::string &alphabet, int max_length, const std::string &password_hash) {
    // Try to crack password by brute force, using all possible passwords with given alphabet and max length.
    // Use sha256(string) function to compute password's hash and match it with given hash.
    // Return password for which hashes are matched.
    // Return empty string if password isn't found.

    for (const auto &password: all_words(alphabet, max_length)) {
        if (sha256(password) == password_hash) {
            return password;
        }
    }
    return "";
}
