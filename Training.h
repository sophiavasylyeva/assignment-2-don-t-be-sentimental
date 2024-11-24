#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include "DSString.h"

class Training{
public:
    Training(char* filename);
    void WordSentiment(DSString, bool);
    std::map<DSString,int>Train();
private:
    std::map<DSString, int> mapForWords;
};