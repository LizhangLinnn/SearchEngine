#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// return the sentences that matches your search query
// search query start with a single word
// then we will improve the search query with capability of search sentences
// after that we can further improve the search query with error corrections


// concept of pre-processing

// TODOs
// - optimise space complexity (image we have millions of documents to be indexed)
// - enable prefixed search: e.g. searching "fir" should return the document "I'm the first log"
// - enable searching by sentence:
//      e.g. searching "first log" should return the document "I'm the first log".
//      If there's no match, then return the most relevant results .
//      e.g. partial match of sentence - searching "I'm first log" should return the document "I'm the first log")
// - enable relevance ordering: e.g. if we search for
// - replace text document with json document, and enabling searching by json field

vector<string> documents = {
        "I'm the first log",
        "Here is the second log",
        "How are you doing?",
        "Hello Google"
};

unordered_map<string, vector<int>> termsToDocumentIdsMap = {};

string readWord(string document, int &index) {
    // removing prefixing empty spaces
    while (index < document.size() && document[index] == ' ') {
        index++;
    }

    string word = "";

    // reading word
    for (; index < document.size() && document[index] != ' '; index++) {
        word += document[index];
    }

    return word;
}

void indexing() {
    // iterate through the documents
    // for each document, read the word, and build the inverted index
    for (int i=0; i<documents.size(); i++) {
        for (int j=0; j<documents[i].size(); j++) {
            string word = readWord(documents[i], j);
            termsToDocumentIdsMap[word].push_back(i);
        }
    }
}


int main(int argc, char* argv[]) {

    string wordToSearch = argv[1];
    cout << wordToSearch << endl;

    // indexing - build the inverted index for terms
    indexing();

    // searching
    vector<int> matchedDocuments = termsToDocumentIdsMap[wordToSearch];
    if (!matchedDocuments.empty()) {
        cout << "Found matched documenst: ";
    }
    for (int id : matchedDocuments) {
        cout << id << " ";
    }


    return 0;
}



