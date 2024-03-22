def max_min(depth, node_index, maximizing_player, values, alpha, beta):
    if depth == 0:
        return values[node_index]

    if maximizing_player:
        best_value = -float("inf")
        for i in range(0, 2):
            child_value = max_min(
                depth - 1, 2 * node_index + i, False, values, alpha, beta
            )
            best_value = max(best_value, child_value)
            alpha = max(alpha, best_value)
            if beta <= alpha:
                break
        return best_value
    else:
        best_value = float("inf")
        for i in range(0, 2):
            child_value = max_min(
                depth - 1, 2 * node_index + i, True, values, alpha, beta
            )
            best_value = min(best_value, child_value)
            beta = min(beta, best_value)
            if beta <= alpha:
                break
        return best_value


# Example usage
values = [3, 5, 6, 9, 1, 2, 0, -1]
best_value = max_min(3, 0, True, values, -float("inf"), float("inf"))
print("Best value:", best_value)
