const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const lines = [];

rl.on('line', (line) => {
  lines.push(line);
}).on('close', () => {
  const N = parseInt(lines[0]);
  const people = lines[1].split(' ').map((input) => parseInt(input));

  const result = Array(N).fill(99);

  for (let i=0; i<N; i++) {
    const height = i+1;
    const pos = people[i];
    
    let tall = 0;
    for (let j=0; j<N; j++) {
      if (tall === pos && result[j] === 99) {
        result[j] = height;
        break;
      }
      if (result[j] > height) {
        tall++;
      }
    }
  }

  console.log(result.join(' '));
  process.exit();
});