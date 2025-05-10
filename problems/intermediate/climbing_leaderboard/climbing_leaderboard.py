
def climbingLeaderboard(ranked, player):
   
    unique_scores = sorted(set(ranked), reverse=True)
    result = []
    i = len(unique_scores) - 1

    for score in player:
        while i >= 0 and score >= unique_scores[i]:
            i -= 1
        result.append(i + 2)  

    return result

