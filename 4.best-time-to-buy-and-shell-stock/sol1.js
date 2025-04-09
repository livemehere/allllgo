/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let profit = 0;
  for (let i = 0; i < prices.length - 1; i++) {
    const cur = prices[i];
    for (let j = i + 1; j < prices.length; j++) {
      const next = prices[j];
      const diff = next - cur;
      if (diff <= 0) continue;
      profit = Math.max(profit, diff);
    }
  }

  return profit;
};
