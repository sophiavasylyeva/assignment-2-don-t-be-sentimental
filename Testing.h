#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include "DSString.h"

class Testing{
public:
    Testing(const std::map<DSString, int>&, char* filename1);
    void TweetTester(DSString, DSString);
    std::map<DSString,bool>Test();
private:
    std::map<DSString, int> mapForWords; 
    std::map<DSString, bool> mapForTweet;
};