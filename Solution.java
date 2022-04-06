
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class Solution {

    private static final char[] GENE_LETTERS = new char[]{'A', 'C', 'G', 'T'};
    private static final int GENE_SIZE = 8;
    private static final int NOT_POSSIBLE = -1;

    public int minMutation(String start, String end, String[] bank) {

        Set<String> setGeneBank = new HashSet<>();
        for (String gene : bank) {
            setGeneBank.add(gene);
        }

        if (!setGeneBank.contains(end)) {
            return NOT_POSSIBLE;
        }

        Queue<char[]> queue = new LinkedList<>();
        queue.add(start.toCharArray());
        int numberOfMutations = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            while (size-- > 0) {
                char[] geneAsArray = queue.poll();
                if (String.valueOf(geneAsArray).equals(end)) {
                    return numberOfMutations;
                }

                for (int i = 0; i < GENE_SIZE; i++) {
                    for (int j = 0; j < GENE_LETTERS.length; j++) {

                        char storeCurrentLetter = geneAsArray[i];
                        geneAsArray[i] = GENE_LETTERS[j];
                        String geneToString = String.valueOf(geneAsArray);

                        if (setGeneBank.contains(geneToString)) {
                            setGeneBank.remove(geneToString);
                            queue.add(Arrays.copyOf(geneAsArray, GENE_SIZE));
                        }
                        geneAsArray[i] = storeCurrentLetter;
                    }
                }
            }
            numberOfMutations++;
        }
        return NOT_POSSIBLE;
    }
}
