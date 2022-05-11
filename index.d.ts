/**
 * Generates a random string
 * @param length how long of a string to generate
 */
export declare function string(length: number, { chars } : { chars?: string }): number;

/**
 * Generates a random number
 * @param min min number
 * @param max max number
 */
export declare function number(min: number, max: number): string;

export declare enum CHARS {
    DEFAULT = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
    ALL = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&'()*+,-./:;<=>?@[]^_`{|}~/",

    NUMERIC = "0123456789",
    UPPERCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    LOWERCASE_LETTERS = "abcdefghijklmnopqrstuvwxyz",
    SPECIAL_CHARACTERS = "!#$%&'()*+,-./:;<=>?@[\] ^ _`{|}~/"
}