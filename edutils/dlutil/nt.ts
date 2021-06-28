//https://stackoverflow.com/questions/61770240/is-there-any-way-to-convert-a-node-project-to-deno

import { createRequire } from "https://deno.land/std/node/module.ts";

const require = createRequire(import.meta.url);
// Loads native module polyfill.
const path = require("path");
// Visits node_modules.
const leftPad = require("left-pad");

console.log(leftPad('5', 5, '0'))