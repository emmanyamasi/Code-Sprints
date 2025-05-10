package problems.intermediate.climbing_leaderboard;

import java.util.*;

public class ClimbingLeaderboard {
     List<Integer> uniqueRanks = new ArrayList<>();
        for (int score : ranked) {
            int lastScore = -1;

for (int score : ranked) {
    if (score != lastScore) {
        uniqueRanks.add(score);
        lastScore = score;
    }
        }
    
    public static List<Integer> climbingLeaderboard(List<Integer> ranked, List<Integer> player) {
        List<Integer> result = new ArrayList<>();
         List<Integer> result = new ArrayList<>();
        int index = uniqueRanks.size() - 1;

        for (int pScore : player) {
           
            while (index >= 0 && pScore >= uniqueRanks.get(index)) {
                index--;
            }
            result.add(index + 2); 
        }
        return result;
    }
}}
