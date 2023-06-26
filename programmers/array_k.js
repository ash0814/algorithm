function solution(array, commands) {
    var answer = [];
    let i;
    for (i = 0; i < commands.length; i++) {
        let cut = array.slice(commands[i][0] - 1, commands[i][1]);
        cut.sort((a, b) => a - b);
        answer[i] = cut[commands[i][2] - 1];
    }
    return answer;
}

console.log("answer : ", solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3], [2, 5, 3]]));
