
#include "Training.h"
//assign each word of tweet to 1 if positive and -1 if negative

Training::Training(char* filename){
   // char filename[] = "train_dataset_20k.csv";
    std::ifstream stream(filename);
    //stream.open(filename);
    char buffer[1000];

    stream.getline(buffer, 1000);
    while (!stream.eof()) {
        stream.getline(buffer, 1000, ','); //reads in sentiment
        if (buffer[0] != '4' && buffer[0] != '0') {
            break;
        }
        bool sentiment = buffer[0] == '4'; //positive is 4
        for (int i = 0; i < 4; i++) {
            stream.getline(buffer, 1000, ','); //reads in id
        }
        stream.getline(buffer, 1000);
        DSString tweet(buffer);
        WordSentiment(tweet, sentiment); //calls sentiment function for word analysis
    }
    stream.close();
    }

std::map<DSString,int>Training::Train() {
    return mapForWords; //universality of map across classes
}


void Training::WordSentiment(DSString tweet, bool sentiment){
    tweet = tweet.toLower();
    std::vector<DSString> wholeTweet = tweet.tokenizer();
    for(int i = 0; i < wholeTweet.size(); i++){
        if(mapForWords.find(wholeTweet[i]) == mapForWords.end()){
            if(sentiment){
                mapForWords[wholeTweet[i]] = 1; //word is positive
            }
            else    
                mapForWords[wholeTweet[i]] = -1; //word is negative
        }
        else{
            if(sentiment){
                mapForWords[wholeTweet[i]]++; //map populates
            }
            else    
                mapForWords[wholeTweet[i]]--;
        }
    }
        
}
