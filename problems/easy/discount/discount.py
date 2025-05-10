
# p =original price
#  d = percentage discount

def getdiscountedPS(p,d):
    finalp = p - (p * d/100)
    return round(finalp, 2)
