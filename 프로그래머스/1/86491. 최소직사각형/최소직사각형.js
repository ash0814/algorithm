function solution(sizes) {
    var answer = 0;
    let wlist = []
    let hlist = [];
    sizes.forEach((ele) => {
        let [w, h] = ele;
        if (w > h) {
            wlist.push(w);
            hlist.push(h);
        }
        else {
            wlist.push(h);
            hlist.push(w);
        }
    })
    answer = Math.max(...wlist) * Math.max(...hlist);
    
    return answer;
}