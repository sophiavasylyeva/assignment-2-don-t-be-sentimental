#include "Validation.h"
#include <iomanip>

//compares id of sentiment of tweet (correct answer) to what testing determined (machine learning program) 
//(does id match sentiment of testing?)

Validation::Validation(const std::map<DSString, bool>& m, char* filename, char* filename1, char* filename2){
    mapForTweet = m;
    //char filename[] = "train_dataset_sentiment_10k.csv";
    std::ifstream stream(filename);
   // stream.open(filename);
    char buffer[1000];
    stream.getline(buffer, 1000);
    while(!stream.eof()){
        stream.getline(buffer, 1000, ',');
        if(buffer[0] != '4' && buffer[0] != '0'){
          break;
        }
        bool sentiment = (buffer[0] == '4'); //assigns sentiments 4 to positive
        stream.getline(buffer, 1000);
        DSString id(buffer);
        if (mapForTweet[id] != sentiment) {
          wrongTweets.push_back(id); //wrong tweet if sentiment is false, negative
      }
    }
    tester(filename2, filename1); 
    stream.close();
}


void Validation::tester(char* accuraryFile, char* resultsFile){
    std::ofstream accuracy(accuraryFile);
    accuracyRate = (double) (mapForTweet.size() - wrongTweets.size())/mapForTweet.size();
    accuracy << std::setprecision(3) << accuracyRate << std::endl;
    for(int i = 0; i < wrongTweets.size(); i++){
      if(mapForTweet[wrongTweets[i]] == true)
        accuracy << "4, 0, " << wrongTweets[i] << std::endl;
      else  
        accuracy << "0, 4, " << wrongTweets[i] << std::endl;
    }

  std::ofstream results(resultsFile);
  for(const auto& iterator: mapForTweet){
    //results << iterator.second << ", " << iterator.first << std::endl;

    if(iterator.second == 1)
      results << "4, " << iterator.first << std::endl;
    else  
      results << "0, " << iterator.first << std::endl;
    // for(int i = 0; i < mapForTweet.size(); i++)
    //   results << iterator.first << " " << iterator.second << std::endl;
  }

}
