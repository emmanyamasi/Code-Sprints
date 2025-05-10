
function getDiscount(p,d) {
        // write your code here
        let finalP = p - (p * d / 100);
        let roundP = finalP.toFixed(2);

        return roundP;

    return 0;
}
