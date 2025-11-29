/*Question#4: You are developing a search feature for a large book database. Implement the KMP algorithm to search for a query string in the book's content. Return all positions where the query occurs. Example:
Input: Text = ababababc 
Pattern = abab
Output: [0, 2, 4]
Extra Challenge: Show the LPS (Longest Prefix Suffix) array used for the search.*/
#include <iostream>
#include <string>
using namespace std;

void buildLPSArray(const string &query, int* lps) {
    int queryLen = query.length();
    lps[0] = 0; 
    int prefixLen = 0;
    int currentPos = 1;

    while (currentPos < queryLen) {
        if (query[currentPos] == query[prefixLen]) {
            prefixLen++;
            lps[currentPos] = prefixLen;
            currentPos++;
        } 
        else {
            if (prefixLen != 0) {
                prefixLen = lps[prefixLen - 1]; 
            } 
            else {
                lps[currentPos] = 0;
                currentPos++;
            }
        }
    }
}

int* KMPSearch(const string &bookContent, const string &searchQuery, int &result) {
    int contentLen = bookContent.length();
    int queryLen = searchQuery.length();
    result = 0;
    
    int* temp = new int[contentLen];
    int* lps = new int[queryLen];
    buildLPSArray(searchQuery, lps);
    
    cout << "LPS array: [";
    for (int i = 0; i < queryLen; i++) {
        cout << lps[i];
        if (i < queryLen - 1) cout << " ";
    }
    cout << "]" << endl;

    int contentIndex = 0; 
    int queryIndex = 0; 
    while (contentIndex < contentLen) {
        if (searchQuery[queryIndex] == bookContent[contentIndex]) {
            contentIndex++; 
            queryIndex++;
        }

        if (queryIndex == queryLen) {
            temp[result] = contentIndex - queryIndex;
            result++;
            queryIndex = lps[queryIndex - 1]; 
        } 
        else if (contentIndex < contentLen && searchQuery[queryIndex] != bookContent[contentIndex]) {
            if (queryIndex != 0) {
                queryIndex = lps[queryIndex - 1]; 
            } 
            else {
                contentIndex++; 
            }
        }
    }
    
    int* final = new int[result];
    for (int i = 0; i < result; i++) {
        final[i] = temp[i];
    }
    
    delete[] temp;
    delete[] lps;
    
    return final;
}

int main() {
    string bookContent = "ababababc";
    string searchQuery = "abab";
    int result = 0;
    int* position = KMPSearch(bookContent, searchQuery, result);
    
    if (result == 0) {
        cout << "No occurrences found." << endl;
        delete[] position;
        return 0;
    }

    cout << "[";
    for (int i = 0; i < result; i++) {
        cout << position[i];
        if (i < result - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    delete[] position;
}
