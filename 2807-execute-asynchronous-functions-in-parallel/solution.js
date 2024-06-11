/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    const resultPromise = new Promise((res, rej) => {
        const result = new Array(functions.length);
        let cnt = 0;

        functions.forEach((fn, index) => {
            try {
                fn().then((res) => {
                    result[index] = res;
                }).catch(e => {
                    rej(e);
                }).finally(() => {
                    cnt++;
                    if(cnt == functions.length) {
                        res(result);
                    }
                })
            } catch(e) {
                rej(e);
            } 
        })
        
    });

    return resultPromise;
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
