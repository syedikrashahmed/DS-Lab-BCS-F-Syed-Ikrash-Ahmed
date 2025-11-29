/*Question#1: You are developing a text editor. Implement a function that searches for Force algorithm to find and return the starting indices of the keyword in the all occurrences of a user-provided keyword in a large document. Use the Brute document. Example:
Input: Text = the quick brown fox jumps over the lazy dog
Pattern = the;
Output: [0, 31]
Extra Challenge: Count and return the total number of comparisons your algorithm makes.*/
#include <iostream>
#include <string>
using namespace std;

int* bruteForceSearch(string doc, string keyword, int &compare, int &result) {
    int doc_len = doc.length();
    int key_len = keyword.length();
    compare = 0;
    result = 0;
    
    int* temp_results = new int[doc_len];
    
    for (int pos = 0; pos <= doc_len - key_len; pos++) {
        int k = 0;
        while (k < key_len && doc[pos + k] == keyword[k]) {
            compare++;
            k++;
        }   
        
        if (k == key_len) { 
            compare++;
            temp_results[result] = pos;
            result++;
        }
    }
    
    int* final_results = new int[result];
    for (int x = 0; x < result; x++) {
        final_results[x] = temp_results[x];
    }
    delete[] temp_results;
    
    return final_results;
}

int main() {
    string document = "the quick brown fox jumps over the lazy dog";
    string keyword = "the";
    int comparisons = 0;
    int result_count = 0;
    
    int* positions = bruteForceSearch(document, keyword, comparisons, result_count);
    
    if (result_count == 0) {
        cout << "No occurrences found." << endl;
        cout << "Total comparisons: " << comparisons << endl;
        delete[] positions;
        return 0;
    }

    cout << "[";
    for (int i = 0; i < result_count; i++) {
        cout << positions[i];
        if (i < result_count - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    delete[] positions;
}
