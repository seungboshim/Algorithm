// 두 큐 합 같게 만들기

function sumQueue(queue) {
  let sum = 0;
  queue.forEach((elem) => {
    sum += elem;
  })
  return sum;
}

function solution(queue1, queue2) {
  var answer = 0;

  let sum1 = sumQueue(queue1);
  let sum2 = sumQueue(queue2);
  const totalSum = sum1+sum2;
  if (totalSum % 2 !== 0) {
    return -1;
  }

  const target = totalSum / 2;
  const combinedQueue = [...queue1, ...queue2]; // [1, 1, 1, 1],[1, 1, 7, 1]
  
  let left = 0;
  let right = queue1.length;
  let currSum = sum1; // 4
  let maxCount = queue1.length + queue2.length;
  
  while (answer <= maxCount*2) {
    if (currSum === target) {
      return answer;
    }
    if (currSum < target) {
      currSum += combinedQueue[right];
      right++;
    } else {
      currSum -= combinedQueue[left];
      left++;
    }
    answer++;
  }

  return -1;
}
