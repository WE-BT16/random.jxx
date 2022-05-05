try {
    const { random } = require("./build/Release/random.node");
    module.exports = random;
} catch (error) {
    throw new Error("Failed to load module, try rebuilding." + "\n" + error);
}