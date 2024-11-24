#include "Testing.h"

//tests if whole tweet is positive or negative based on summation of word values (positive or negative)
//Frequency of words increases value (increase 1)

Testing::Testing(const std::map<DSString, int>& m, char* filename1){
    mapForWords = m;
    //char filename1[] = "train_dataset_10k.csv";
    std::ifstream stream(filename1);
    //stream.open(filename1);
    char buffer[1000];
    stream.getline(buffer, 1000); //reads in file, id column
    while (!stream.eof()) {
        stream.getline(buffer, 1000, ','); 
        DSString id = buffer;
        if (id.length() == 0) {
            break;
        }
        for (int i = 0; i < 3; i++) {
            stream.getline(buffer, 1000, ','); //reads in tweet, last column
        }
        stream.getline(buffer, 1000);
        DSString tweet(buffer);
        TweetTester(tweet, id); //calls tester for tweet
    }
    stream.close();
}

std::map<DSString,bool>Testing::Test() {
    return mapForTweet; //allows access of map across classes
}

void Testing::TweetTester(DSString tweet, DSString id){
    int count = 0;
    tweet = tweet.toLower(); //lowers all letters of tweet
    std::vector<DSString> wholeTweet = tweet.tokenizer(); //tokenizes tweet
    for(int i = 0; i < wholeTweet.size(); i++){
        if(mapForWords.find(wholeTweet[i]) != mapForWords.end()){
            if(mapForWords[wholeTweet[i]] > 0)
                count++; //if word positive, count increases
            else if(mapForWords[wholeTweet[i]] < 0)
                count--;
        }
    }
    mapForTweet[id] = (count > 0); //at the id, if count greater than 0, tweet is positive

}

