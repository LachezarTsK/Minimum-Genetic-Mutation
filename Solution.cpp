
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <array>
#include <vector>
using namespace std;

class Solution {
    
    inline static const array<char, 4> GENE_LETTERS{ 'A', 'C', 'G', 'T'};
    inline static const int GENE_SIZE = 8;
    inline static const int NOT_POSSIBLE = -1;

public:

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> setGeneBank;
        for (const auto& gene : bank) {
            setGeneBank.insert(gene);
        }

        //C++20: setGeneBank.contains(end) 
        if (setGeneBank.find(end) == setGeneBank.end()) {
            return NOT_POSSIBLE;
        }

        queue<string> queue;
        queue.push(start);
        int numberOfMutations = 0;

        while (!queue.empty()) {
            int size = queue.size();

            while (size-- > 0) {

                //since it is a reference to queue.front(), queue.pop() is at the bottom of the loop.
                string& gene = queue.front();
                if (gene == end) {
                    return numberOfMutations;
                }

                for (int i = 0; i < GENE_SIZE; i++) {
                    for (int j = 0; j < GENE_LETTERS.size(); j++) {

                        char storeCurrentLetter = gene[i];
                        gene[i] = GENE_LETTERS[j];

                        //C++20: !setGeneBank.contains(gene) 
                        if (setGeneBank.find(gene) != setGeneBank.end()) {
                            setGeneBank.erase(gene);
                            queue.push(gene);
                        }
                        gene[i] = storeCurrentLetter;
                    }
                }
                queue.pop();
            }
            numberOfMutations++;
        }
        return NOT_POSSIBLE;
    }
};
