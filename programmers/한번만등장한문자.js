function solution(s) {
  var answer = '';
  let obj = {};
  s.split('').sort().forEach((word) => {
    if (obj[word])
      obj[word]++;
    else
      obj[word] = 1;
  })
  for (const key in obj) {
    if (obj[key] === 1)
      answer += key;
  }
  return answer;
}