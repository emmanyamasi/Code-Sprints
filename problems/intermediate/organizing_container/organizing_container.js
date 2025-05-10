function organizingContainers(container) {
    const n = container.length;
    const containerSums = new Array(n).fill(0);
    const typeSums = new Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            containerSums[i] += container[i][j]; // total balls in container i
            typeSums[j] += container[i][j];      // total balls of type j
        }
    }

    containerSums.sort((a, b) => a - b);
    typeSums.sort((a, b) => a - b);

    for (let i = 0; i < n; i++) {
        if (containerSums[i] !== typeSums[i]) {
            return "Impossible";
        }
    }

    return "Possible";
}

module.exports = { organizingContainers };



