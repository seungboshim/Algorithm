const fs = require('fs');
// const path = require('path');
// const inputFile = path.join(__dirname, 'input.txt');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const dictionary = new Map();

const [N, M] = input[0].split(' ').map(Number);
for (let i=1; i<=N; i++) {
  const word = input[i].trim();
  if (word.length < M) continue;
  else {
    const freq = dictionary.get(word) || 0;
    dictionary.set(word, freq+1);
  }
}

const arr = [...dictionary].sort((a, b) => {
  if (a[1] === b[1]) {
    if (a[0].length === b[0].length) {
      if (a[0] < b[0]) {
        return -1;
      } else {
        return 1;
      }
    } else {
      return b[0].length - a[0].length;
    }
  } else {
    return b[1] - a[1];
  }
})

const result = arr.map((dict) => dict[0]).join('\n');
console.log(result);

