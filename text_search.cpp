#include <cassert>
#include <cstdlib>
#include <iostream>
#ifdef _MSC_VER
#include <string>
#else
#include <cstring>
#endif

std::string lower(std::string word) {
    int length = word.length();
    std::string lc = "";

    for (int i = 0; i < length; i++) {
        lc += tolower(word[i]);
    }

    return lc;
}

static void test() {
    assert(lower("abcd").compare("abcd") == 0);
    assert(lower("abc").compare("abcd") == -1);
    assert(lower("abcd").compare("abc") == 1);
}

int main() {
    test();
    std::string paragraph;
    std::cout << "Please enter your paragraph: \n";
    std::getline(std::cin, paragraph);
    std::cout << "\nHello, your paragraph is:\n " << paragraph << "!\n";
    std::cout << "\nThe size of your paragraph = " << paragraph.size()
              << " characters. \n\n";

    if (paragraph.empty()) {
        std::cout << "\nThe paragraph is empty" << std::endl;
    } else {
        int ch = 0;
        while (true) {
            std::string word;
            std::cout << "Please enter the word you are searching for: ";
            std::getline(std::cin, word);
            std::cout << "Ignore case-sensitive? 1 = Yes, 0 = No" << std::endl;
            std::cin >> ch;
            if (ch == 1) {
                std::string lowerCase = lower(
                    paragraph);
                std::string lowerCaseWord =
                    lower(word);

                std::cout << "Hello, your word is " << word << "!\n";
                if (lowerCase.find(lowerCaseWord) == std::string::npos) {
                    std::cout << word << " does not exist in the sentence"
                              << std::endl;
                } else {
                    std::cout << "The word " << word
                              << " is now found at location "
                              << lowerCase.find(lowerCaseWord) << std::endl
                              << std::endl;
                }
            } else {
                std::cout << "Hello, your word is " << word << "!\n";
                if (paragraph.find(word) == std::string::npos) {
                    std::cout << word << " does not exist in the sentence"
                              << std::endl;
                } else {
                    std::cout << "The word " << word
                              << " is now found at location "
                              << paragraph.find(word) << std::endl
                              << std::endl;
                }
            }
            std::cout << "\nPress Ctrl + C to exit the program.\n\n";
            std::cin.get();
        }
    }
    return 0;
}
