
def organizingContainers(container):
    n = len(container)

    # Total number of balls in each container (row sums)
    container_sums = [sum(row) for row in container]

    # Total number of each type of ball (column sums)
    type_sums = [sum(container[i][j] for i in range(n)) for j in range(n)]

    # Sort and compare the two lists
    if sorted(container_sums) == sorted(type_sums):
        return "Possible"
    else:
        return "Impossible"
