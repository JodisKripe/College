def alphabeta(node, depth, alpha, beta, maximizingPlayer, values):
    if depth == 0 or node >= len(values):
        return values[node]
    if maximizingPlayer:
        maxEval = -float("inf")
        for child in [2 * node + i for i in range(2)]:
            eval = alphabeta(child, depth - 1, alpha, beta, False, values)
            maxEval = max(maxEval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break
        return maxEval
    else:
        minEval = float("inf")
    for child in [2 * node + i for i in range(2)]:
        eval = alphabeta(child, depth - 1, alpha, beta, True, values)
        minEval = min(minEval, eval)
        beta = min(beta, eval)
        if beta <= alpha:
            break
    return minEval


# Example usage:
values = [15, 2, 1, -8, -9, 16, 0, 4]
best_value = alphabeta(0, 3, -float("inf"), float("inf"), True, values)
print("Best value:", best_value)
