const { ALLOW_CHARS } = require("./chars");
const random = require("./randomjxx");

/**
 * Generate a random string
 * @param {number} length length of the string
 * @param {*} options options
 * @returns {string} generated random string
 */
function string(length, options = {}) {
    if (options.chars == null) options.chars = ALLOW_CHARS.DEFAULT;
    return random.string(length, options.chars);
}

module.exports.string = string;
