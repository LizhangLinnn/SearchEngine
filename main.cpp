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

// word -> document mapping
// China -> [ (0, [0, 3]), (1, [0, 5]), (2, [0]) ]
// Eastern -> [ (0, [2, 4]), (1, [4]) ]
// Easter -> []

// other word -> [documentId]

// time complexity (n*m) - n number of documents in the DB, average m number of characters in the doducment
// space complexity (m)
// brute force

// constraints:
// - strong match X
// - weak match Y

// 1. single word -> China:
// 2. double words -> China Eastern:
// 3. missing pending character -> China Easter: -> Easter && Eastern && East
// 4. typo of single character AND typo doesn't match any existing words in the index ->


vector<string> documents = {
        "China ashjdas Eastern China Eastern airline offers airliairline offers airline tickets & flights to over worldwide 1000 destinations in 177 countries. Book direct at China Eastern UK official site.",
        "China offers asdhsajdhj as Eastern China airline tickets & flights to over worldwide 1000 destinations in 177 countries. Book direct at China Eastern UK official site.",
        "China Eastern offers airliairline offers airline tickets & flights to over worldwide 1000 destinations in 177 countries. Book direct at China Eastern UK official site.",
        "China Southern Airlines UK, London, United Kingdom. 10K likes. Welcome to the official page of China Southern Airlines in United Kingdom"
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



