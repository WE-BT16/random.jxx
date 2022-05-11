# random.jxx
Random number and string generator

## Install
- Check you have the build requirements installed
- `npm install --save random.jxx`

## Usage
```js
const random = require("random.jxx");
random.string(100); // random string with a length of 100
random.number(1, 100); // random number between 1 and 100

random.string(100, {
    chars: random.CHARS.ALL
}); // random string with a length of 100 with all all chars

// for `CHARS` options see index.d.ts
```

## Build Requirements
- python3
- make
- gcc
- node