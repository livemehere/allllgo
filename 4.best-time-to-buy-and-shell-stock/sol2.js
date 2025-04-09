/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let profit = 0;
  let minPrice = prices[0];
  for (let i = 1; i < prices.length; i++) {
    const cur = prices[i];
    profit = Math.max(profit, cur - minPrice);
    minPrice = Math.min(minPrice, cur);
  }

  return profit;
};
