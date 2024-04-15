#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string& str) {
    std::vector<std::string> words;
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ofstream rValue("wadaw.txt");// создание файла на кирилице и чтение
    rValue << "ab bc cd de e";
    rValue << "e ed dc cb ba vdsa gfh jghj";
    rValue.close();
    std::ifstream lValue("wadaw.txt");
    lValue.seekg(0, std::ios::beg);
    if (!lValue) {
        std::cerr << "Unable to open input file!" << std::endl;
        return 1;
    }
    
    std::vector<std::string> allWords;
    std::string line;

    while (getline(lValue, line)) 
    {
        std::vector<std::string> words = split(line);
        allWords.insert(allWords.end(), words.begin(), words.end());  
        std::cout << line << std::endl;  
    }
    
    std::sort(allWords.begin(), allWords.end());

    std::ofstream outputFile("output.txt");

    for (const std::string& word : allWords) 
        outputFile << word << std::endl;

    lValue.close();
    return 0;
}