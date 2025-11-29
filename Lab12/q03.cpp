/*Question#3: You are designing a DNA sequence analyzer. Implement the Boyer-Moore algorithm to efficiently find a short DNA motif (pattern) in a long DNA strand. Return all starting positions of the motif in the strand. Example:
Input: DNA = ACGTACGTGACG
Pattern = ACG
Output: [0, 4, 9]
Extra Challenge: Implement both the bad character and good suffix heuristics for optimal performance.*/

#include <iostream>
#include <string>
using namespace std;
#define alphabets 256

void createBadCharTable(string &motif, int* badCharTable) {
    int motiflen = motif.length();
    for (int i = 0; i < alphabets; i++)
        badCharTable[i] = -1; 
    for (int i = 0; i < motiflen; i++)
        badCharTable[(int)motif[i]] = i;
}

int* boyerMooreSearch(string &dnaSequence, string &dnaMotif, int &result) {
    int seqlen = dnaSequence.length();
    int motiflen = dnaMotif.length();
    result = 0;
    
    int* temp = new int[seqlen];
    int* badCharTable = new int[alphabets];
    createBadCharTable(dnaMotif, badCharTable);

    int shiftpos = 0; 
    while (shiftpos <= seqlen - motiflen) {
        int compare_pos = motiflen - 1;
        while (compare_pos >= 0 && dnaMotif[compare_pos] == dnaSequence[shiftpos + compare_pos]) {
            compare_pos--;
        }

        if (compare_pos < 0) {
            temp[result] = shiftpos;
            result++;
            shiftpos += (shiftpos + motiflen < seqlen) ? motiflen - badCharTable[dnaSequence[shiftpos + motiflen]] : 1;
        } 
        else {
            int skip_chars = max(1, compare_pos - badCharTable[dnaSequence[shiftpos + compare_pos]]);
            shiftpos += skip_chars;
        }
    }
    
    int* final_results = new int[result];
    for (int i = 0; i < result; i++) {
        final_results[i] = temp[i];
    }
    
    delete[] temp;
    delete[] badCharTable;
    
    return final_results;
}

int main() {
    string dna_strand = "ACGTACGTGACG";
    string motif = "ACG";
    int result = 0;
    
    int* positions = boyerMooreSearch(dna_strand, motif, result);
    
    if (result == 0) {
        cout << "No occurrences found." << endl;
        delete[] positions;
        return 0;
    }

    cout << "[";
    for (int i = 0; i < result; i++) {
        cout << positions[i];
        if (i < result - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    delete[] positions;
}
