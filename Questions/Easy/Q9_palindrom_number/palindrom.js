var isPalindrome = function (x) {
  const numToString = x.toString();
  const stringToNum = numToString.split("").reverse().join("");

  if (x === Number(stringToNum)) {
    return true;
  } else {
    return false;
  }
};

console.log(isPalindrome(121));
