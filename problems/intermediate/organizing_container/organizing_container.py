
def organizingContainers(container):
    # Calculate total balls in each container (row sums)
    container_sums = [sum(row) for row in container]
    
    type_sums = [sum(container[i][j] for i in range(n)) for j in range(n)]
    
    if sorted(container_sums) == sorted(type_sums):
        return "Possible"
    else:
    return "Impossible"
