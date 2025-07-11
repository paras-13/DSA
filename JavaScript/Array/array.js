//! Array creation
const arr = [1, 2, 3, "Hello"];
console.log(arr);

//! Find length of array
console.log("\n" + "Length of array:");
let n = arr.length;
console.log(n);

//! Add an element at end
console.log("\n" + "Add an element at end:");
arr.push(4); // returns new length
console.log(arr);

//? with push we can add multiple element as well at end
console.log("\n" + "Adding multiple element at end:");
arr.push(5, 6, 7);
console.log(arr);

//! Add an item at front
console.log("\n" + "Add an element at front:");
arr.unshift(10); // returns new length
console.log(arr);

//? with unshift we can add multiple element at front
console.log("\n" + "Adding multiple element at front:");
arr.unshift(-2, -1, 0);
console.log(arr);

//! Remove an item from back
console.log("\n" + "Remove an element from back:");
arr.pop(); // returns removed element
console.log(arr);

//! Remove an item from front
console.log("\n" + "Remove an element from front:");
arr.shift(); // returns removed element
console.log(arr);

//! Traverse in array using value
for (let val of arr) console.log(val);

//! Traverse using index
for (let i = 0; i < arr.length; i++) {
  console.log(arr[i]);
}

//! Find index of an element
console.log("\n" + "Find index of an element: ");
console.log(arr.indexOf(2)); // returns index or -1

//! Check if array includes a value
console.log("\n" + "Check whether 'hello' is their in array or nor");
console.log(arr.includes("Hello")); // true/false

//! Slice: get a subarray (does not modify original)
console.log("\n" + "Slice and create a new array:");
const sliced = arr.slice(1, 3); // from index 1 to 2
console.log(sliced);

//! Splice: add/remove elements (modifies original)
console.log("\n" + "Remove from index 1 and insert new data: ");
arr.splice(1, 1, "new"); // remove 1 at index 1, insert "new"
console.log(arr);

//! Reverse array (modifies original)
console.log("\n" + "Reverse array:");
arr.reverse();
console.log(arr);

//! Sort array (modifies original)
console.log("\n" + "Sort array:");
arr.sort(); // sorts as strings by default
console.log(arr);

//! Map: create new array by applying function
console.log("\n" + "Creating a new array based on callback function:");
const mapped = arr.map((x) => (typeof x === "number" ? x * 2 : x));
console.log(mapped);

//! Filter: create new array with elements passing test
console.log(
  "\n" + "Filter array on the basis of conditions in callback function:"
);
const filtered = arr.filter((x) => typeof x === "number");
console.log(filtered);

//! Reduce: accumulate a single value from array
console.log(
  "\n" + "Get a computer value by applying some operations in array:"
);
const sum = arr.reduce(
  (acc, curr) => (typeof curr === "number" ? acc + curr : acc),
  0
);
console.log(sum);

//! Find: returns first element matching condition
console.log("\n" + "Find first element which can be matched -> return element");
const found = arr.find((x) => typeof x === "string");
console.log(found);

//! FindIndex: returns index of first matching element
console.log(
  "\n" + "Find index of first element which will be matched, else return -1"
);
const foundIdx = arr.findIndex((x) => typeof x === "string");
console.log(foundIdx);

//! forEach: execute function for each element
console.log("\n" + "forEach for JS array:");
arr.forEach((val, idx) => {
  console.log(`Index ${idx}: ${val}`);
});

//! Concat: merge arrays (does not modify original)
console.log("\nConcat two arrays: ");
const arr2 = [5, 6];
const merged = arr.concat(arr2);
console.log(merged);

//! Join: create string from array
console.log("\nCreate string from array using join:");
console.log(arr.join(", "));

//! Fill: fill array with static value
console.log("\nTo fill array with certain value");
const filled = new Array(5).fill(0);
console.log(filled);

// Learning material summary:
// - push/pop: add/remove from end
// - unshift/shift: add/remove from front
// - slice/splice: get/cut/insert subarrays
// - map/filter/reduce: functional programming
// - find/findIndex: search for elements
// - forEach: iterate with callback
// - concat/join: merge or stringify
// - fill/flat/copyWithin: advanced manipulation
// - sort/reverse: order elements
// - indexOf/includes: search for values
