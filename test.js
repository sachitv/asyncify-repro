import module from "./build/asyncify_bigint.js"

const mymod = await module();

console.log(mymod.getBigInt());