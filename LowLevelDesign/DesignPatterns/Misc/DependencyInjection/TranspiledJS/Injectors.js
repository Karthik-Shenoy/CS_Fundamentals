"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Service2Injector = exports.Service1Injector = void 0;
var Consumers_1 = require("./Consumers");
var Services_1 = require("./Services");
var Service1Injector = /** @class */ (function () {
    function Service1Injector() {
    }
    Service1Injector.prototype.getConsumer = function () {
        return new Consumers_1.Consumer1(new Services_1.Service1());
    };
    return Service1Injector;
}());
exports.Service1Injector = Service1Injector;
var Service2Injector = /** @class */ (function () {
    function Service2Injector() {
    }
    Service2Injector.prototype.getConsumer = function () {
        return new Consumers_1.Consumer1(new Services_1.Service2());
    };
    return Service2Injector;
}());
exports.Service2Injector = Service2Injector;
