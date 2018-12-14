let (%=) = (value, factor) => 0 == (value mod factor);
let isLeapYear = (year) => year %= 100 ? year %= 400 : year %= 4;
