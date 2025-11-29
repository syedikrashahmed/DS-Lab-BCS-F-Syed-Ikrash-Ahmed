/*Question#2: You are building a plagiarism detection tool. Implement the Rabin-Karp algorithm to find whether a small snippet of text appears anywhere in a larger document. Return all positions where the snippet occurs. Assume you are using a simple hash function with a prime modulus of your choice. Example:
Input: Text = Data structures and algorithms are fun. Algorithms make tasks easier
Pattern = Algorithms
Output:[27, 41]
Extra Challenge: Demonstrate the effect of hash collisions by printing any false- positive hash matches that are discarded.*/
#include <iostream>
#include <string>
using namespace std;
#define charnum 256  

int* rabinKarpSearch(string text, string snippet, int prime, int &result) {
    int text_len = text.length();   
    int snippet_len = snippet.length(); 
    result = 0;
    
    if (snippet_len == 0 || snippet_len > text_len) {
        return nullptr;
    }
    
    int* temp = new int[text_len];
    int snippetHash = 0;  
    int windowHash = 0;   
    int hash_power = 1;

    for (int i = 0; i < snippet_len - 1; i++) {
        hash_power = (hash_power * charnum) % prime;
    }

    for (int i = 0; i < snippet_len; i++) {
        snippetHash = (charnum * snippetHash + snippet[i]) % prime;
        windowHash = (charnum * windowHash + text[i]) % prime;
    }

    for (int start_pos = 0; start_pos <= text_len - snippet_len; start_pos++) {
        if (snippetHash == windowHash) {
            bool exact_match = true;
            for (int j = 0; j < snippet_len; j++) {
                if (text[start_pos + j] != snippet[j]) {
                    exact_match = false;
                    break;
                }
            }
            if (exact_match) {
                temp[result] = start_pos;
                result++;
            }
        }

        if (start_pos < text_len - snippet_len) {
            windowHash = (charnum * (windowHash - text[start_pos] * hash_power) + text[start_pos + snippet_len]) % prime;
            if (windowHash < 0)
                windowHash = windowHash + prime;
        }
    }
    
    int* final = new int[result];
    for (int i = 0; i < result; i++) {
        final[i] = temp[i];
    }
    delete[] temp;
    
    return final;
}

int main() {
    string document = "Data structures and algorithms are fun. Algorithms make tasks easier";
    string snippet = "Algorithms";
    int prime = 101; 
    int result = 0;
    int* found_positions = rabinKarpSearch(document, snippet, prime, result);
    
    if (result == 0) {
        cout << "No occurrences found." << endl;
        return 0;
    }
    
    cout << "[";
    for (int i = 0; i < result; i++) {
        cout << found_positions[i];
        if (i < result - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    delete[] found_positions;
}
