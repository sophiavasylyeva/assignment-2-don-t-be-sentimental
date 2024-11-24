#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include "DSString.h"

class Validation{
public:
    Validation(const std::map<DSString, bool>&, char* filename, char* filename1, char* filename2);
    void tester(char* accuraryFile, char* resultsFile);
    double accuracyRate;
private:
    std::map<DSString, bool> mapForTweet;
    std::vector<DSString> wrongTweets; 
};