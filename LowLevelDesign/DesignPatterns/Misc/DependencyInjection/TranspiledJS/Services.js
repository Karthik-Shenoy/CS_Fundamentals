"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Service2 = exports.Service1 = void 0;
var Service1 = /** @class */ (function () {
    function Service1() {
    }
    Service1.prototype.serviceOperation = function (data) {
        console.log("Service1 : processing the given data : ".concat(data));
    };
    return Service1;
}());
exports.Service1 = Service1;
var Service2 = /** @class */ (function () {
    function Service2() {
    }
    Service2.prototype.serviceOperation = function (data) {
        console.log("Service2 : processing the given data : ".concat(data));
    };
    return Service2;
}());
exports.Service2 = Service2;
