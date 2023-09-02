"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Consumer1 = void 0;
var Consumer1 = /** @class */ (function () {
    function Consumer1(service) {
        this.service = service;
    }
    Consumer1.prototype.useService = function (data) {
        this.service.serviceOperation(data);
    };
    return Consumer1;
}());
exports.Consumer1 = Consumer1;
