try {
    const random = require("../build/Release/random.node");
    module.exports = random;
} catch (error) {
    if (process.env["RANDOM_JXX_ALLOW_ATTEMPT_DEBUG_LOADING"] === "true") {
        try {
            const random_debug = require("./build/Debug/random.node");
            module.exports = random_debug;
        } catch (error) {
            throwFailed(error);
        }
    } else {
        throwFailed(error);
    }
}

function throwFailed(error) {
    throw new Error("Failed to load module, try rebuilding." + "\n" + error);
}
