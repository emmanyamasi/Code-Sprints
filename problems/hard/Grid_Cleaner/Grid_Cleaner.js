function gridCleaner(grid, column, row, n, dir = 0) {
    const directions = [
        [-1, 0], // 0 - North
        [0, 1],  // 1 - East
        [1, 0],  // 2 - South
        [0, -1]  // 3 - West
    ];

    for (let i = 0; i < n; i++) {
        // Expand grid if out of bounds
        if (row < 0) {
            grid.unshift(new Array(grid[0].length).fill(0));
            row = 0;
        } else if (row >= grid.length) {
            grid.push(new Array(grid[0].length).fill(0));
        }

        if (column < 0) {
            for (let r = 0; r < grid.length; r++) {
                grid[r].unshift(0);
            }
            column = 0;
        } else if (column >= grid[0].length) {
            for (let r = 0; r < grid.length; r++) {
                grid[r].push(0);
            }
        }

        const tile = grid[row][column];

        if (tile === 1) {
            dir = (dir + 1) % 4;     // Turn right
            grid[row][column] = 0;   // Mark dirty
        } else {
            dir = (dir + 3) % 4;     // Turn left
            grid[row][column] = 1;   // Mark clean
        }

        row += directions[dir][0];
        column += directions[dir][1];
    }

    return grid;
}

module.exports = gridCleaner;
