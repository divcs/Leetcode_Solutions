var lengthOfLastWord = function (s) {
  const words = s.trim().split(" ").reverse();
  const wordslen = words[0].length;
  return wordslen;
};
